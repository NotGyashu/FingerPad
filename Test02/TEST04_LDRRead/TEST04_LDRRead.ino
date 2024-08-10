void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  pinMode(A2,INPUT); 
  pinMode(A3,INPUT); 
  pinMode(A4,INPUT); 
  pinMode(A5,INPUT); 
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A3));
  delay(100);
  
}
