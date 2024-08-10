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
  tmrpcm.setVolume(5);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // if button press on A1 is detected
  while(analogRead(A3)>500){
    delay(100);
    Serial.print("*");
  }
  int t1 = millis();
  while(analogRead(A3)>75){
    delay(100);
        Serial.print("#");

    }
  if(analogRead(A3)<75){
      int t2 = millis();
      int t = (t2-t1);
          Serial.print(t);
          delay(100);

      if(t>200){
        tmrpcm.play("1.wav");
            Serial.print("a");
            delay(100);
      }
        else{
        tmrpcm.play("4.wav");
            Serial.print("b");
            delay(100);
        }
    }
  delay(100);
   // Delay a little bit to improve simulation performance


}
