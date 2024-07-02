#include "SoftwareSerial.h"
#include <DFPlayerMini_Fast.h>

// Ultasonic pins
const int frontTrigPin = 2;
const int frontEchoPin = 3;
const int leftTrigPin = 4;
const int leftEchoPin = 5;
const int rightTrigPin = 6;
const int rightEchoPin = 7;

// Initialize variable
long frontDuration, leftDuration, rightDuration;
int frontDistance, leftDistance, rightDistance;

// DFPlayer mini pins
static const uint8_t PIN_MP3_TX = 8; 
static const uint8_t PIN_MP3_RX = 9; 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFPlayerMini_Fast player;

void setup() {
  pinMode(frontTrigPin, OUTPUT); // Set frontTrigPin As Output
  pinMode(frontEchoPin, INPUT); // Set frontEchoPin As Input
  pinMode(leftTrigPin, OUTPUT); // Set leftTrigPin As Output
  pinMode(leftEchoPin, INPUT); // Set leftEchoPin As Input
  pinMode(rightTrigPin, OUTPUT); // Set rightTrigPin As Output
  pinMode(rightEchoPin, INPUT); // Set rightEchoPin As Input
  
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);
}

void loop() {
  // Front sensor
  digitalWrite(frontTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTrigPin, LOW);
  frontDuration = pulseIn(frontEchoPin, HIGH);
  frontDistance = frontDuration * 0.034 / 2;
  
  // Left sensor
  digitalWrite(leftTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTrigPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);
  leftDistance = leftDuration * 0.034 / 2;
  
  // Right sensor
  digitalWrite(rightTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTrigPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);
  rightDistance = rightDuration * 0.034 / 2;

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    player.volume(30);
    if(player.isPlaying() == false){
      // Set distance
      if (frontDistance < 110 && leftDistance < 90) {
        player.play(1);
        Serial.print("Front sensor: ");
        Serial.println(frontDistance);
        Serial.print("Left sensor: ");
        Serial.println(leftDistance);
      }
      else if (frontDistance < 110 && rightDistance < 90) {
        player.play(2);
        Serial.print("Front sensor: ");
        Serial.println(frontDistance);
        Serial.print("Right sensor: ");
        Serial.println(rightDistance);
      }
      else if (leftDistance < 90 && rightDistance < 90){
        player.play(3);
        Serial.print("Left sensor: ");
        Serial.println(leftDistance);
        Serial.print("Right sensor: ");
        Serial.println(rightDistance);
      }
      else if (frontDistance < 110) {
        player.play(4);
        Serial.print("Front sensor: ");
        Serial.println(frontDistance);
      } 
      else if (leftDistance < 90) {
        player.play(5);
        Serial.print("Left sensor: ");
        Serial.println(leftDistance);
      }
      else if (rightDistance < 90) {
        player.play(6);
        Serial.print("Right sensor: ");
        Serial.println(rightDistance);
      }

      else {
        Serial.print("Front sensor: ");
        Serial.println(frontDistance);
        Serial.print("Left sensor: ");
        Serial.println(leftDistance);
        Serial.print("Right sensor: ");
        Serial.println(rightDistance);
      }
    }
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
  // Sensor read delay
  delay(300);
}
