//Declaring all variables as integers
#include<Arduino.h>
int A,B,C,D;
int a,b,c,d,e,f,g;
//Code released under GNU GPL.  Free to use for anything
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(12, OUTPUT);
    pinMode(6, INPUT);  
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    
}

// the loop function runs over and over again forever
void loop() {
  
A = digitalRead(6);//LSB  
B = digitalRead(7);  
C = digitalRead(8);  
D = digitalRead(9);//MSB  
  

a=(A*!B&&!C&&!D)||(!A&&!B&&C&&!D);
b=(A&&!B&&C&&!D)||(!A&&B&&C&&!D);
c=(!A&&B&&!C&&!D);
d=(A&&!B&&!C&&!D)||(!A&&!B&&C&&!D)+(A&&B&&C&&!D);
e=(A&&!B&&!C&&!D)||(A&&B&&!C&&!D)||(!A&&!B&&C&&!D)||(A&&!B&&C&&!D)||(A&&B&&C&&!D)||(A&&!B&&!C&&D);
f=(A&&!B&&!C&&!D)||(!A&&B&&!C&&!D)||(A&&B&&!C&&!D)||(A&&B&&C&&!D);
g=(!A&&!B&&!C&&!D)||(A&&!B&&!C&&!D)||(A&&B&&C&&!D);

digitalWrite(2,a);
digitalWrite(3,b);
digitalWrite(4,c);
digitalWrite(5,d);
digitalWrite(10,e);
digitalWrite(11,f);
digitalWrite(12,g);
}
