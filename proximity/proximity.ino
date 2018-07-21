#include "WStream.h"
#define Stream WStream
#include <Wire.h>
#include <VL6180X.h>
#include <SPI.h>
#include <BLEPeripheral.h>

BLEPeripheral blep;
BLEService bless = BLEService("CCC0");
BLEIntCharacteristic sensor_char("CCC1", BLERead | BLENotify);

VL6180X sensor;

void setup() { 
  Wire.begin();

  blep.setLocalName("BLEP");
  blep.setDeviceName("BLEP");
  blep.setAdvertisedServiceUuid(bless.uuid());
  blep.addAttribute(bless);
  blep.addAttribute(sensor_char);
  blep.begin();

  sensor.init();
  sensor.configureDefault();
  sensor_char.setValue(0);
}

void loop() {
  blep.poll();
  int dist = sensor.readRangeSingleMillimeters();
  sensor_char.setValue(dist);
}
