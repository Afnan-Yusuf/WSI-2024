#include <Arduino.h>
//#include "CytronMotorDriver.h"

volatile unsigned long lastPulseA4 = 0;
volatile unsigned long lastPulseA5 = 0;
volatile unsigned long lastPulseA8 = 0;
volatile unsigned long lastPulseA9 = 0;
volatile unsigned long lastPulseA10 = 0;
volatile unsigned long lastPulseA11 = 0;

const int xmin = 1085;
const int xmax = 1902;
const int ymin = 1050;
const int ymax = 1974;

const int thresh = 25;
const unsigned long pulseTimeout = 1000; // Timeout for pulses in microseconds

//CytronMD motor_right(PWM_DIR, 14, 2);
//CytronMD motor_left(PWM_DIR, 15, 3);

void handlePulseA4();
void handlePulseA5();
void handlePulseA8();
void handlePulseA9();
void handlePulseA10();
void handlePulseA11();
void setup()
{
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  attachInterrupt(digitalPinToInterrupt(A4), handlePulseA4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(A5), handlePulseA5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(A8), handlePulseA8, CHANGE);
  attachInterrupt(digitalPinToInterrupt(A9), handlePulseA9, CHANGE);
  attachInterrupt(digitalPinToInterrupt(A10), handlePulseA10, CHANGE);
  attachInterrupt(digitalPinToInterrupt(A11), handlePulseA11, CHANGE);
  Serial.begin(9600);
}

void loop()
{
  int rightspeed;
  int leftspeed;

  int angular = map(lastPulseA10, xmin, xmax, 255, -255);
  int linear = map(lastPulseA11, ymin, ymax, 255, -255);
  if (linear > thresh)
  {
    rightspeed = linear + angular;
    leftspeed = linear - angular;

    motor_right.setSpeed(rightspeed);
    motor_left.setSpeed(leftspeed);
  }
  else if (linear < (0 - thresh))
  {
    rightspeed = linear + angular;
    leftspeed = linear - angular;

    motor_right.setSpeed(rightspeed);
    motor_left.setSpeed(leftspeed);
  }
  else
  {
    motor_right.setSpeed(right);
    motor_left.setSpeed(left);
  }
   Serial.print(lastPulseA10);
   Serial.print("\t");
   Serial.println(lastPulseA11);
}

void handlePulseA4()
{
  static unsigned long lastTime = 0;
  unsigned long currentTime = micros();
  if (digitalRead(A4) == HIGH)
  {
    lastTime = currentTime;
  }
  else
  {
    lastPulseA4 = currentTime - lastTime;
  }
}

void handlePulseA5()
{
  static unsigned long lastTime = 0;
  unsigned long currentTime = micros();
  if (digitalRead(A5) == HIGH)
  {
    lastTime = currentTime;
  }
  else
  {
    lastPulseA5 = currentTime - lastTime;
  }
}

void handlePulseA8()
{
  static unsigned long lastTime = 0;
  unsigned long currentTime = micros();
  if (digitalRead(A8) == HIGH)
  {
    lastTime = currentTime;
  }
  else
  {
    lastPulseA8 = currentTime - lastTime;
  }
}

void handlePulseA9()
{
  static unsigned long lastTime = 0;
  unsigned long currentTime = micros();
  if (digitalRead(A9) == HIGH)
  {
    lastTime = currentTime;
  }
  else
  {
    lastPulseA9 = currentTime - lastTime;
  }
}

void handlePulseA10()
{
  static unsigned long lastTime = 0;
  unsigned long currentTime = micros();
  if (digitalRead(A10) == HIGH)
  {
    lastTime = currentTime;
  }
  else
  {
    lastPulseA10 = currentTime - lastTime;
  }
}

void handlePulseA11()
{
  static unsigned long lastTime = 0;
  unsigned long currentTime = micros();
  if (digitalRead(A11) == HIGH)
  {
    lastTime = currentTime;
  }
  else
  {
    lastPulseA11 = currentTime - lastTime;
  }
}
