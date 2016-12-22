#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <WiFiUdp.h>
#include <functional>

// Declare function prototypes
bool connectUDP();
void prepareIds();
void respondToSearch();
void startHttpServer();

// Change these to whatever you'd prefer:
String device_name = "christmas lights";  // Name of device
int relayPin = D1;                        // Pin to toggle
bool debug = false;                       // If you want debug messages
bool squawk = true;                       // For on/off messages

// Some UDP / WeMo specific variables:
WiFiUDP UDP;
IPAddress ipMulti(239, 255, 255, 250);
unsigned int portMulti = 1900; // local port to listen on
ESP8266WebServer HTTP(80);
String serial; // Where we save the string of the UUID
String persistent_uuid; // Where we save some socket info with the UUID

// Buffer to save incoming packets:
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

void setup() {
  // Begin Serial:
  Serial.begin(115200);

  // Setup the pin for output:
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Start with light on
//  digitalWrite(relayPin, LOW); // Start with light off

  // Set the UUIDs and socket information:
  prepareIds();

  // Get settings from WiFi Manager:
  WiFiManager wifiManager;
  // wifiManager.resetSettings(); // Uncomment this to test WiFi Manager function
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.autoConnect();

  // Wait til WiFi is connected properly:
  int counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    counter++;
  }
  Serial.println("Connected to WiFi");

  // Connect to UDP:
  bool udpConnected = connectUDP();
  if (udpConnected){
    startHttpServer(); // Start the HTTP Server
  }

}

void loop() {
  HTTP.handleClient();
  delay(1);

  // If there are packets, we parse them:
  int packetSize = UDP.parsePacket();

  if(packetSize) {
    if (debug) {
      Serial.println("");
      Serial.print("Received packet of size ");
      Serial.println(packetSize);
      Serial.print("From ");
      IPAddress remote = UDP.remoteIP();

      for (int i =0; i < 4; i++) {
        Serial.print(remote[i], DEC);
        if (i < 3) {
          Serial.print(".");
        }
      }

      Serial.print(", port ");
      Serial.println(UDP.remotePort());
    }

    int len = UDP.read(packetBuffer, 255);

    if (len > 0) {
      packetBuffer[len] = 0;
    }

    String request = packetBuffer;

    if(request.indexOf('M-SEARCH') > 0) {
      if(request.indexOf("urn:Belkin:device:**") > 0) {
        if (debug) {
          Serial.println("Responding to search request ...");
        }
        respondToSearch();
      }
    }
  }

  delay(10);
}

void prepareIds() {
  uint32_t chipId = ESP.getChipId();
  char uuid[64];
  sprintf_P(uuid, PSTR("38323636-4558-4dda-9188-cda0e6%02x%02x%02x"),
  (uint16_t) ((chipId >> 16) & 0xff),
  (uint16_t) ((chipId >>  8) & 0xff),
  (uint16_t)   chipId        & 0xff);

  serial = String(uuid);
  persistent_uuid = "Socket-1_0-" + serial;
}

bool connectUDP(){
  boolean state = false;
  Serial.println("Connecting to UDP");

  if(UDP.beginMulticast(WiFi.localIP(), ipMulti, portMulti)) {
    Serial.println("Connection successful");
    state = true;
  }
  else{
    Serial.println("Connection failed");
  }

  return state;
}

void startHttpServer() {
  HTTP.on("/index.html", HTTP_GET, [](){
    if (debug) {
      Serial.println("Got Request index.html ...\n");
    }
    HTTP.send(200, "text/plain", "Hello World!");
  });

  HTTP.on("/upnp/control/basicevent1", HTTP_POST, []() {
    if (debug) {
    Serial.println("########## Responding to  /upnp/control/basicevent1 ... ##########");
    }


    //for (int x=0; x <= HTTP.args(); x++) {
    //  Serial.println(HTTP.arg(x));
    //}

    String request = HTTP.arg(0);
    if (debug) {
      Serial.print("request:");
      Serial.println(request);
    }


    if(request.indexOf("<BinaryState>1</BinaryState>") > 0) {
      if (squawk) {
          Serial.println("Got on request");
      }

      digitalWrite(relayPin, HIGH); // turn on relay with voltage HIGH
    }

    if(request.indexOf("<BinaryState>0</BinaryState>") > 0) {
      if (squawk) {
          Serial.println("Got off request");
      }

      digitalWrite(relayPin, LOW); // turn on relay with voltage LOW
    }

    HTTP.send(200, "text/plain", "");
  });

  HTTP.on("/eventservice.xml", HTTP_GET, [](){
    if (debug) {
        Serial.println(" ########## Responding to eventservice.xml ... ########\n");
    }

    String eventservice_xml = "<?scpd xmlns=\"urn:Belkin:service-1-0\"?>"
    "<actionList>"
    "<action>"
    "<name>SetBinaryState</name>"
    "<argumentList>"
    "<argument>"
    "<retval/>"
    "<name>BinaryState</name>"
    "<relatedStateVariable>BinaryState</relatedStateVariable>"
    "<direction>in</direction>"
    "</argument>"
    "</argumentList>"
    "<serviceStateTable>"
    "<stateVariable sendEvents=\"yes\">"
    "<name>BinaryState</name>"
    "<dataType>Boolean</dataType>"
    "<defaultValue>0</defaultValue>"
    "</stateVariable>"
    "<stateVariable sendEvents=\"yes\">"
    "<name>level</name>"
    "<dataType>string</dataType>"
    "<defaultValue>0</defaultValue>"
    "</stateVariable>"
    "</serviceStateTable>"
    "</action>"
    "</scpd>\r\n"
    "\r\n";

    HTTP.send(200, "text/plain", eventservice_xml.c_str());
  });

  HTTP.on("/setup.xml", HTTP_GET, [](){
    if (debug) {
        Serial.println(" ########## Responding to setup.xml ... ########\n");
    }


    IPAddress localIP = WiFi.localIP();
    char s[16];
    sprintf(s, "%d.%d.%d.%d", localIP[0], localIP[1], localIP[2], localIP[3]);

    String setup_xml = "<?xml version=\"1.0\"?>"
    "<root>"
    "<device>"
    "<deviceType>urn:Belkin:device:controllee:1</deviceType>"
    "<friendlyName>"+ device_name +"</friendlyName>"
    "<manufacturer>Belkin International Inc.</manufacturer>"
    "<modelName>Emulated Socket</modelName>"
    "<modelNumber>3.1415</modelNumber>"
    "<UDN>uuid:"+ persistent_uuid +"</UDN>"
    "<serialNumber>221517K0101769</serialNumber>"
    "<binaryState>0</binaryState>"
    "<serviceList>"
    "<service>"
    "<serviceType>urn:Belkin:service:basicevent:1</serviceType>"
    "<serviceId>urn:Belkin:serviceId:basicevent1</serviceId>"
    "<controlURL>/upnp/control/basicevent1</controlURL>"
    "<eventSubURL>/upnp/event/basicevent1</eventSubURL>"
    "<SCPDURL>/eventservice.xml</SCPDURL>"
    "</service>"
    "</serviceList>"
    "</device>"
    "</root>\r\n"
    "\r\n";

    HTTP.send(200, "text/xml", setup_xml.c_str());
    if (debug) {
      Serial.print("Sending :");
      Serial.println(setup_xml);
    }
  });

  HTTP.begin();
  if (debug) {
    Serial.println("HTTP Server started ..");
  }
}

void respondToSearch() {
  if (debug) {
    Serial.println("");
    Serial.print("Sending response to ");
    Serial.println(UDP.remoteIP());
    Serial.print("Port : ");
    Serial.println(UDP.remotePort());
  }

  IPAddress localIP = WiFi.localIP();
  char s[16];
  sprintf(s, "%d.%d.%d.%d", localIP[0], localIP[1], localIP[2], localIP[3]);

  String response =
  "HTTP/1.1 200 OK\r\n"
  "CACHE-CONTROL: max-age=86400\r\n"
  "DATE: Tue, 14 Dec 2016 02:30:00 GMT\r\n"
  "EXT:\r\n"
  "LOCATION: http://" + String(s) + ":80/setup.xml\r\n"
  "OPT: \"http://schemas.upnp.org/upnp/1/0/\"; ns=01\r\n"
  "01-NLS: b9200ebb-736d-4b93-bf03-835149d13983\r\n"
  "SERVER: Unspecified, UPnP/1.0, Unspecified\r\n"
  "ST: urn:Belkin:device:**\r\n"
  "USN: uuid:" + persistent_uuid + "::urn:Belkin:device:**\r\n"
  "X-User-Agent: redsonic\r\n\r\n";

  UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
  UDP.write(response.c_str());
  UDP.endPacket();
  if (debug) {
    Serial.println("Response sent !");
  }
}

void configModeCallback(WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println("Soft AP's IP Address:");
  Serial.println(WiFi.softAPIP());
  Serial.println("WiFi Manager: Please connect to AP:");
  Serial.println(myWiFiManager->getConfigPortalSSID());
  Serial.println("To setup WiFi Configuration");
}
