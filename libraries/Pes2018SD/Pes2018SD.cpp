/*
Pes2018SD.h
* Libreria para realizar los metodos del Modulo SD
* Creada: Yilmar Mazo Vargas
* Febrero 2018 ---

CONEXION SEGUN LA TARJETA 

	Modelo Arduino		MOSI			MISO			SDK			SS SLAVE	SS		MASTER
		UNO				11,ICSP-4	12,ICSP-1	13,ICSP-3		10			Z
		MEGA				51,ICSP-4	50,ICSP-1	52,ICSP-3		53			Z
		LEONARDO			ICSP-4		ICSP-1		ICSP-3			Z			Z
		DUE				ICSP-4		ICSP-1		ICSP-3			Z			4,10,52

*/
/*
	Librerias 
*/
#include "Arduino.h"
#include "Pes2018SD.h"
#include <SPI.h>//tarjeta SD
#include <SD.h>//Tarjeta SD

/*
<summary>
	Construtor 
		Modelo Arduino		SS SLAVE
			UNO				  10
			MEGA				  53
</summary>
<param name="serialTe"=solicita el puero o PI en el cual se conecto el modulo SD SS SLAVE/>
*/
Pes2018SD::Pes2018SD(HardwareSerial *serialTe)
{
	_chipSelect = serialTe;
	_chipSelect->begin(9600);
}
/*
<summary>
	inici el serial del modulo SD
</summary>
*/
void Pes2018SD::iniciarSD()
{
	//código
	SD.begin(_chipSelect); // Iniciamos el módulo SD
	while (!Serial) {
		; // Espere a que se conecte el puerto serie. Necesario solo para el puerto USB nativo
	}
	
}
/*
<summary>
	Valida la conexion del modulo y si tiene una tarjeta SD coneectada
</summary>
*/
void Pes2018SD:: validarSD() {
	Sd2Card card;
	// usaremos el código de inicialización de las bibliotecas de utilidades
	if (!card.init(SPI_HALF_SPEED, _chipSelect)) {
		Serial.println("error de inicialización. Cosas que verificar:");
		Serial.println("* ¿está insertada una tarjeta?");
		Serial.println("* ¿su cableado es correcto?");
		Serial.println("* ¿Cambió el chipSelect pin para que coincida con su escudo o módulo?");
		return;
	}
	else {
		Serial.println("El cableado es correcto y hay una tarjeta presente.");
	}

}
/*
<summary>
	Metodo el utilizamos para guardar los datos de temperatura
</summary>
<param name="readTempC"=solicita la temperatura en Celsius />
<param name="readTempF"=solicita la temperatura en fahrenheit/>
<param name="tipo"=si el "tipo=1" guarda la temperatura del ambiente, si el "tipo =2" guarda la temperatura del objeto/>
*/
void Pes2018SD::GuardarSDTem(float  readTempC, float  readTempF, int tipo) {
		if (tipo==1) {
		File dataFile = SD.open("TempA.txt", FILE_WRITE); //Crea el archivo DHT11 o si ya existe escribe dentro de el (Podeis cambiarlo)
		if (dataFile)
		{
			Serial.println("Guardando Temperatura Ambiente...");
			dataFile.print("La temperatura es de: ");   dataFile.print(readTempC); dataFile.println("*C");
			dataFile.print("La temperatura es de: ");   dataFile.print(readTempF); dataFile.println("*F");
			Serial.print("La temperatura es de: ");  Serial.print(readTempC); Serial.println("*C");
			Serial.print("La temperatura es de: ");  Serial.print(readTempF); Serial.println("*F");
			dataFile.close();
		}
		else
		{
			Serial.print("Error al guardar...");
		}
	}
	else
	{
		File dataFile = SD.open("TempO.txt", FILE_WRITE); //Crea el archivo DHT11 o si ya existe escribe dentro de el (Podeis cambiarlo)
		if (dataFile)
		{
			Serial.println("guardando Temperatura Objeto...");
			dataFile.print("La temperatura es de: ");  dataFile.print(readTempC); dataFile.println("*C");
			dataFile.print("La temperatura es de: "); dataFile.print(readTempF); dataFile.println("*F");
			Serial.print("La temperatura es de: ");   Serial.print(readTempC); Serial.println("*C");
			Serial.print("La temperatura es de: ");  Serial.print(readTempF); Serial.println("*F");
			dataFile.close();
		}
		else
		{
			Serial.print("Error al guardar...");
		}
	}
}
/*
<summary>
Metodo el utilizamos para guardar los datos de temperatura
</summary>
<param name="flat"=solicita el dato "flat"/>
<param name="flon"=solicita el dato "flon"/>
<param name="age"=solicita el dato "age"/>
<param name="sat"=solicita el dato "sat"/>
<param name="prec"=solicita el dato "prec"/>
<param name="chars"=solicita el dato "chars"/>
<param name="sentences"=solicita el dato "sentences"/>
<param name="failed"=solicita el dato "failed"/>
*/
void Pes2018SD::GuardarSDGPS(String strGPS){
	//float flat, float flon, unsigned long age, unsigned short sat, unsigned long  prec,
	//unsigned long chars, unsigned short sentences, unsigned short failed) {
		File dataFile = SD.open("GPS.txt", FILE_WRITE); //Crea el archivo GPS o si ya existe escribe dentro de el (Podeis cambiarlo)
		if (dataFile)
		{
			Serial.println("Guardando GPS...");
			dataFile.print(strGPS);
			Serial.print(strGPS);
			/*dataFile.print(flat);
			dataFile.print(" LON=");
			dataFile.print(flon);
			dataFile.print(" SAT=");
			dataFile.print(sat);
			dataFile.print(" PREC=");
			dataFile.print(prec);
		
			dataFile.print(" CHARS=");
			dataFile.print(chars);
			dataFile.print(" SENTENCES=");
			dataFile.print(sentences);
			dataFile.print(" CSUM ERR=");
			dataFile.println(failed);

			Serial.print("LAT=");
			Serial.print(flat);
			Serial.print(" LON=");
			Serial.print(flon);
			Serial.print(" SAT=");
			Serial.print(sat);
			Serial.print(" PREC=");
			Serial.print(prec);

			Serial.print(" CHARS=");
			Serial.print(chars);
			Serial.print(" SENTENCES=");
			Serial.print(sentences);
			Serial.print(" CSUM ERR=");
			Serial.println(failed);*/
			dataFile.close();	
		}
		else
		{
			Serial.print("Error al guardar...");
		}
}
