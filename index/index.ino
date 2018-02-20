#include <SoftwareSerial.h>
#include <Test.h>
#include <RF24.h>
#include <RFManager.h>


#define CE_PIN 22
#define CSN_PIN 23

Test testInstance(5);


void setup() {
  Serial.begin(9600);
  RF24 _radio(CE_PIN, CSN_PIN);
  RFManager rfManagerInstance(_radio);
}

void loop() {
  testInstance.sayHello();
  delay(2000);
}
