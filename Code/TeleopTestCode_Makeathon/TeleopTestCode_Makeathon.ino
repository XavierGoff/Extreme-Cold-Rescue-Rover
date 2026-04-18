#include <SPI.h>
#include <RF24.h>
#include <ESP32Servo.h>
#include <stdint.h>

// ================= RADIO =================
RF24 radio(4, 5);   // CE, CSN
const byte address[6] = "06211";

struct Data_Package {
  int16_t xValue;
  int16_t yValue;
};

Data_Package data;

// ================= MOTOR DRIVER OUTPUTS =================
Servo leftDrive;
Servo rightDrive;

// Cytron RC inputs
const int RC1_PIN = 16;
const int RC2_PIN = 17;

const int STOP_US = 1500;
const int MAX_OFFSET = 200;
const int DEADZONE = 30;
const unsigned long SIGNAL_TIMEOUT = 300;

unsigned long lastPacketTime = 0;

// Flip these if direction is wrong
const bool invertX = false;
const bool invertY = true;
const bool invertLeft = false;
const bool invertRight = false;

int clamp255(int v) {
  return constrain(v, -255, 255);
}

int applyDeadzone(int v) {
  if (abs(v) < DEADZONE) return 0;
  return v;
}

int toPulseOffset(int v) {
  return map(v, -255, 255, -MAX_OFFSET, MAX_OFFSET);
}

void stopDrive() {
  leftDrive.writeMicroseconds(STOP_US);
  rightDrive.writeMicroseconds(STOP_US);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== ROBOT TELEOP BOOT ===");

  leftDrive.attach(RC1_PIN, 1000, 2000);
  rightDrive.attach(RC2_PIN, 1000, 2000);

  stopDrive();
  delay(3000);  // let driver initialize at neutral

  if (!radio.begin()) {
    Serial.println("Radio NOT responding!");
    while (1) {
      delay(10);
    }
  }

  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, address);
  radio.startListening();

  lastPacketTime = millis();

  Serial.println("Receiver ready");
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package));
    lastPacketTime = millis();

    int x = clamp255(data.xValue);
    int y = clamp255(data.yValue);

    if (invertX) x = -x;
    if (invertY) y = -y;

    x = applyDeadzone(x);
    y = applyDeadzone(y);

    int leftCmd = y + x;
    int rightCmd = y - x;

    leftCmd = clamp255(leftCmd);
    rightCmd = clamp255(rightCmd);

    if (invertLeft) leftCmd = -leftCmd;
    if (invertRight) rightCmd = -rightCmd;

    int leftPulse = STOP_US + toPulseOffset(leftCmd);
    int rightPulse = STOP_US + toPulseOffset(rightCmd);

    leftDrive.writeMicroseconds(leftPulse);
    rightDrive.writeMicroseconds(rightPulse);

    Serial.print("X: ");
    Serial.print(x);
    Serial.print("  Y: ");
    Serial.print(y);
    Serial.print("  | Lpulse: ");
    Serial.print(leftPulse);
    Serial.print("  Rpulse: ");
    Serial.println(rightPulse);
  } else {
    if (millis() - lastPacketTime > SIGNAL_TIMEOUT) {
      stopDrive();
    }
  }
}