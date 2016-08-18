#include "ArduinoJson.h"
#include <ESP8266WiFi.h>

template<uint array_size> class iotHubLib {
private:
  char* iothub_server; // the location of the server
  int iothub_port= 80;
  bool sensor_configs_loaded = false;

  WiFiClient client;

  int tick_time = 10000; // default of 10 seconds
  char sensor_ids[array_size][25]; // array of sensor ID's, sensor ids are 25 alphanumeric keys long
  //char* sensor_ids[][25]; // array of sensor ID's, sensor ids are 25 alphanumeric keys long

  void Connect() {
    Serial.print("Attempting to connect to server\n");
    if (client.connect(iothub_server, 80) ) {
      Serial.println("connected to server");
    }
  };

  // this should read sensor ID's from internal memory if available, else ask for new ids from the given server
  void LoadSensors() {
  };

  // this should save sensor ID's TO internal memory
  void SaveSensors() {
  };

  void RegisterSensor(char* sensor_name, char sensor_id[25] ) {
    Serial.println("Registering sensor");
    // Make a HTTP post
    client.println("POST /api/sensors");

    // prep the json object
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& json_obj = jsonBuffer.createObject();
    json_obj["name"] = sensor_name;

    client.println(" HTTP/1.1");
    client.print("Host: "); client.println(iothub_server);
    client.println("Content-Type: application/json"); // important! JSON conversion in nodejs requires this

    // send length of the json to come
    client.print("Content-Length: "); client.println(json_obj.measureLength());
    client.println();

    // send the json
    json_obj.printTo(client);// this is great except it seems to be adding quotation marks around what it is sending
  }

public:
  // constructor cannot contain parameters?
  iotHubLib(char* server, int port) {
    iothub_server = server;
    iothub_port = port;
    Serial.begin(115200);
    Connect();
    LoadSensors();
  };
  // destructor
  ~iotHubLib() {
  };

  void StartConfig() {};

  void Send(uint sensor_index,float sensor_value) {
      // Make a HTTP post
      client.print("POST /api/sensors/"); client.print(sensor_ids[sensor_index]); client.println("/data");

      // prep the json object
      StaticJsonBuffer<50> jsonBuffer;
      JsonObject& json_obj = jsonBuffer.createObject();
      json_obj["value"] = sensor_value;

      client.println(" HTTP/1.1");
      client.print("Host: "); client.println(iothub_server);
      client.println("Content-Type: application/json"); // important! JSON conversion in nodejs requires this

      // send length of the json to come
      client.print("Content-Length: "); client.println(json_obj.measureLength());
      client.println();

      // send the json
      json_obj.printTo(client);// this is great except it seems to be adding quotation marks around what it is sending
  };

  // this should post to /api/sensors with the requested sensor, this will then return an ID that can be used
void RegisterSensors(char* sensor_names[]) {
    if (!sensor_configs_loaded) {

      for(uint i=0; i < array_size;i++ ) {
         RegisterSensor(sensor_names[i],sensor_ids[i]);
      }

    } else {
      Serial.println("Sensor already registered");
    }
  };

};
