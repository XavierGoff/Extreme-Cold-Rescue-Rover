# Design Decisions

## Overview

This project was driven by a series of practical engineering trade-offs, balancing performance, complexity, cost, and build time. Each major component was selected based on its suitability for the specific constraints of snow traversal and rapid prototyping.

---

## Tracked vs Wheeled Locomotion

### Decision: Tracked drivetrain

Tracked locomotion was selected over wheels due to its superior performance in soft terrain.

**Reasons:**

* Increased contact area reduces ground pressure
* Improved traction on loose or uneven surfaces
* Better load distribution across the terrain

**Trade-offs:**

* Increased mechanical complexity
* Higher friction losses compared to wheels
* More difficult turning dynamics

Despite these drawbacks, tracks were necessary to achieve reliable mobility in snow.

---

## Microcontroller Selection

### Decision: ESP32 (receiver), Arduino Nano (transmitter)

A dual-microcontroller architecture was used.

**ESP32 (receiver):**

* Greater processing capability
* More flexible GPIO
* Better suited for handling communication and motor control simultaneously

**Arduino Nano (transmitter):**

* Simple and reliable
* Sufficient for reading joystick inputs
* Lower complexity for the user interface side

This separation reduces system coupling and simplifies debugging.

---

## Communication Protocol

### Decision: nRF24L01 over Bluetooth/WiFi

**Reasons:**

* Lower latency than WiFi-based solutions
* Simpler communication model (no pairing or network setup)
* More predictable performance in isolated environments

**Trade-offs:**

* Less range than some long-range protocols
* Requires careful power and wiring management

The nRF modules provided a good balance between simplicity and responsiveness.

---

## Motor Driver Selection

### Decision: RC-style motor driver (PWM input)

**Reasons:**

* Simplifies control (servo-style signals)
* Eliminates need for custom H-bridge logic
* Reliable and well-tested interface

**Trade-offs:**

* Less control granularity compared to direct PWM + direction control
* Requires calibration around neutral (1500 µs)

---

## Power Architecture

### Decision: Separate motor and logic power paths

**Reasons:**

* Motors introduce electrical noise and voltage drops
* Logic systems (ESP32, RF module) require stable voltage

By separating these paths, system stability was significantly improved.

---

## Control Strategy

### Decision: Differential drive mixing

**Reasons:**

* Simple to implement
* Intuitive user control
* No need for complex kinematic modelling

This approach allows the robot to be controlled effectively with minimal computation.

---

## System Complexity vs Reliability

A key guiding principle was:

> Prioritise reliability over complexity in early iterations

Rather than implementing advanced features (autonomy, sensors), the focus was placed on:

* stable communication
* robust power delivery
* predictable mechanical performance

This ensured a working system before adding additional layers of complexity.

---

## Summary

The design decisions reflect a pragmatic approach:

* Choose solutions that are **good enough and reliable**
* Avoid unnecessary complexity in early builds
* Prioritise system integration over individual component optimisation

These principles enabled rapid development while maintaining engineering rigor.
