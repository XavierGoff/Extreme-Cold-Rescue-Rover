# CAD

## Overview

This folder contains the mechanical design files for the robot, including structural components, drivetrain layout, and full assembly models.

The CAD work focuses on creating a compact, lightweight chassis capable of supporting a tracked drivetrain while housing the electronics and power system.

---

## Structure

```text
CAD/
├── 3D Printed Parts/
├── Laser Cut Parts/
├── Main Assembly/
```

---

## Design Approach

The mechanical design was developed with the following priorities:

* Low overall mass to improve flotation on soft terrain
* Sufficient structural rigidity to support drivetrain loads
* Efficient packaging of electronics within a compact footprint
* Modularity to allow rapid iteration and redesign

---

## Chassis Design

The chassis is approximately 300 mm × 250 mm in plan and serves as the central structure for:

* Motor mounting
* Track support
* Electronics integration
* Battery placement

The layout aims to keep mass centralised and maintain a stable centre of gravity.

---

## Drivetrain Integration

The CAD model incorporates a tracked system designed to maximise ground contact area.

Key considerations:

* Track width and footprint for reduced ground pressure
* Motor placement for efficient power transmission
* Clearance for debris and snow accumulation

---

## Manufacturing Methods

The design is intended for rapid prototyping using:

* **3D printing (FDM)** for custom components
* **Laser cutting** for flat structural parts
* Standard fasteners (M3 hardware) for assembly

---

## Assembly

The `Main Assembly` folder contains the full system model, showing:

* Component placement
* Mounting relationships
* Overall packaging of the robot

This assembly is used to verify fit, clearances, and integration between subsystems.

---

## Notes

* Parts are designed with tolerances suitable for typical FDM printers
* Fillets and chamfers are used where appropriate to reduce stress concentrations
* The design supports iterative updates without requiring a full rebuild

---

## Future Improvements

* Increased use of metal components for durability
* Improved sealing for wet and cold environments
* Optimisation of track geometry
* Refined mounting solutions for electronics

---

## Summary

The CAD design provides a practical and adaptable mechanical foundation for the robot, balancing performance, manufacturability, and ease of iteration.
