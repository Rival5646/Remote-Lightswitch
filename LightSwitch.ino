#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <IRremote.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(9, OUTPUT);
  AFMS.begin();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if(results.value == 484668045){
      Serial.println("Turn Light ON");
      myMotor->setSpeed(255);
      myMotor->run(BACKWARD);
      delay(200);
      myMotor->setSpeed(0);
    
      
    }
    if(results.value == 484700685){
      Serial.println("Turn Light OFF");
      myMotor->setSpeed(255);
      myMotor->run(FORWARD);
      delay(200);
      myMotor->setSpeed(0);
      
    }
    
    irrecv.resume(); // Receive the next value
  }

}
