#include <Arduino.h>
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(3, a); 
  digitalWrite(2, b); 
  digitalWrite(7, c); 
  digitalWrite(8, d); 
  digitalWrite(9, e); 
  digitalWrite(4, f);     
  digitalWrite(5, g); 
}
void numberchooser(int a){
	switch (a){
		case 1:
			sevenseg(1,0,0,1,1,1,1);
			break;
		case 2:
			sevenseg(0,0,1,0,0,1,0);
			break;
		case 3:
			sevenseg(0,0,0,0,1,1,0);
			break;
		case 4:
			sevenseg(1,0,0,1,1,0,0);
			break;
		case 5:
			sevenseg(0,1,0,0,1,0,0);
			break;
		case 6:
			sevenseg(0,1,0,0,0,0,0);
			break;
		case 7:
			sevenseg(0,0,0,1,1,1,1);
			break;
		case 8:
			sevenseg(0,0,0,0,0,0,0);
			break;
		case 9:
			sevenseg(0,0,0,1,1,0,0);
			break;
		case 0:
			sevenseg(0,0,0,0,0,0,1);
			break;
				
	}
}
void setup() 
{
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);            
}
void loop() {
	numberchooser(9);
}

