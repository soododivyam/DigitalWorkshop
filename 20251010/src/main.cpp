
#include <Arduino.h>
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
void setup(){
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	pinMode(13,OUTPUT);
	pinMode(6,INPUT);
	pinMode(7,INPUT);
	pinMode(8,INPUT);
	pinMode(9,INPUT);
}
void loop(){
	digitalWrite(13,HIGH);
	delay(100);
	digitalWrite(13,LOW);
	delay(100);
	disp_7447(1,0,1,1);
}
