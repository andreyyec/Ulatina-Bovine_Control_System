/*
  RFManager.h - Library controlling RF Communications for the bovine necklace
  Header file (it defines the class structure)
*/
#ifndef RFManager_h
#define RFManager_h

#include "HardwareSerial.h"
#include "Arduino.h"
//#include "RF24.h"

class RFManager {
  public:
    RFManager(RF24& radio, HardwareSerial& print);
    void setWriter();
    void setListener();
    void sendData();
    void getData();
    void showData();
    void updateMessage();
  private:
    const byte _slaveAddress[5] = {'R','x','A','A','A'};
    char _dataReceived[11];
    char _dataToSend[11];
    bool _newData;
    bool _rslt;
    char _txNum = 1; 
    RF24& _radio;
    HardwareSerial* _print;
};

#endif