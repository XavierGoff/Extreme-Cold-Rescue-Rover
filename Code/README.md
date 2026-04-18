# Code

## Overview

This folder contains the embedded code used to operate the robot’s wireless control system. The firmware is split into two independent components:

* **Transmitter (Arduino Nano)** — reads joystick input and sends control data
* **Receiver (ESP32)** — receives data and drives the motors

The system uses nRF24L01 modules for low-latency wireless communication.

---

## Structure

```text
Firmware/
├── ESP32_Receiver/
│   └── main.ino
├── Nano_Transmitter/
│   └── main.ino
```

---

## ESP32 Receiver

The ESP32 acts as the main control unit on the robot.

### Responsibilities:

* Receive wireless packets from the transmitter
* Interpret joystick inputs
* Apply control logic (differential drive mixing)
* Generate PWM signals for the motor driver
* Implement failsafe behaviour if signal is lost

### Key Features:

* Differential drive mapping (Y ± X)
* Deadzone filtering
* Signal timeout failsafe
* Servo-style PWM output (RC motor driver compatible)

---

## Arduino Nano Transmitter

The transmitter reads user input and sends it wirelessly.

### Responsibilities:

* Read analog joystick inputs
* Map raw values to a usable control range (-255 to 255)
* Apply deadzone filtering to remove noise
* Transmit data packets via nRF24

### Key Features:

* Lightweight control loop
* Consistent update rate (~20–25 Hz)
* Minimal processing to reduce latency

---

## Communication Protocol

Both transmitter and receiver share a common data structure:

```cpp
struct Data_Package {
  int16_t xValue;
  int16_t yValue;
};
```

* `xValue` → turning input
* `yValue` → forward/backward input

Communication is handled using the RF24 library over SPI.

---

## Dependencies

* RF24 library
* SPI library
* ESP32Servo (receiver only)

---

## Upload Instructions

### ESP32:

* Select correct ESP32 board in Arduino IDE
* Ensure correct COM port is selected
* Upload receiver code

### Arduino Nano:

* Select Arduino Nano board
* Choose correct processor (ATmega328P / Old Bootloader if needed)
* Upload transmitter code

---

## Notes

* Both devices must use the same RF address
* SPI wiring must be correct for communication to work
* Power stability is critical for reliable operation

---

## Summary

The firmware is designed to be simple, robust, and responsive, providing a solid foundation for real-time teleoperation while remaining extensible for future features such as autonomy or sensor integration.
