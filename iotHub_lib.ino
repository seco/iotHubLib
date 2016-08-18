#include "iotHub_lib.hpp"


iotHubLib<2> iothub("callum-desktop",3000);


void setup() {
  // add sensors
  char *names[] = {"Temperature Sensor 1","Temperature Sensor 2"};
  iothub.RegisterSensors(names);
}

void loop() {
  // iothub.SetValue(0,10.1)
  // iothub.SetValue(1,11.12)
}
