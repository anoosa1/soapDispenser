#include <Servo.h>

#define US_TRIG 10
#define US_ECHO 11
#define SERVO_PIN 12

Servo servo;

void setup()
{
  // start serial
  Serial.begin(9600);

  // setup ultrasonic pins
  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);

  // setup servo pins
  servo.attach(SERVO_PIN);     
}

void loop() 
{
  int read = readUltrasonic();
  delay(100);
  if(read < 5)
  {
    servo.write(90);
    delay(500);
  }
  else
  {
    servo.write(1);
  }
}