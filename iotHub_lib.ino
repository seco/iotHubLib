#include "iotHub_lib.hpp"

iotHubLib iothub("callum-desktop",3000);

void setup() {
  // add sensors
  iothub.RegisterSensors(["Temperature Sensor 1","Temperature Sensor 2"],2);
}

void loop() {
  // iothub.SetValue(0,10.1)
  // iothub.SetValue(1,11.12)
  iothub.Update
}
