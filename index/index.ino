#include <SoftwareSerial.h>
#include <Test.h>

Test testInstance(5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  testInstance.sayHello();
  delay(2000);
}
