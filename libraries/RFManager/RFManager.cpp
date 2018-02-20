
/*
  RFManager.cpp - Library defining project structure
  File with actual algorithms and functions
*/

#include "HardwareSerial.h"
#include "Arduino.h"
#include "RF24.h"
#include "RFManager.h"

RFManager::RFManager(RF24& radio, HardwareSerial &print) {
    _newData = false;
    _print = &print;
    _print->begin(9600);
   	_radio = radio;
  	_radio.begin();
  	_radio.setDataRate( RF24_250KBPS );
}

void RFManager::setListener() {
	_radio.openReadingPipe(1,_slaveAddress);
  	_radio.startListening();
}

void RFManager::setWriter() {
	_radio.setRetries(3,5); // delay, count
 	_radio.openWritingPipe(_slaveAddress); //Abrir canal para escribir
}

void RFManager::sendData() {
	bool rslt = false;
    _print->println("=> Sending Data...");
    
    _rslt = _radio.write(&_dataToSend,sizeof(_dataToSend)); //Envia la data del array
    
    _print->print("=> Data Sent");
    _print->print(_dataToSend);
    if (rslt) { //Si la informacion se envio y fue recibida
        _print->println("  Ack received.");
        RFManager::updateMessage(); //Actualiza el mensaje con contador txNum
    } else {
        _print->println("  Tx failed!");
    }
}

void RFManager::updateMessage() {
    // Verificar si se esta enviando nueva informacion
    _txNum += 1;
    if (_txNum > '9') {
        _txNum = '0';
    }
    _dataToSend[8] = _txNum;
}

void RFManager::getData() {
  	if ( _radio.available() ) { //Si el canal esta disponible
        _print->println("=> Radio receiving..."); 
        _radio.read( &_dataReceived, sizeof(_dataReceived) ); //Lee la data y la guarda en el array
        _newData = true; // Setear variable de recibido de la informacion
    }
}

void RFManager::showData() {
  	if (_newData == true) { //Si la informacion se recibio
        _print->print("Data received: ");
        _print->println(_dataReceived); //Imprime lo que se encuentra en el array
        _newData = false; //Despues de mostrar la informacion cambiamos la variable de recepcion de datos a falso
    }
}

