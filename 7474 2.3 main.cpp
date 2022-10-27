#include<Arduino.h>
//Declaring all variables as integers
int Z,Y,X,W;
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
    pinMode(6, INPUT);  
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    
    
}

// the loop function runs over and over again forever
void loop() {
 digitalWrite(LED_BUILTIN,HIGH);
 delay(1000);
W = digitalRead(6);//LSB  
X = digitalRead(7);  
Y = digitalRead(8);  
Z = digitalRead(9);//MSB 
 
 
A=(!W&&!X&&!Y&&!Z)|| (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);

digitalWrite(LED_BUILTIN,LOW);
 delay(1000);  
 
disp_7447(D,C,B,A);  

}
