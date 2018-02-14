
/*
  Test.cpp - Library defining project structure
  File with actual algorithms and functions
*/

#include "Arduino.h"
#include "Test.h"

Test::Test(int pin) {
	_pin = pin;
  	Test::setOutputPin(pin); 
}

void Test::setOutputPin(int pin) {
  	pinMode(pin, OUTPUT);
}

void Test::getPin() {
  	Serial.println("Library configured with Pin #"+_pin);
}

void Test::sayHello() {
  	Serial.println("Hello World");
}