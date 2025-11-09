
#include <Arduino.h>

//Declaring all variables as integers
int Z=0,Y=1,X=1,W=0;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
//These are non-minimized
  //A=(!Z&&!Y&&!X&&!W) || (!Z&&!Y&&X&&!W) || (!Z&&Y&&!X&&!W) || (!Z&&Y&&X&&!W) || (Z&&!Y&&!X&&!W);
  //B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  //C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  //D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);

	//These are for K-Map minimized
	//A=(!W&&!Z)||(!W&&!X&&!Y);
	//B=(W&&!X&&!Z)||(!W&&X&&!Z);
	//C=(W&&X&&!Y&&!Z)||(!X&&Y&&!Z)||(!W&&Y&&!Z);
	//D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);

	//For Dont care
	A=!W;
	B=W&&!X&&!Z||!W&&X;
	C=!X&&Y||!W&&Y||W&&X&&!Y;
	D=!W&&Z||W&&X&&Y;
  
disp_7447(D,C,B,A);  
}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
