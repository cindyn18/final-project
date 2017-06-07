/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo2; 
Servo myservo3; 
boolean rotation = false;

int pos = 0;    // variable to store the servo position

int sensorValue = 0; 
const int photoPin = A3;  // Analog input pin that the potentiometer is attached to
const int servoPin1 = 5; // Analog output pin that the LED is attached to
const int servoPin2 = 10; // Analog output pin that the LED is attached to
const int servoPin3 = 19; // Analog output pin that the LED is attached to

void setup() {
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(servoPin3);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(photoPin);
  while(sensorValue < 60) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    if(rotation == false && pos < 180) {
      pos++;
      if(pos == 180) {
        rotation = true;
      }
    }
    if(rotation == true && pos > 0) {
      pos--;
      if(pos == 0) {
        rotation = false;
      }
    } 
    delay(15);
    sensorValue = analogRead(photoPin);
  }
}

