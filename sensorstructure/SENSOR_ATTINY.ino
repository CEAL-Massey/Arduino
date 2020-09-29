// the 7-bit address (remember to change this when adapting this example)
#define I2C_SLAVE_ADDRESS 0x04

// Get this from https://github.com/rambo/TinyWire
#include <TinyWireS.h>

char reading = 1;

void requestEvent(){  
  TinyWireS.send(reading);
}

void setup()
{
    //Serial.begin(9600);
    TinyWireS.begin(I2C_SLAVE_ADDRESS);
    //Sets up the onRequest function (what we do if asked to send something).
    TinyWireS.onRequest(requestEvent);
}

void loop()
{

}
