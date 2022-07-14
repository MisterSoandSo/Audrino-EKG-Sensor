#include "arduino-timer.h"

// These constants won't change. They're used to give names to the pins used:

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
bool readyADC=false;

Timer <1,micros>timer;   //one task
bool readADC(void *){
  sensorValue=analogRead(analogInPin);
  readyADC=true;
}
void setup() {
  init();
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(19200);  //38400);   //19200); //9600);
  //call the ReadADC
  timer.every(2540,readADC);   //2777
  readyADC=false;
}

void loop() {
  timer.tick();
  if(readyADC==true){
    readyADC=false;
    Serial.print("!");
    Serial.print( sensorValue);
  
  }
}
