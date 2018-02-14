/*
  Test.h - Library defining project structure
  Header file (it defines the class structure)
*/
#ifndef Test_h
#define Test_h

#include "SoftwareSerial.h"
#include "Arduino.h"

class Test
{
  public:
    Test(int pin);
    void setOutputPin(int pin);
    void getPin();
    void sayHello();
  private:
    int _pin;
    //Serial _serialInstance;
};

#endif