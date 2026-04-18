# System Overview

## Introduction

The system is designed as a modular, wireless ground robot platform capable of remote operation in low-traction environments. It integrates mechanical, electrical, and control subsystems into a cohesive architecture, prioritising robustness and real-time responsiveness over complexity.

---

## System Architecture

The robot is composed of three primary subsystems:

1. **Transmitter (Human Interface)**
2. **Wireless Communication Layer**
3. **Receiver + Actuation System**

These subsystems operate in a continuous loop, enabling real-time teleoperation.

---

## Data Flow

The control pipeline is structured as follows:

```text
Joystick Input → Arduino Nano → nRF24 Transmitter
              → Wireless Link →
ESP32 Receiver → Control Mapping → Motor Driver → Motors
```

* The joystick generates analog signals corresponding to user input.
* These signals are processed and transmitted wirelessly.
* The receiver interprets the data and converts it into motor commands.

---

## Transmitter Subsystem

The transmitter is built around an Arduino Nano and a dual-axis joystick.

Responsibilities:

* Reading analog joystick inputs
* Converting raw values into a normalised control range (-255 to 255)
* Applying a deadzone to eliminate noise around the neutral position
* Packaging and transmitting data via the nRF24 module

This subsystem is intentionally lightweight to minimise latency and complexity.

---

## Communication System

Wireless communication is handled using nRF24L01 modules operating over SPI.

Key characteristics:

* Low-latency communication
* Simple packet-based transmission
* No reliance on external infrastructure (unlike WiFi)

The system transmits compact data packets containing only the required control variables, ensuring fast and reliable updates.

---

## Receiver and Control Subsystem

The receiver is based on an ESP32 microcontroller.

Responsibilities:

* Receiving incoming control packets
* Validating signal timing (failsafe timeout)
* Mapping joystick input into differential motor commands
* Generating PWM signals for the motor driver

A signal timeout mechanism ensures that the robot halts if communication is lost.

---

## Control Strategy

The control system uses a differential drive model:

* Forward/backward motion is controlled by the Y-axis
* Turning is controlled by the X-axis
* Motor commands are generated using a simple mixing algorithm:

```text
Left Motor  = Y + X
Right Motor = Y - X
```

This allows for intuitive control and smooth transitions between motion states.

---

## Power System Integration

The system separates high-current motor power from logic-level electronics:

* Motors are powered directly from the battery
* Control electronics are powered via a regulated supply

This reduces electrical noise and improves system stability.

---

## Summary

The system architecture prioritises:

* Simplicity and reliability
* Real-time control
* Modular expandability

The result is a robust platform that can be extended with additional sensing and autonomy in future iterations.
