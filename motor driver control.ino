#include <IRremote.h>
int IRsensorPin = 12;
IRrecv irrecv(IRsensorPin);
decode_results results;
int RightMotorForward = 2;    
int RightMotorBackward = 3;   
int LeftMotorForward = 4;     
int LeftMotorBackward = 5;    
void setup(){
  pinMode(LeftMotorForward,OUTPUT);
  pinMode(RightMotorForward,OUTPUT);
  pinMode(LeftMotorBackward,OUTPUT);
  pinMode(RightMotorBackward,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop(){
if (irrecv.decode(&results)){
Serial.println(results.value);
delay(5);
irrecv.resume();
  }
  // instead of zeros "0000", write the hex codes
  if(results.value == 0000) MotorForward();
  if(results.value == 0000) MotorBackward();
  if(results.value == 0000) TurnRight();
  if(results.value == 0000) TurnLeft();
  if(results.value == 0000) MotorStop();
}

// FORWARD 
void MotorForward(){
  digitalWrite(LeftMotorForward,HIGH);
  digitalWrite(RightMotorForward,HIGH);
  digitalWrite(LeftMotorBackward,LOW);
  digitalWrite(RightMotorBackward,LOW); 
}

// BACKWARD 
void MotorBackward(){
  digitalWrite(LeftMotorBackward,HIGH);
  digitalWrite(RightMotorBackward,HIGH);
  digitalWrite(LeftMotorForward,LOW);
  digitalWrite(RightMotorForward,LOW);
}

// TURN RIGHT 
void TurnRight(){
  digitalWrite(LeftMotorForward,HIGH); 
  digitalWrite(RightMotorForward,LOW);
  digitalWrite(LeftMotorBackward,LOW);
  digitalWrite(RightMotorBackward,HIGH);
}

// TURN LEFT 
void TurnLeft(){
  digitalWrite(RightMotorForward,HIGH);  
  digitalWrite(LeftMotorForward,LOW);
  digitalWrite(LeftMotorBackward,HIGH);
  digitalWrite(RightMotorBackward,LOW);
}

// STOP 
void MotorStop(){
  digitalWrite(LeftMotorBackward,LOW);
  digitalWrite(RightMotorBackward,LOW);
  digitalWrite(LeftMotorForward,LOW);
  digitalWrite(RightMotorForward,LOW);
}
