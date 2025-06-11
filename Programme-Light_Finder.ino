#include <Servo.h>
 
Servo myservo;
const int droite = A0, gauche = A1, servoPin = 9;
int signaldroit, signalgauche;
 
void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
}
 
void loop() {
  signaldroit = analogRead(droite);
  signalgauche = analogRead(gauche);
  Serial.print("droite: "); Serial.print(signaldroit);
  Serial.print(" gauche: "); Serial.println(signalgauche);
 
  int difference = signaldroit - signalgauche;
  if (abs(difference) > 10) {
    int servoPosition = constrain(myservo.read() + (difference > 0 ? 1 : -1), 0, 180);
    myservo.write(servoPosition);
    delay(100);
  }
}