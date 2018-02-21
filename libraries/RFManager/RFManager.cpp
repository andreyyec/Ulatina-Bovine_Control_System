
/*
  RFManager.cpp - Library defining project structure
  File with actual algorithms and functions
*/

#include "Arduino.h"
#include "RF24.h"
#include "RFManager.h"

RFManager::RFManager(RF24 &radio) {
    _newData = false;
   	_radio = &radio;
}

void RFManager::setUp() {
	_radio->begin();
	_radio->setDataRate( RF24_250KBPS );
 	_radio->setRetries(3,5); // delay, count
}

void RFManager::setListener() {
	Serial.println("=> Setting Listener...");
	_radio->openReadingPipe(1, _slaveAddress);
  	_radio->startListening();
}

void RFManager::setWriter() {
	Serial.println("=> Setting Writer...");
	_radio->setRetries(3,5); // delay, count
 	_radio->openWritingPipe(_slaveAddress); //Abrir canal para escribir
}

void RFManager::sendData(char* message) {

    Serial.println("=> Sending Data...");
    
    _rslt = _radio->write(&message,sizeof(message)); //Envia la data del array
    
    Serial.println("=> Data Sent");
    Serial.println(message);
    Serial.println(_rslt);

    if (_rslt) { //Si la informacion se envio y fue recibida
        Serial.println("  Ack received.");
        updateMessage(); //Actualiza el mensaje con contador txNum
    } else {
        Serial.println("  Tx failed!");
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
	Serial.println("=> Getting Data...");
  	if ( _radio->available() ) { //Si el canal esta disponible
        Serial.println("=> Radio receiving..."); 
        _radio->read(&_dataReceived, sizeof(_dataReceived) ); //Lee la data y la guarda en el array
        _newData = true; // Setear variable de recibido de la informacion
    }
}

void RFManager::showData() {
	Serial.println('Showing Data');
  	if (_newData == true) { //Si la informacion se recibio
        Serial.print("Data received: ");
        Serial.println(_dataReceived); //Imprime lo que se encuentra en el array
        _newData = false; //Despues de mostrar la informacion cambiamos la variable de recepcion de datos a falso
    }
}

