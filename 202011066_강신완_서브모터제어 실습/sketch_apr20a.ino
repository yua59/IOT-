#include <Servo.h>

Servo myServo;
int angle = 90;
void setup() {
  myServo.attach(12);
  // put your setup code here, to run once:

}

void loop() {
  for (angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);
    delay(15);
  }
  for (angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);
    delay(15);
  } 

  // put your main code here, to run repeatedly:
}
