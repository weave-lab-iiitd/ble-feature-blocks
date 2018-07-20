//#include "WStream.h"
//#define Stream WStream
//#include <SPI.h>
//#include <BLEPeripheral.h>
//
//BLEPeripheral blep;
//BLEService bless = BLEService("CCC0");
//BLEIntCharacteristic sensor_char("CCC1", BLERead | BLENotify);
//
//#define LED 13
//int ledState = LOW;
//unsigned long prev = 0;
//unsigned long prev2 = 0;
//
//#define outputA 0
//#define outputB 1
//int counter = 0;
//int aState;
//int aLastState;
//
//void setup() {
//  pinMode(LED, OUTPUT);  
//  blep.setLocalName("BLEP");
//  blep.setDeviceName("BLEP");
//  blep.setAdvertisedServiceUuid(bless.uuid());
//  blep.addAttribute(bless);
//  blep.addAttribute(sensor_char);
//  blep.begin();
//
//  pinMode (outputA, INPUT);
//  pinMode (outputB, INPUT);
//  aLastState = digitalRead(outputA);
//}
//
//void loop() {
//  if (millis() - prev > 1000) {
//    prev = millis();
//    ledState = ~ledState;
//    digitalWrite(LED, ledState);
//  }
//  blep.poll();
//  aState = digitalRead(outputA);
//  if (aState != aLastState) {
//    if (digitalRead(outputB) != aState) {
//      counter++;
//    }
//    else {
//      counter--;
//    }
//  }
//  aLastState = aState;
//  
//  if (millis() - prev2 > 50) {
//    prev2 = millis();
//    sensor_char.setValue(counter);
//  }
//  
//}
