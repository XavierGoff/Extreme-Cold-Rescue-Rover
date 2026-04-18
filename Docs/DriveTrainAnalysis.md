# Drivetrain Analysis

## Overview

The drivetrain was designed to enable reliable motion across soft, low-strength terrain such as powder snow. The primary challenges were maintaining traction while preventing the robot from sinking.

---

## Terrain Interaction

Soft snow behaves as a deformable surface:

* High local pressure causes sinking
* Low pressure allows the robot to remain on top

Therefore, drivetrain design must minimise ground pressure.

---

## Ground Pressure Considerations

Ground pressure is defined as:

```text
Pressure = Weight / Contact Area
```

To reduce pressure:

* Increase contact area
* Reduce total mass

---

## Tracked Configuration

Tracks were selected to maximise contact area.

Advantages:

* Large footprint distributes weight
* Improved traction through continuous contact
* Better performance on uneven surfaces

---

## Trade-offs

Tracked systems introduce:

* Increased mechanical friction
* Higher power requirements
* More complex construction

However, these were acceptable given the terrain requirements.

---

## Torque Requirements

Snow creates significant resistance through:

* compression of material
* ploughing effect at the front of the track

This requires:

* high torque at low speeds
* stable drivetrain output

---

## Motor Selection

Motors were chosen based on:

* torque output rather than speed
* ability to operate under load without stalling

Gear reduction plays a key role in increasing usable torque.

---

## Turning Behaviour

Differential drive introduces:

* skid steering (tracks slide during turns)
* increased resistance during rotation

This was accepted as a trade-off for simplicity.

---

## Weight Distribution

Mass was kept:

* low
* centrally located

This improves:

* stability
* uniform load distribution across tracks

---

## Summary

The drivetrain design prioritises:

* flotation over speed
* torque over efficiency
* simplicity over precision

This results in a system capable of traversing challenging terrain while remaining mechanically feasible to build.
