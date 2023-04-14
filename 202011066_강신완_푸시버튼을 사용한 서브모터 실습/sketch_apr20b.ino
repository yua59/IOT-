#include <Servo.h>
Servo myServo;
int motorPin = 12;
int pushPin = 7;
int angle = 90;
int state=0;

void setup() {
  myServo.attach(motorPin);
  pinMode(pushPin, INPUT);
  Serial.begin(9600);
  Serial.println("Enter the push button.");

  // put your setup code here, to run once:

}

void loop() {
  if (digitalRead(pushPin) == HIGH){
    if (state == 0) { 
      angle += 1; // 각도를 1도씩 증가
      if (angle>=180) state = 1; // 회전 방향을 반시계 방향으로 전환
      myServo.write(angle); // angle 값을 서보에게 전달하여 기록
      delay(10);
      Serial.println(angle); // 현재 각도를 시리얼 모니터에 표시
    }
    else { 
      angle -= 1;
      if (angle<=0) state = 0; // 회전 방향을 시계 방향으로 전환
    myServo.write(angle);
    delay(10);
    Serial.println(angle);
    }
  }

  // put your main code here, to run repeatedly:

}
