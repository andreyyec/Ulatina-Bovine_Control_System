
/*
Pes2018SD.h
* Libreria para realizar los metodos del Modulo MSM
* Creada: Yilmar Mazo Vargas
* Febrero 2018 ---

*/

#ifndef Pes2018SD_h
#define Pes2018SD_h
#include "Arduino.h"

class Pes2018SD {

public:
	
	///<summary>
	///Construtor
	///	Modelo Arduino		SS SLAVE
	///		UNO				  10
	///		MEGA				  53
	///</summary>
	///<param name="serialTe">solicita el puero o PI en el cual se conecto el modulo SD SS SLAVE</param>
	Pes2018SD(HardwareSerial *serialTe);
	///<summary>
	///inici el serial del modulo SD
	///</summary>
	void Pes2018SD::iniciarSD();
	///<summary>
	///	Metodo el utilizamos para guardar los datos de temperatura
	///</summary>
	///<param name="readTempC">solicita la temperatura en Celsius </param>
	///<param name="readTempF">solicita la temperatura en fahrenheit</param>
	///<param name="tipo">si el "tipo=1" guarda la temperatura del ambiente, si el "tipo =2" guarda la temperatura del objeto</param>
	void Pes2018SD::GuardarSDTem(float  readTempC, float  readTempF, int tipo);
	///<summary>
	///Valida la conexion del modulo y si tiene una tarjeta SD coneectada
	///</summary>
	void Pes2018SD::validarSD();
	///<summary>
	///Metodo el utilizamos para guardar los datos de temperatura
	///</summary>
	///<param name="flat">solicita el dato "flat"</param>
	///<param name="flon">solicita el dato "flon"</param>
	///<param name="age">solicita el dato "age"</param>
	///<param name="sat">solicita el dato "sat"</param>
	///<param name="prec">solicita el dato "prec"</param>
	///<param name="chars">solicita el dato "chars"</param>
	///<param name="sentences">solicita el dato "sentences"</param>
	///<param name="failed">solicita el dato "failed"</param>
	void Pes2018SD::GuardarSDGPS(String strGPS);
		//float flat, float flon, unsigned long age, unsigned short sat, unsigned long  prec, unsigned long chars, unsigned short sentences, unsigned short failed);
private:
	HardwareSerial *_chipSelect;
};

#endif


