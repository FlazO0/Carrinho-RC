#include "BluetoothSerial.h"
#include <Arduino.h>

BluetoothSerial serialBT;

// Bluetooth signal store in this variable
char btSignal;

// Initial speed
int Speed = 100;

// Define PWM pins
int enA = 5;
int enB = 23;

// Motor controlling pins
int IN1 = 22;
int IN2 = 21;
int IN3 = 19;
int IN4 = 18;

// PWM frequency and resolution
const int pwmFreq = 5000; // 5 kHz
const int pwmResolution = 8; // 8-bit

void setup() {
  Serial.begin(115200);

  // Bluetooth initialization
  serialBT.begin("CARRINHO ;)");

  // Set pin modes for motor control
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Attach PWM to pins with specified frequency and resolution
  ledcAttach(enA, pwmFreq, pwmResolution); // Attach enA pin with PWM frequency and resolution
  ledcAttach(enB, pwmFreq, pwmResolution); // Attach enB pin with PWM frequency and resolution

  // Initial state of the car
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  while (serialBT.available()) {
    btSignal = serialBT.read();
    
    // Set speed based on Bluetooth signal
    if (btSignal == '0') Speed = 100;
    if (btSignal == '1') Speed = 110;
    if (btSignal == '2') Speed = 120;
    if (btSignal == '3') Speed = 130;
    if (btSignal == '4') Speed = 140;
    if (btSignal == '5') Speed = 150;
    if (btSignal == '6') Speed = 180;
    if (btSignal == '7') Speed = 200;
    if (btSignal == '8') Speed = 220;
    if (btSignal == '9') Speed = 240;
    if (btSignal == 'q') Speed = 255;

    // Output signal to Serial Monitor
    Serial.println(btSignal);
    
    // Control motor direction based on Bluetooth signal
    if (btSignal == 'B') {
      backward();
    } else if (btSignal == 'F') {
      forward();
    } else if (btSignal == 'L') {
      turnLeft();  // Adjusted turning left behavior
    } else if (btSignal == 'R') {
      turnRight(); // Adjusted turning right behavior
    } else if (btSignal == 'S') {
      stop();
    }
  }
}

// Function to move motor backward
void backward() {
  ledcWrite(enA, Speed);
  ledcWrite(enB, Speed);

  digitalWrite(IN1, LOW);  // Motor A (left) spins backward
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  // Motor B (right) spins backward
  digitalWrite(IN4, HIGH);
}

// Function to move motor forward
void forward() {
  ledcWrite(enA, Speed);
  ledcWrite(enB, Speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to turn left (disable right motor, only left motor moves)
void turnLeft() {
  // Stop right motor, keep left motor running
  ledcWrite(enA, Speed);  // Keep left motor running
  ledcWrite(enB, 0);      // Stop right motor

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  // Stop right motor
}

// Function to turn right (disable left motor, only right motor moves)
void turnRight() {
  // Stop left motor, keep right motor running
  ledcWrite(enA, 0);      // Stop left motor
  ledcWrite(enB, Speed);  // Keep right motor running

  digitalWrite(IN1, LOW);  // Stop left motor
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  // Right motor moves forward
}

// Function to stop both motors
void stop() {
  ledcWrite(enA, 0); // Set PWM value to 0 to stop the motor
  ledcWrite(enB, 0); // Set PWM value to 0 to stop the motor

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
