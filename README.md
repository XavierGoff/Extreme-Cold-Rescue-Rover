# Extreme Cold Rescue Rover

A tracked rescue robot designed to operate in snowy and unstable terrain, with a focus on low ground pressure, robust mobility, and practical field deployment. This project was developed as a fast-turnaround engineering build, combining mechanical design, drivetrain selection, power system integration, and control architecture into a compact rescue platform.

![Hero Render](images/hero-render.png)

## Overview

This robot was developed to address a simple but difficult problem: how can a small ground robot move effectively across soft snow without sinking, stalling, or becoming unstable?

The project focuses on designing a lightweight tracked platform capable of traversing powdery terrain while carrying its own electronics and drive system. The design process involved balancing traction, footprint area, chassis weight, torque requirements, and manufacturability under tight time and budget constraints.

Rather than treating this as just a remote-controlled vehicle, the project was approached as an engineering system, with attention given to terrain interaction, drivetrain performance, structural layout, and future expandability toward autonomous rescue functionality.

## Key Features

- Tracked drivetrain for improved traction and terrain conformity
- Wide contact area to reduce ground pressure on soft snow
- High-torque drive system for low-speed force output
- Compact chassis designed around integrated electronics and battery packaging
- Modular structure to support iterative redesign and component replacement
- Remote control operation, with future scope for semi-autonomous behaviour

## Engineering Objectives

The main technical goals of the project were:

- Minimise sinking in soft snow by increasing contact area and lowering pressure on the terrain
- Generate sufficient drive torque to maintain motion under resistive snow loading
- Keep overall mass low enough to preserve flotation and reduce drivetrain demand
- Package the electronics cleanly and reliably within the vehicle footprint
- Build a platform that could realistically be expanded into a more capable rescue system

## Design Approach

The design was driven by the interaction between terrain mechanics and drivetrain requirements.

Soft snow presents a major mobility challenge because small wheels or narrow tracks create high local pressure, causing the vehicle to sink and lose usable traction. To address this, the robot uses a tracked architecture with an enlarged footprint, distributing its weight over a greater contact area.

Alongside flotation, the drive system had to be selected for torque rather than top speed. Since snow traversal creates significant rolling and pushing resistance, the drivetrain was designed around high-torque motors capable of moving the platform steadily under load.

The chassis was laid out to keep mass centralised, protect components, and allow quick design iteration as the build evolved.

## Mechanical Design

### Chassis

The robot uses a compact chassis approximately 300 mm × 250 mm in plan, designed to support the drivetrain, electronics, and battery while maintaining a stable centre of mass.

Key design considerations included:

- structural rigidity without unnecessary mass
- sufficient internal space for electronics routing
- accessible mounting points for rapid redesign
- compatibility with 3D printed and fabricated components

### Mobility System

The tracked configuration was chosen over wheels to improve performance on soft terrain.

Advantages of the tracked system include:

- larger contact patch
- reduced ground pressure
- improved traction on loose terrain
- better ability to traverse uneven or partially compacted surfaces

Track width and footprint were treated as major design variables because they directly influence flotation and terrain loading.

## Electronics and Control

The robot integrates a compact control and power architecture designed for reliable drivetrain operation.

Current system elements include:

- microcontroller / receiver interface
- motor driver
- battery power distribution
- switching and protection hardware
- dual drive motor configuration

The control system was selected to prioritise robustness and simplicity in the first build phase, with future scope for more advanced sensing and autonomy.

## Power System

The power system was designed around the demands of the drivetrain, since motor load dominates total energy usage in snow-traversing platforms.

Important design considerations included:

- supplying sufficient current during startup and stall-like conditions
- separating control logic from motor power where necessary
- protecting the system with appropriate switching and fuse selection
- maintaining reasonable runtime without excessive battery mass

## Calculations and Engineering Reasoning

A major part of the project involved validating design decisions analytically rather than selecting components blindly.

The engineering work included:

- estimating ground pressure based on robot mass and contact area
- assessing whether the platform would remain above soft snow rather than digging in
- evaluating torque and drivetrain requirements for snow resistance
- comparing motor options based on speed, torque, and mass trade-offs
- considering the effect of battery and electronics weight on total system performance

Further details are included in the project documents in the [`docs/`](docs/) folder.

## Challenges

Some of the key engineering challenges in this build were:

- balancing torque and weight within a limited budget
- designing for snow performance without overbuilding the chassis
- packaging electronics cleanly in a compact tracked layout
- maintaining modularity while still achieving structural rigidity
- selecting components that were realistic to source and build around quickly

## Future Improvements

Planned next steps include:

- optimised motor torque/speed tradeoff
- improved environmental sealing for wet and cold operation
- sensor integration for terrain awareness and navigation
- use of metal parts for increased lifespan/resiliance
- more rigorous field testing in snow and loose terrain
- semi-autonomous or waypoint-based rescue capability

## Repository Structure

```text
.
├── README.md
├── Cad/
├── Code/
├── Electronics/
├── Images/
├── docs/
