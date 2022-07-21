// 21-7-2022 Mecanum Car (All direction functions added, Front and Back speed done)
#include <Arduino.h>
// Motor 1 Pins
constexpr byte Motor1_PWB = 12;
constexpr byte Motor1_BI1 = 34;
constexpr byte Motor1_BI2 = 35;

// Motor 2 Pins
constexpr byte Motor2_PWB = 8;
constexpr byte Motor2_BI1 = 37;
constexpr byte Motor2_BI2 = 36;

// Motor 3 Pins
constexpr byte Motor3_PWB = 9;
constexpr byte Motor3_BI1 = 43;
constexpr byte Motor3_BI2 = 42;

// Motor 4 Pins
constexpr byte Motor4_PWB = 5;
constexpr byte Motor4_BI1 = 29;
constexpr byte Motor4_BI2 = 39;

// Motor Speed Variables
byte M1_Speed = 0;
byte M2_Speed = 0;
byte M3_Speed = 0;
byte M4_Speed = 0;
byte MotorSpeed = 0;
constexpr uint16_t MAX_SPEED = 255;

//Joystick Zones and Threshold
constexpr uint16_t JOYSTICK_Y_UPPER_THRESHOLD = 950;
constexpr uint16_t JOYSTICK_Y_MID_UPPER_THRESHOLD = 520;
constexpr uint16_t JOYSTICK_Y_MID_LOWER_THRESHOLD = 460;
constexpr uint16_t JOYSTICK_Y_LOWER_THRESHOLD = 30;

constexpr uint16_t JOYSTICK_X_UPPER_THRESHOLD = 950;
constexpr uint16_t JOYSTICK_X_MID_UPPER_THRESHOLD = 520;
constexpr uint16_t JOYSTICK_X_MID_LOWER_THRESHOLD = 460;
constexpr uint16_t JOYSTICK_X_LOWER_THRESHOLD = 30;
uint8_t joystickZone = 0;

void setup()
{
  // Motor 1 Setup
  pinMode(Motor1_PWB, OUTPUT);
  pinMode(Motor1_BI1, OUTPUT);
  pinMode(Motor1_BI2, OUTPUT);

  // Motor 2 Setup
  pinMode(Motor2_PWB, OUTPUT);
  pinMode(Motor2_BI1, OUTPUT);
  pinMode(Motor2_BI2, OUTPUT);

  // Motor 3 Setup
  pinMode(Motor3_PWB, OUTPUT);
  pinMode(Motor3_BI1, OUTPUT);
  pinMode(Motor3_BI2, OUTPUT);

  // Motor 4 Setup
  pinMode(Motor4_PWB, OUTPUT);
  pinMode(Motor4_BI1, OUTPUT);
  pinMode(Motor4_BI2, OUTPUT);
  Serial.begin(9600);
}

void Forward()
{
  M1_Speed = MotorSpeed;
  M2_Speed = MotorSpeed;
  M3_Speed = MotorSpeed;
  M4_Speed = MotorSpeed;

  // Motor 1 Forward
  digitalWrite(Motor1_BI1, LOW);
  digitalWrite(Motor1_BI2, HIGH);

  // Motor 2 Forward
  digitalWrite(Motor2_BI1, LOW);
  digitalWrite(Motor2_BI2, HIGH);

  // Motor 3 Forward
  digitalWrite(Motor3_BI1, HIGH);
  digitalWrite(Motor3_BI2, LOW);

  // Motor 4 Forward
  digitalWrite(Motor4_BI1, HIGH);
  digitalWrite(Motor4_BI2, LOW);
  Serial.println("Moving Forward");
}

void Backward()
{
  M1_Speed = MotorSpeed;
  M2_Speed = MotorSpeed;
  M3_Speed = MotorSpeed;
  M4_Speed = MotorSpeed;

  // Motor 1 Backward
  digitalWrite(Motor1_BI1, HIGH);
  digitalWrite(Motor1_BI2, LOW);

  // Motor 2 Backward
  digitalWrite(Motor2_BI1, HIGH);
  digitalWrite(Motor2_BI2, LOW);

  // Motor 3 Backward
  digitalWrite(Motor3_BI1, LOW);
  digitalWrite(Motor3_BI2, HIGH);

  // Motor 4 Backward
  digitalWrite(Motor4_BI1, LOW);
  digitalWrite(Motor4_BI2, HIGH);
  Serial.println("Moving Backward");
}

void SlidingLeft()
{
  M1_Speed = MotorSpeed;
  M2_Speed = MotorSpeed;
  M3_Speed = MotorSpeed;
  M4_Speed = MotorSpeed;

  // Motor 1 Forward
  digitalWrite(Motor1_BI1, LOW);
  digitalWrite(Motor1_BI2, HIGH);

  // Motor 2 Backward
  digitalWrite(Motor2_BI1, HIGH);
  digitalWrite(Motor2_BI2, LOW);

  // Motor 3 Forward
  digitalWrite(Motor3_BI1, HIGH);
  digitalWrite(Motor3_BI2, LOW);

  // Motor 4 Backward
  digitalWrite(Motor4_BI1, LOW);
  digitalWrite(Motor4_BI2, HIGH);
  Serial.println("Sliding Left");
}

void SlidingRight()
{
  M1_Speed = MotorSpeed;
  M2_Speed = MotorSpeed;
  M3_Speed = MotorSpeed;
  M4_Speed = MotorSpeed;

  // Motor 1 Backward
  digitalWrite(Motor1_BI1, HIGH);
  digitalWrite(Motor1_BI2, LOW);

  // Motor 2 Forward
  digitalWrite(Motor2_BI1, LOW);
  digitalWrite(Motor2_BI2, HIGH);

  // Motor 3 Backward
  digitalWrite(Motor3_BI1, LOW);
  digitalWrite(Motor3_BI2, HIGH);

  // Motor 4 Forward
  digitalWrite(Motor4_BI1, HIGH);
  digitalWrite(Motor4_BI2, LOW);
  Serial.println("Sliding Right");
}

void SlidingLeftForward()
{
  M1_Speed = MotorSpeed;
  M2_Speed = 0;
  M3_Speed = MotorSpeed;
  M4_Speed = 0;

  // Motor 1 Forward
  digitalWrite(Motor1_BI1, LOW);
  digitalWrite(Motor1_BI2, HIGH);

  // Motor 3 Forward
  digitalWrite(Motor3_BI1, HIGH);
  digitalWrite(Motor3_BI2, LOW);

  // Motor 2 and 4 Neutral
  Serial.println("Sliding Left Forward");
}

void SlidingRightForward()
{
  M1_Speed = 0;
  M2_Speed = MotorSpeed;
  M3_Speed = 0;
  M4_Speed = MotorSpeed;

  // Motor 2 Forward
  digitalWrite(Motor2_BI1, LOW);
  digitalWrite(Motor2_BI2, HIGH);

  // Motor 4 Forward
  digitalWrite(Motor4_BI1, HIGH);
  digitalWrite(Motor4_BI2, LOW);

  // Motor 1 and 3 Neutral
  Serial.println("Sliding Right Forward");
}

void SlidingRightBackward()
{
  M1_Speed = 0;
  M2_Speed = MotorSpeed;
  M3_Speed = 0;
  M4_Speed = MotorSpeed;

  // Motor 2 Forward
  digitalWrite(Motor2_BI1, HIGH);
  digitalWrite(Motor2_BI2, LOW);

  // Motor 4 Backward
  digitalWrite(Motor4_BI1, LOW);
  digitalWrite(Motor4_BI2, HIGH);

  // Motor 1 and 3 Neutral
  Serial.println("Sliding Right Backward");
}

void SlidingLeftBackward()
{
  M1_Speed = MotorSpeed;
  M2_Speed = 0;
  M3_Speed = MotorSpeed;
  M4_Speed = 0;

  // Motor 1 Backward
  digitalWrite(Motor1_BI1, HIGH);
  digitalWrite(Motor1_BI2, LOW);

  // Motor 3 Backward
  digitalWrite(Motor3_BI1, LOW);
  digitalWrite(Motor3_BI2, HIGH);

  // Motor 2 and 4 Neutral
  Serial.println("Sliding Left Backward");
}

void RotatingRight()
{
  M1_Speed = MotorSpeed;
  M2_Speed = MotorSpeed;
  M3_Speed = MotorSpeed;
  M4_Speed = MotorSpeed;

  // Motor 1 Forward
  digitalWrite(Motor1_BI1, LOW);
  digitalWrite(Motor1_BI2, HIGH);

  // Motor 2 Forward
  digitalWrite(Motor2_BI1, LOW);
  digitalWrite(Motor2_BI2, HIGH);

  // Motor 3 Backward
  digitalWrite(Motor3_BI1, LOW);
  digitalWrite(Motor3_BI2, HIGH);

  // Motor 4 Backward
  digitalWrite(Motor4_BI1, LOW);
  digitalWrite(Motor4_BI2, HIGH);
  Serial.println("Rotating Right");
}

void RotatingLeft()
{
  M1_Speed = MotorSpeed;
  M2_Speed = MotorSpeed;
  M3_Speed = MotorSpeed;
  M4_Speed = MotorSpeed;

  // Motor 1 Backward
  digitalWrite(Motor1_BI1, HIGH);
  digitalWrite(Motor1_BI2, LOW);

  // Motor 2 Backward
  digitalWrite(Motor2_BI1, HIGH);
  digitalWrite(Motor2_BI2, LOW);

  // Motor 3 Forward
  digitalWrite(Motor3_BI1, HIGH);
  digitalWrite(Motor3_BI2, LOW);

  // Motor 4 Forward
  digitalWrite(Motor4_BI1, HIGH);
  digitalWrite(Motor4_BI2, LOW);
  Serial.println("Rotating Left");
}

void loop()
{
  uint16_t Right_joystickX = analogRead(A1);
  uint16_t Right_joystickY = analogRead(A2);
  uint16_t Left_joystickX = analogRead(A6);
  uint16_t Left_joystickY = analogRead(A5);

  if (Left_joystickY < JOYSTICK_Y_LOWER_THRESHOLD /*30*/)
  {
    joystickZone += 1;
  }
  else if (Left_joystickY < JOYSTICK_Y_MID_LOWER_THRESHOLD /*460*/)
  {
    joystickZone += 2;
  }
  else if (Left_joystickY > JOYSTICK_Y_MID_UPPER_THRESHOLD /*520*/ && Left_joystickY < JOYSTICK_Y_UPPER_THRESHOLD /*950*/)
  {
    joystickZone += 3;
  }
  else if (Left_joystickY > JOYSTICK_Y_UPPER_THRESHOLD /*950*/)
  {
    joystickZone += 4;
  }
  else
  {
    joystickZone += 5;
  }

  if (Left_joystickX < JOYSTICK_X_LOWER_THRESHOLD /*30*/)
  {
    joystickZone += 10;
  }
  else if (Left_joystickX < JOYSTICK_X_MID_LOWER_THRESHOLD /*460*/)
  {
    joystickZone += 20;
  }
  else if (Left_joystickX > JOYSTICK_X_MID_UPPER_THRESHOLD /*520*/ && Left_joystickX < JOYSTICK_X_UPPER_THRESHOLD /*950*/)
  {
    joystickZone += 30;
  }
  else if (Left_joystickX > JOYSTICK_X_UPPER_THRESHOLD /*950*/)
  {
    joystickZone += 40;
  }
  else
  {
    joystickZone += 50;
  }

  switch(joystickZone){
    case 51: //Backward - Full Speed
      MotorSpeed = MAX_SPEED;
      Backward();
      break;
    
    case 52: //Backward - Mapping Speed
      MotorSpeed = map(Left_joystickY, JOYSTICK_Y_MID_LOWER_THRESHOLD, JOYSTICK_Y_LOWER_THRESHOLD, 0, MAX_SPEED);
      Backward();
      break;
    
    case 53: //Forward - Mapping Speed
      MotorSpeed = map(Left_joystickY, JOYSTICK_Y_MID_UPPER_THRESHOLD, JOYSTICK_Y_UPPER_THRESHOLD, 0, MAX_SPEED);
      Forward();
      break;

    case 54: //Forward - Full Speed
     MotorSpeed = MAX_SPEED;
     Forward();
     break;
    
    case 55: //Idle
     MotorSpeed = 0;
     Forward();
     break;

  }

  // Setting the speeds
  analogWrite(Motor1_PWB, M1_Speed);
  analogWrite(Motor2_PWB, M2_Speed);
  analogWrite(Motor3_PWB, M3_Speed);
  analogWrite(Motor4_PWB, M4_Speed);
  
  Serial.print(Left_joystickX);
  Serial.print(" ");
  Serial.print(Left_joystickY);
  Serial.print(" ");
  Serial.print(Right_joystickX);
  Serial.print(" ");
  Serial.print(Right_joystickY);
  Serial.print(" ");
  Serial.println(joystickZone);
  joystickZone = 0;
}