# Electronics Overview

## Introduction

The electronics system integrates control, communication, and power delivery for the robot. It is designed to provide reliable motor actuation while maintaining stable wireless communication under electrically noisy conditions.

---

## System Components

The system consists of:

* ESP32 (receiver and control unit)
* Arduino Nano (transmitter)
* nRF24L01 modules (wireless communication)
* Motor driver (RC PWM input)
* LiPo battery
* Buck converter for regulated logic power

---

## Architecture

The electronics are divided into two main subsystems:

### 1. Control & Communication

* Wireless link using nRF24 modules
* Joystick input processed by Arduino Nano
* Control data transmitted to ESP32

### 2. Power & Actuation

* Motor driver powered directly from battery
* ESP32 and RF modules powered via regulated 5V supply
* PWM signals used to control motor speed and direction

---

## Design Priorities

The electronics were designed with the following priorities:

* Stable wireless communication
* Noise isolation between motors and logic
* Simple and reliable control architecture
* Ease of debugging and modification

---

## Key Challenges

During development, several issues were encountered:

* RF instability due to power noise
* ESP32 serial corruption under load
* Sensitivity of SPI communication to wiring and pin selection

These were addressed through improved grounding, power filtering, and pin configuration.

---

## Summary

The final electronics system provides a stable platform for wireless teleoperation, while remaining modular and extensible for future upgrades such as sensors or autonomous control.
