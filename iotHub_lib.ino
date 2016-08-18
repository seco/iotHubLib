#include "iotHub_lib.hpp"

iotHubLib iothub("callum-desktop",3000);

void setup() {
  // add sensors

  uint temp_sensor_1 = iothub.RegisterSensor("Temperature Sensor 1");
  uint temp_sensor_2 = iothub.RegisterSensor("Temperature Sensor 2");

}

void loop() {}
