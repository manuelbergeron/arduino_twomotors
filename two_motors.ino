#include <AFMotor.h>

// Codes for the motor function.
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

AF_DCMotor motor1(2, MOTOR34_1KHZ);
AF_DCMotor motor2(1, MOTOR34_1KHZ);
int valueX;
int valueY;
int valueF;
int middle1 = 490; 
int middle2 = 525;
int speedX = 0;
int speedY = 0;
int speedF = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Mount driving");
   motor1.setSpeed(0);
}

void loop() {
 
  valueX = analogRead(5); 
  valueY = analogRead(4);
  valueF = analogRead(3);
 /* Serial.println("NEW LINE");
  Serial.println(valueY);
  Serial.println(valueX);
  Serial.println(valueF);
  delay(1000);
  */
  
  if (valueX > middle1 && valueX < middle2) {
    if (valueF > 0) {
      speedF = valueF / 50;
       motor1.setSpeed(speedF);
       motor1.run(FORWARD);
    } else {
       motor1.setSpeed(0);
       motor1.run(RELEASE);
    }
  } else if (valueX > middle2) {
     //On avance
     speedX = (valueX - middle2) / 2;
     motor1.setSpeed(speedX);
     motor1.run(BACKWARD);
  } else if (valueX < middle1) {
    //on recule
     speedX = abs(valueX - middle1) / 2;
     motor1.setSpeed(speedX);
     motor1.run(FORWARD);
  }
  
  if (valueY > middle1 && valueY < middle2) {
     motor2.setSpeed(0);
     motor2.run(RELEASE);
  } else if (valueY > middle2) {
     //On avance
     speedY = (valueY - middle2) / 2;
     motor2.setSpeed(speedY);
     motor2.run(BACKWARD);
  } else if (valueY < middle1) {
     //on recule
     speedY = abs(valueY - middle1) / 2;
     motor2.setSpeed(speedY);
     motor2.run(FORWARD);
  }
}


