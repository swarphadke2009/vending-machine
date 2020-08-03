#include<Servo.h>
Servo s;
const int ledPin = 13;
const int buzzerPin = 12;
const int ldrPin = A0;
const int laserPin = 7;
void setup () {
  s.attach(9);
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(ldrPin, INPUT);
pinMode( laserPin , OUTPUT);
digitalWrite( laserPin , HIGH);
}


void loop() {
int ldrStatus = analogRead(ldrPin);
if (ldrStatus > 100) {
  s.write(200);
tone(buzzerPin, 100);
digitalWrite(ledPin, HIGH);
delay(100);
noTone(buzzerPin);
digitalWrite(ledPin, LOW);
delay(100);
Serial.println(" ALARM ACTIVATED ");
}
else {
  s.write(0);
noTone(buzzerPin);
digitalWrite(ledPin, LOW);
Serial.println("ALARM DEACTIVATED");
}
Serial.println( ldrStatus );
//delay(10);
}
