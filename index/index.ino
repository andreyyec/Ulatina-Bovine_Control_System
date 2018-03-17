//*******  RF Libraries ********
#include <SoftwareSerial.h>
#include <Test.h>
#include <RF24.h>
#include <RFManager.h>

//****** MPU Libraries ******
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "MPUManager.h"
//***************************
//RF
#define CER_PIN 22
#define CSNR_PIN 23

//RF 
#define CES_PIN 30
#define CSNS_PIN 31

//Test testInstance(5);

//******* RF objects ********
RF24 _radio1(CES_PIN, CSNS_PIN);
RF24 _radio2(CER_PIN, CSNR_PIN);

RFManager rfManagerInstance1(_radio1); 
RFManager rfManagerInstance2(_radio2);

//******* MPU objects *******
MPU6050 sensor;

MPUManager MPUInstance(sensor);
//***************************

char message[11] = "Mensaje";
char _Msj[11];

void setup() {
  Serial.begin(9600);
  _radio1.begin();
  rfManagerInstance1.setUp();
  rfManagerInstance2.setUp();
  //Serial.println("This is a test");

  MPUInstance.startConnection();
}

void loop() {
  //testInstance.sayHello();
  //delay(2000);

  //Serial.println(message);
//******* RF functions ********
  rfManagerInstance1.setListener();
  rfManagerInstance1.getData();

  rfManagerInstance2.setWriter();
  rfManagerInstance2.sendData(message);
  
  rfManagerInstance1.showData();
//******* MPU functions ********
  MPUInstance.getData();
  MPUInstance.showData();
//***************************
}
