/*
  RFManager.h - Library controlling RF Communications for the bovine necklace
  Header file (it defines the class structure)
*/
#ifndef RFManager_h
#define RFManager_h

#include "String.h"
#include "Arduino.h"
#include "RF24.h"

class RFManager {
  public:
    RFManager(RF24& radio);
    void setUp();
    void setWriter();
    void setListener();
    void sendData(char* message);
    void getData();
    void showData();
    void updateMessage();
    //char* _dataToSend[11] = {'R','x','A','A','A','R','x','A','A','A','A'};
  private:
    const byte _slaveAddress[5] = {'R','x','A','A','A'};
    bool _newData;
    bool _rslt = false;
    char* _txNum = 1; 
    char _dataReceived[11];
    char _dataToSend[11];
    RF24* _radio;
};

#endif