#include "ArduinoJson.h"
#include <ESP8266WiFi.h>

class iotHubLib {
private:
  char iothub_server[] = ""; // the location of the server including port of the server if not the standard 80
  WiFiClient client;
  int tick_time = 10000; // default of 10 seconds
  long sensorId;

  void Connect() {
    Serial.print("Attempting to connect to server\n");
    if (client.connect(server, 80) ) {
      Serial.println("connected to server");
    }
  }

public:
  iotHubLib(char[] server) {
    iothub_server = server;
    Connect();
  }

  void StartConfig() {}

  void Send(sensor_value) {
      // Make a HTTP post
      client.println("POST /api/sensors/"+ sensorId +"/data");

      // prep the json object
      StaticJsonBuffer<50> jsonBuffer;
      JsonObject& root = jsonBuffer.createObject();
        root["value"] = sensor_value

      client.println(" HTTP/1.1");
      client.print("Host: "); client.println(iothub_server);
      client.println("Content-Type: application/json"); // important! JSON conversion in nodejs requires this

      // send length of the json to come
      client.print("Content-Length: "); client.println(PostData.length());
      client.println();

      // send the json
      root.printTo(client);// this is great except it seems to be adding quotation marks around what it is sending
  }
}
