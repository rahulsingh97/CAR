#include <IRremote.h>
const int RECV_PIN = 12;
unsigned long lastCode; 
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup(){Serial.begin(9600);irrecv.enableIRIn();}
void loop() {
if(irrecv.decode(&results)){
    if(results.value == 0xFFFFFFFF){results.value = lastCode;}
    if(results.value == 0xDE4001F){lastCode = results.value;
        //function              
    }
    if(results.value == 0x592FA519){lastCode = results.value;
       //function     
    }
    if(results.value == 0x69C6FA7D){lastCode = results.value;
       //function     
    }
    Serial.println(lastCode);
    delay(100); 
    irrecv.resume(); 
}}
