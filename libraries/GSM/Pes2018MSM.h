
/*
Pes2018MSM.h
* Libreria para realizar los metodos del Modulo MSM
* Creada: Yilmar Mazo Vargas
* Febrero 2018 ---

*/

#ifndef Pes2018MSM_h
#define Pes2018MSM_h
#include "Arduino.h"

class Pes2018MSM {

public:
	Pes2018MSM(int pin);
	void setOutputPin(int pin);
	void getPin();
	void sayHello();
	void Pes2018MSM::iniciarGSM()
private:
	int _pin;
	void Pes2018MSM::enviarAT(char* ATcommand, char* resp_correcta, unsigned int tiempo);
	//Serial _serialInstance;

};

#endif

