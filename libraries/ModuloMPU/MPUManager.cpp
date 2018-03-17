    
/*
  MPUManager.cpp - Library defining project structure
  File with actual algorithms and functions
*/
#include "Arduino.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "MPUManager.h"
#include "Wire.h"


MPUManager::MPUManager(MPU6050 &sensor) {
    
    _mpuA = &sensor;
    Serial.begin(9600);    //Iniciando puerto serial
    Wire.begin();           //Iniciando I2C  
}


void MPUManager::getData(){
 // Leer las aceleraciones y velocidades angulares
  _mpuA->getAcceleration(&ax, &ay, &az);
  _mpuA->getRotation(&gy, &gx, &gz);

 //Calcular los angulos de rotacion:
  
  dt = millis()-tiempo_prev;
  tiempo_prev=millis();

  girosc_ang_x = (gx/131)*dt/1000.0 + girosc_ang_x_prev;
  girosc_ang_y = (gy/131)*dt/1000.0 + girosc_ang_y_prev;
  girosc_ang_z = (gz/131)*dt/1000.0 + girosc_ang_z_prev;

  girosc_ang_x_prev=girosc_ang_x;
  girosc_ang_y_prev=girosc_ang_y;
  girosc_ang_z_prev=girosc_ang_z;
  
  ax_m_s2 = ax * (9.81/16384.0); //9.81 de gravedad | 16384 de los sensitivities para MPU | http://www.naylampmechatronics.com/blog/45_Tutorial-MPU6050-Aceler%C3%B3metro-y-Giroscopio.html
  ay_m_s2 = ay * (9.81/16384.0);
  az_m_s2 = az * (9.81/16384.0);
}


void MPUManager::showData(){
   //Mostrar los aceleracion separadas por un [tab]
  Serial.print("Aceleración en X:  ");
  Serial.print(ax_m_s2);
  Serial.print("    Aceleración en Y:  ");
  Serial.print(ay_m_s2);
  Serial.print("    Aceleración en Z:  ");
  Serial.print(az_m_s2);
  //Mostrar los angulos separadas por un [tab]
  Serial.print("    Rotacion en X:  ");
  Serial.print(girosc_ang_x); 
  Serial.print("    Rotacion en Y: ");
  Serial.print(girosc_ang_y);
  Serial.print("    Rotacion en Z: ");
  Serial.println(girosc_ang_z);
  delay(100);
}

void MPUManager::startConnection(){ 

  _mpuA->initialize();    //Iniciando el sensor

  if (_mpuA->testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
  tiempo_prev=millis();
}
