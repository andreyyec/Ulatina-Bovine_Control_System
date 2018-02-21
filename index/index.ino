#include <SoftwareSerial.h>
#include <Test.h>
#include <RF24.h>
#include <RFManager.h>

//RF
#define CER_PIN 22
#define CSNR_PIN 23

//RF 
#define CES_PIN 30
#define CSNS_PIN 31

Test testInstance(5);

RF24 _radio1(CES_PIN, CSNS_PIN);
RF24 _radio2(CER_PIN, CSNR_PIN);

RFManager rfManagerInstance1(_radio1);
RFManager rfManagerInstance2(_radio2);

char message[11] = "Mensaje";

void setup() {
  Serial.begin(9600);
  _radio1.begin();
  rfManagerInstance1.setUp();
  rfManagerInstance2.setUp();
  Serial.println("This is a test");
}

void loop() {
  testInstance.sayHello();
  delay(2000);

  Serial.println(message);

  rfManagerInstance1.setListener();
  rfManagerInstance1.getData();

  rfManagerInstance2.setWriter();
  rfManagerInstance2.sendData("test");

  rfManagerInstance1.showData();
  
}
