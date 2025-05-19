//c++

#include <Stepper.h>
#define STEPS 32
#include <Servo.h>
Stepper stepper(STEPS, 8, 10, 9, 11);
int xPin = A0;
int yPin = A1;
int x1Pin = A2;
int y1Pin = A3;
int buttonPin = 2;
int buttonState = 0;
int x = 180;
int x1 = 180;
int y1 = 180;
Servo servo_3;
Servo servo_5;
Servo servo_6;
Servo servo_9;
String rts = (" ");
void setup() {
  stepper.setSpeed(700);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  servo_3.attach(3, 500, 2500);
  servo_5.attach(5, 500, 2500);
  servo_6.attach(6, 500, 2500);
  servo_9.attach(9, 500, 2500);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  int x1Value = analogRead(x1Pin);
  int y1Value = analogRead(y1Pin);

  xValue -= 520;
  xValue /= 500;
  xValue *= 2;
  x = x + xValue;
  yValue -= 520;
  yValue /= 500;
  yValue *= 20;

    xValue -= 520;
  xValue /= 500;
  xValue *= 2;
  x1 = x1 + x1Value;
  yValue -= 520;
  yValue /= 500;
  yValue *= 2;
  y1 = y1 +y1Value;
  
  int serv3 = x;
  int serv5 = x1;
  int serv6 = y1;
  int serv9 = 0;
  int Step1 = yValue;
  servo_3.write(serv3);
  servo_5.write(serv5);
  servo_6.write(serv6);
  servo_9.write(serv9);
  stepper.step(Step1);
 
  if (x>180){
  x= 180;
  }
  if (x<0){
  x= 0;
  }

    if (x1>180){
  x1= 180;
  }
  if (x1<0){
  x1= 0;
  }

    if (y1>180){
  y1= 180;
  }
  if (x<0){
  y1= 0;
  }
  
Serial.print ( x , OUTPUT);
Serial.print ( x1 , OUTPUT);
Serial.print ( y1 , OUTPUT);
Serial.print ( rts );
Serial.println ( yValue , OUTPUT);
delay (0);
}
