// C++ code
//
/*
  Keyboard

  Plays a pitch that changes based on a changing
  input circuit:
  * 3 pushbuttons from +5V to analog in 0 through
  3
  * 3 10K resistors from analog in 0 through 3 to
  ground
  * 8-ohm speaker on digital pin 8
*/


int pos = 0;

void setup()
{
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(8, OUTPUT);
  
}

void loop()
{
  // if button press on A1 is detected
  if (analogRead(A1) < 75) 
    tone(8, 440, 100); // play tone 57 (A4 = 440 Hz)
  
   if (analogRead(A2) < 75) 
    tone(8, 330 , 100); // play tone 57 (A4 = 440 Hz)
  
   if (analogRead(A3) < 75) 
    tone(8, 550 , 100); // play tone 57 (A4 = 440 Hz)
  
   if (analogRead(A4) < 75) 
    tone(8, 220 , 100); // play tone 57 (A4 = 440 Hz)
  
   if (analogRead(A5) < 75) 
    tone(8, 600 , 100); // play tone 57 (A4 = 440 Hz)
  
  delay(10); // Delay a little bit to improve simulation performance
}
