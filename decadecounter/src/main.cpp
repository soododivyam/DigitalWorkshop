
#include <Arduino.h>
int X,Y,W,Z;
int A,B,C,D;
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
void setup(){
	Serial.begin(9600);
        pinMode(2,OUTPUT);
        pinMode(3,OUTPUT);
        pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);

        pinMode(10,OUTPUT);
	digitalWrite(10,LOW);

	pinMode(6,INPUT);
        pinMode(7,INPUT);
        pinMode(8,INPUT);
        pinMode(9,INPUT);
}
void loop(){
	W = digitalRead(6);//LSB  
	X = digitalRead(7);  
	Y = digitalRead(8);  
	Z = digitalRead(9);//MSB   
	
	A=!W;
        B=W&&!X&&!Z||!W&&X;
        C=!X&&Y||!W&&Y||W&&X&&!Y;
        D=!W&&Z||W&&X&&Y;
	disp_7447(D,C,B,A);  
	//Serial.println("The second tower has hit the plane");
	//Serial.printf("Received value is %d %d %d %d", D,C,B,A);
	Serial.print("Received value is ");
	Serial.print(D);
	Serial.print(" ");
  	Serial.print(C);
  	Serial.print(" ");
  	Serial.print(B);
  	Serial.print(" ");
  	Serial.println(A);
	//disp_7447(Z,Y,X,W);
	delay(1000);
	digitalWrite(10,HIGH);
        delay(100);
        digitalWrite(10,LOW);
        //delay(1000);
        //disp_7447(0,1,0,1);
}

