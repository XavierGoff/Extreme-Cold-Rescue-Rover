#include <SPI.h>
#include <RF24.h>
#include <stdint.h>

RF24 radio(4, 21);   // CE, CSN
const byte address[6] = "06211";

struct Data_Package {
  int16_t xValue;
  int16_t yValue;
};

Data_Package data;

const int xPin = 34;   // joystick left/right
const int yPin = 35;   // joystick forward/back

const int DEADZONE = 25;

int readAxis(int pin) {
  int raw = analogRead(pin);                 // 0 to 4095
  int val = map(raw, 0, 4095, -255, 255);    // convert to -255 to 255

  if (abs(val) < DEADZONE) val = 0;
  return constrain(val, -255, 255);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== TRANSMITTER BOOT ===");

  if (!radio.begin()) {
    Serial.println("Radio NOT responding!");
    while (1) {
      delay(10);
    }
  }

  radio.setPALevel(RF24_PA_MIN);
  radio.openWritingPipe(address);
  radio.stopListening();

  Serial.println("Transmitter ready");
}

void loop() {
  data.xValue = readAxis(xPin);
  data.yValue = readAxis(yPin);

  bool ok = radio.write(&data, sizeof(Data_Package));

  Serial.print("X: ");
  Serial.print(data.xValue);
  Serial.print("  Y: ");
  Serial.print(data.yValue);
  Serial.print("  | sent: ");
  Serial.println(ok ? "YES" : "NO");

  delay(40);
}