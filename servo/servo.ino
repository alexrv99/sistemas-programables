#include <Servo.h>

Servo sg90;

void setup() {
  Serial.begin(9600);
  sg90.attach(9);
}

void loop() {
  sg90.write(90);

  sg90.write(60);
  delay(1000);
  sg90.write(120);
  delay(1000);
}
