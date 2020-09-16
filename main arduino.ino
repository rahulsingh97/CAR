#include <NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define motor1 5
#define motor11 6
#define motor2 7
#define motor22 8
#define motor1speed 9
#define motor2speed 10

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int dist;

void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);   //Motor connected the flow sensor 1
  pinMode(motor11, OUTPUT);   //Motor connected the flow sensor 1
  pinMode(motor2, OUTPUT);
  pinMode(motor22, OUTPUT);
  pinMode(motor1speed, OUTPUT);
  pinMode(motor2speed, OUTPUT);
  digitalWrite(motor1, LOW);
  digitalWrite(motor11, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor22, LOW);
  analogWrite(motor1speed, 0);
  analogWrite(motor2speed, 0);
}
bool high = LOW;
bool low = HIGH;

void loop() {
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  dist = sonar.convert_cm(uS);
  //Serial.println(String(dist));

  if (dist < 70 && dist > 40) {
    digitalWrite(motor1, LOW);
    digitalWrite(motor11, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor22, LOW);
    analogWrite(motor1speed, 0);
    analogWrite(motor2speed, 0);
  }
  while (Serial.available() > 0) {
    String data = Serial.readStringUntil('@');
    Serial.println(data);
    if (data == "o")
    {
      Serial.println("Turning off both motors");
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor22, LOW);
      analogWrite(motor1speed, 0);
      analogWrite(motor2speed, 0);
    }
    else if (data == "f")
    {
      Serial.println("Turning off motor 5, Turning on motor 7 ");
      digitalWrite(motor1, HIGH);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, high);
      digitalWrite(motor22, low);
      analogWrite(motor1speed, 150);
      analogWrite(motor2speed, 150);
    }
    else if (data == "b")
    {
      Serial.println("Turning on motor 5, Turning off motor 7");
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, HIGH);
      digitalWrite(motor2, low);
      digitalWrite(motor22, high);
      analogWrite(motor1speed, 0);
      analogWrite(motor2speed, 0);
    }
    else if (data == "r")
    {
      Serial.println("Turning on both motors");
      // Stopping inside motor 
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, LOW);      
      digitalWrite(motor2, high);
      digitalWrite(motor22, low);
      delay(500);
      stop();
    }
    else if (data == "l")
    {
      Serial.println("Turning on both motors");
      digitalWrite(motor1, HIGH);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor22, LOW);
      delay(500);
      stop();
    }
    else if (data == "lf")
    {
      Serial.println("Left forward");
      //Rotate left
      digitalWrite(motor1, HIGH);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor22, LOW);
      delay(600);
      //Forward
      digitalWrite(motor1, HIGH);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, high);
      digitalWrite(motor22, low);
      analogWrite(motor1speed, 0);
      analogWrite(motor2speed, 150);
    }
    else if (data == "lb")
    {
       Serial.println("Left Backward");
      //Rotate left
      digitalWrite(motor1, HIGH);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor22, LOW);
      delay(600);
      //Backward
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, HIGH);
      digitalWrite(motor2, low);
      digitalWrite(motor22, high);
      analogWrite(motor1speed, 0);
      analogWrite(motor2speed, 150);
    }
    else if (data == "rf")
    {
       Serial.println("Right forward");
      //Rotate right
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, LOW);
      
      digitalWrite(motor2, high);
      digitalWrite(motor22, low);
      delay(600);
      //Forward
      digitalWrite(motor1, HIGH);
      digitalWrite(motor11, LOW);
      digitalWrite(motor2, high);
      digitalWrite(motor22, low);
      analogWrite(motor1speed, 0);
      analogWrite(motor2speed, 150);
    }
    else if (data == "rb")
    {
      Serial.println("Right Backward");
      //Rotate right
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, LOW);
      
      digitalWrite(motor2, high);
      digitalWrite(motor22, low);
      delay(600);
      //Backward
      digitalWrite(motor1, LOW);
      digitalWrite(motor11, HIGH);
      digitalWrite(motor2, low);
      digitalWrite(motor22, high);
      analogWrite(motor1speed, 0);
      analogWrite(motor2speed, 150);
    }
  }
}
void stop()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor11, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor22, LOW);
  analogWrite(motor1speed, 0);
  analogWrite(motor2speed, 0);
}
