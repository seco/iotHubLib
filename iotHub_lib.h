#include "ArduinoJson.h"
#include <ESP8266WiFi.h>

class iotHubLib {
private:
  char iothub_server[] = ""; // the location of the server
  int iothub_port= 80;

  WiFiClient client;
  int tick_time = 10000; // default of 10 seconds
  long sensor_ids[]; // array of sensor ID's

  void Connect() {
    Serial.print("Attempting to connect to server\n");
    if (client.connect(iothub_server, iothub_port) ) {
      Serial.println("connected to server");
    }
  }

  // this should read sensor ID's from internal memory if available
  void LoadSensors() {

  }

  // this should save sensor ID's TO internal memory
  void SaveSensors() {

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

  // this should post to /api/sensors with the requested sensor, this will then return an ID that can be used
  void RegisterSensor() {
    
  }
}
