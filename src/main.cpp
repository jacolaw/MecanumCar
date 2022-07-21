//Mecanum Car All Forward
#include <Arduino.h>

//Motor 1 Pins
constexpr byte Motor1_PWB = 12;
constexpr byte Motor1_BI1 = 34;
constexpr byte Motor1_BI2 = 35;

//Motor 2 Pins
constexpr byte Motor2_PWB = 8;
constexpr byte Motor2_BI1 = 37;
constexpr byte Motor2_BI2 = 36;

//Motor 3 Pins
constexpr byte Motor3_PWB = 9;
constexpr byte Motor3_BI1 = 43;
constexpr byte Motor3_BI2 = 42;

//Motor 4 Pins
constexpr byte Motor4_PWB = 5;
constexpr byte Motor4_BI1 = 29;
constexpr byte Motor4_BI2 = 39;

void setup(){
  //Motor 1 Setup
  pinMode(Motor1_PWB, OUTPUT);
  pinMode(Motor1_BI1, OUTPUT);
  pinMode(Motor1_BI2, OUTPUT);
  
  //Motor 2 Setup
  pinMode(Motor2_PWB, OUTPUT);
  pinMode(Motor2_BI1, OUTPUT);
  pinMode(Motor2_BI2, OUTPUT);

  //Motor 3 Setup
  pinMode(Motor3_PWB, OUTPUT);
  pinMode(Motor3_BI1, OUTPUT);
  pinMode(Motor3_BI2, OUTPUT);
  
  //Motor 4 Setup
  pinMode(Motor4_PWB, OUTPUT);
  pinMode(Motor4_BI1, OUTPUT);
  pinMode(Motor4_BI2, OUTPUT);
}

void loop(){
  //Motor 1 Forward
  analogWrite(Motor1_PWB, 255);
  digitalWrite(Motor1_BI1, LOW);
  digitalWrite(Motor1_BI2, HIGH);
   
  //Motor 2 Forward
  analogWrite(Motor2_PWB, 255);
  digitalWrite(Motor2_BI1, LOW);
  digitalWrite(Motor2_BI2, HIGH);
 
  //Motor 3 Forward
  analogWrite(Motor3_PWB, 255);
  digitalWrite(Motor3_BI1, HIGH);
  digitalWrite(Motor3_BI2, LOW);
   
  //Motor 4 Forward
  analogWrite(Motor4_PWB, 255);
  digitalWrite(Motor4_BI1, HIGH);
  digitalWrite(Motor4_BI2, LOW);
 

}