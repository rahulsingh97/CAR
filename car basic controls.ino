#include <IRremote.h>
const int RECV_PIN = 8;
unsigned long lastCode; 
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup(){Serial.begin(9600);irrecv.enableIRIn();
pinMode(4,OUTPUT);pinMode(2,OUTPUT);
digitalWrite(4,HIGH);digitalWrite(2,HIGH);
pinMode(3,OUTPUT);pinMode(5,OUTPUT);//weel
pinMode(6,OUTPUT);pinMode(9,OUTPUT);//weel
pinMode(10,OUTPUT);pinMode(11,OUTPUT);//turn
}
void loop() {
if(irrecv.decode(&results)){
    if(results.value == 4294967295){results.value = lastCode;}
    if(results.value == 16422){lastCode = results.value;
    Serial.println("forword");
    digitalWrite(3,HIGH);digitalWrite(5,LOW);
    digitalWrite(6,HIGH);digitalWrite(9,LOW);
    delay(10);
    digitalWrite(3,LOW);digitalWrite(5,LOW);
    digitalWrite(6,LOW);digitalWrite(9,LOW);
        //function                     
    }
    if(results.value == 24614){lastCode = results.value;
    Serial.println("left");
    digitalWrite(3,HIGH);digitalWrite(5,LOW);
    digitalWrite(6,HIGH);digitalWrite(9,LOW);
    digitalWrite(10,HIGH);digitalWrite(11,LOW);
    delay(10);
    digitalWrite(3,LOW);digitalWrite(5,LOW);
    digitalWrite(6,LOW);digitalWrite(9,LOW);
    digitalWrite(10,LOW);digitalWrite(11,LOW);
       //function     
    }
    if(results.value == 20518){lastCode = results.value;
    Serial.println("right");
    digitalWrite(3,HIGH);digitalWrite(5,LOW);
    digitalWrite(6,HIGH);digitalWrite(9,LOW);
    digitalWrite(10,LOW);digitalWrite(11,HIGH);
    delay(10);
    digitalWrite(3,LOW);digitalWrite(5,LOW);
    digitalWrite(6,LOW);digitalWrite(9,LOW);
    digitalWrite(10,LOW);digitalWrite(11,LOW);
       //function     
    }
    if(results.value == 28710){lastCode = results.value;
    Serial.println("back");
    digitalWrite(3,LOW);digitalWrite(5,HIGH);
    digitalWrite(6,LOW);digitalWrite(9,HIGH);
    delay(10);
    digitalWrite(3,LOW);digitalWrite(5,LOW);
    digitalWrite(6,LOW);digitalWrite(9,LOW);
       //function     
    }
    //Serial.println(lastCode);
    //Serial.println(results.value);
    delay(90); 
    irrecv.resume(); 
}}
