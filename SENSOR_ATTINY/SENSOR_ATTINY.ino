// the 7-bit address (remember to change this when adapting this example)
#define I2C_SLAVE_ADDRESS 0x04
// Get this from https://github.com/rambo/TinyWire
#include <TinyWireS.h>
#include "dht.h"
#define DHTPIN 4
dht DHT;
int temp, humid, gl;

void setup()
{
    pinMode(1, OUTPUT);
    pinMode(4, INPUT);
    //Serial.begin(9600);
    TinyWireS.begin(I2C_SLAVE_ADDRESS);
    //Sets up the onRequest function (what we do if asked to send something).
    TinyWireS.onRequest(requestEvent);
}

void loop()
{
  int chk = DHT.read11(DHTPIN);
  temp = DHT.temperature;
  humid = DHT.humidity;

  delay(2000); 
}

void requestEvent(){
  if(gl == 0) {
    TinyWireS.send(temp);
    gl = 1;
  }
  else {
    TinyWireS.send(humid);
    gl = 0;
  }
  digitalWrite(1,HIGH);
  delay(10);
  digitalWrite(1,LOW);
}

//Just need to get humidity and temp come through hard g
