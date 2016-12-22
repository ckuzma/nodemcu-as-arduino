#pragma once

#include <JsonListener.h>
#include <JsonStreamingParser.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define CURRENT 0
#define TEMP 1

#define MAX_AGE_MILLIS 15000


class AdsbExchangeClient: public JsonListener {
  private:
    int counter = 0;
    String currentKey = "";
    String from[2] = {"", ""};
    String to[2] = {"", ""};
    String altitude[2] = {"", ""};
    double distance[2] = {0.0, 0.0};
    double currentMinDistance = 1000.0;
    String aircraftType[2] = {"", ""};
    String operatorCode[2] = {"", ""};
    double heading[2] = {0.0, 0.0};
    long lastSightingMillis = 0;

  public:
    AdsbExchangeClient();

    void updateVisibleAircraft(String searchQuery);

    String getFrom();
    String getFromIcao();
    String getTo();
    String getToIcao();
    String getAltitude();
    double getDistance();
    String getAircraftType();
    String getOperatorCode();
    double getHeading();
    int getNumberOfVisibleAircrafts();
    boolean isAircraftVisible();

    virtual void whitespace(char c);

    virtual void startDocument();

    virtual void key(String key);

    virtual void value(String value);

    virtual void endArray();

    virtual void endObject();

    virtual void endDocument();

    virtual void startArray();

    virtual void startObject();
};
