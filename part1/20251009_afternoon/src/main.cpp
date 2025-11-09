
#include <Arduino.h>
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(2, a); 
  digitalWrite(3, b); 
  digitalWrite(8, c); 
  digitalWrite(7, d); 
  digitalWrite(6, e); 
  digitalWrite(4, f);     
  digitalWrite(5, g); 
}
int a,b,c,d,e,f,g;
int A,B,C,D;
int Z=0,Y=1,X=1,W=0;
void setup() 
{
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);            

}
void loop() {

	A=!W;
	B=W&&!X&&!Z||!W&&X;
	C=!X&&Y||!W&&Y||W&&X&&!Y;
	D=!W&&Z||W&&X&&Y;

//	a = !D&&!C&&!B&&A || !D&&C&&!B&&!A;
//	b = !D&&C&&!B&&A || !D&&C&&B&&!A;
//	c = !D&&!C&&B&&!A;
//	d = !D&&!C&&!B&&A || !D&&C&&!B&&!A || !D&&C&&B&&A || D&&!C&&!B&&A;
//	e = !D&&!C&&!B&&A || !D&&!C&&B&&A || !D&&C&&!B&&!A || !D&&C&&!B&&A || !D&&C&&B&&A || D&&!C&&!B&&A;
//	f = !D&&!C&&!B&&A || !D&&!C&&B&&!A || !D&&!C&&B&&A || !D&&C&&B&&A;
//	g = !D&&!C&&!B&&!A || !D&&!C&&!B&&A || !D&&C&&B&&A;


//	a = !D&&!C&&!B&&A || !D&&C&&!B&&!A;
//	b = !D&&C&&!B&&A || !D&&C&&B&&!A;
//	c = !D&&!C&&B&&!A;
//	d = !D&&C&&!B&&!A || !D&&C&&B&&A || !C&&!B&&A;
//	e = !D&&C&&!B&&!A || !D&&A || !C&&!B&&A;
//	f = !D&&B&&A || !D&&!C&&A || !D&&!C&&B;
// 	g = !D&&!C&&!B || !D&&C&&B&&A;

	a = C&&!B&&!A || !D&&!C&&!B&&A;
	b = C&&!B&&A || C&&B&&!A;
	c = !C&&B&&!A;
	d = C&&!B&&!A || !C&&!B&&A || C&&B&&A;
	e = A || !B&&C;
	f = B&&A || B&&!C || !D&&!C&&A;
	g = !D&&!C&&!B || C&&B&&A;

	sevenseg(a,b,c,d,e,f,g);

}

