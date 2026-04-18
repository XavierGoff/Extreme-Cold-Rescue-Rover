#include <ESP32Servo.h>

Servo leftDrive;
Servo rightDrive;

// ESP32 pins going to Cytron MDDRC10 RC inputs
const int RC1_PIN = 16;   // driver RC1
const int RC2_PIN = 17;   // driver RC2

const int STOP_US = 1500;
const int DRIVE_US = 1700;
const int REV_US   = 1300;

void setDrive(int leftUs, int rightUs) {
  leftDrive.writeMicroseconds(leftUs);
  rightDrive.writeMicroseconds(rightUs);

  Serial.print("Left: ");
  Serial.print(leftUs);
  Serial.print("  Right: ");
  Serial.println(rightUs);
}

void stopDrive() {
  setDrive(STOP_US, STOP_US);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== MDDRC10 AUTONOMOUS TEST ===");

  leftDrive.attach(RC1_PIN, 1000, 2000);
  rightDrive.attach(RC2_PIN, 1000, 2000);

  stopDrive();
  Serial.println("Neutral for arming...");
  delay(3000);
}

void loop() {
  Serial.println("Forward");
  setDrive(DRIVE_US, DRIVE_US);
  delay(2000);

  stopDrive();
  delay(500);

  Serial.println("Turn right");
  setDrive(DRIVE_US, REV_US);
  delay(1000);

  stopDrive();
  delay(500);

  Serial.println("Turn left");
  setDrive(REV_US, DRIVE_US);
  delay(1000);

  stopDrive();
  delay(500);

  Serial.println("Backward");
  setDrive(REV_US, REV_US);
  delay(2000);

  Serial.println("Stop");
  stopDrive();
  delay(4000);
}