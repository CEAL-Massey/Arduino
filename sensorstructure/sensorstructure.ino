#include <Wire.h>

//Slave Address: must be unique per sensor
#define SENS_ADD 0x04
char data;


void setup() {
  // initialize i2c as 'slave'
  Wire.begin(SENS_ADD);
  // define callbacks for i2c communication
  Wire.onRequest(sendData);
}

void loop() {
  //Process for getting sensor readings goes here
  //value of sensor equals 'reading'
  //Example: reading is an analogue reading from A0
  data = analogRead(A0);
}

// callback for sending data
void sendData() {
    Wire.write(data);
}
