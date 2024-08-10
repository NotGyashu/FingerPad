#include "SPI.h"
#include "TMRpcm.h"
#include "SD.h"
#define CSP 4

TMRpcm tmrpcm;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(8, OUTPUT);

  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  if(!SD.begin(CSP)){
    digitalWrite(8, HIGH);
    return;
  }
  tmrpcm.setVolume(6);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // if button press on A1 is detected
  if (analogRead(A1) < 75) 
   tmrpcm.play("1.wav");
  
   if (analogRead(A2) < 75) 
   tmrpcm.play("2.wav");
  
   if (analogRead(A3) < 75) 
    tmrpcm.play("3.wav");
  
   if (analogRead(A4) < 75) 
    tmrpcm.play("4.wav");
  
   if (analogRead(A5) < 75) 
   tmrpcm.play("5.wav");
  
  delay(500); // Delay a little bit to improve simulation performance


}
