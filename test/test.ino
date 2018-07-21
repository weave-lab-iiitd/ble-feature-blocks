#include "WStream.h"
#define Stream WStream
#include <SPI.h>
#include <BLEPeripheral.h>

BLEPeripheral blep;
BLEService bless = BLEService("CCC0");
BLEIntCharacteristic test_char("CCC1", BLERead | BLENotify);

#define LED 13
int ledState = LOW;
unsigned long prev = 0;
unsigned long prev2 = 0;
unsigned long cnt = 3000000;

void setup() {
  pinMode(LED, OUTPUT);  
  blep.setLocalName("TEST3");
  blep.setDeviceName("TEST3");
  blep.setAdvertisedServiceUuid(bless.uuid());
  blep.addAttribute(bless);
  blep.addAttribute(test_char);
  blep.begin();
}

void loop() {
  if (millis() - prev > 1000) {
    prev = millis();
    ledState = ~ledState;
    digitalWrite(LED, ledState);
  }
  blep.poll();
  
  if (millis() - prev2 > 50) {
    prev2 = millis();
    test_char.setValue(cnt++);
  }
}
