<details>
<summary><strong>Clinoscopio – Project Overview</strong></summary>

# Clinoscopio

A low-cost, 3D-printed clinoscope for plant growth and gravitropism experiments.

Clinoscopio is designed to be simple to build, easy to reproduce, and accessible, while still providing a motion profile suitable for gravity-averaging experiments.

---

## Materials

- 3D printed parts (all structural components)
- 1 stepper motor
- Stepper motor driver of choice

No additional mechanical components are required.

---

## Control and Electronics

- Control code is provided for:
  - Arduino
  - ESP32
- Multiple clinoscopes can be daisy-chained
- A single controller can operate multiple units simultaneously

---

## Motion and Mechanical Design

- Single-motor design
- Motion transmitted through a moving two-gear system
- Snap-fit assembly (no screws required)

The rotation pattern is calculated such that, over one full cycle:
- The integral of gravity along all axes is equal to zero
- The variance of gravity is equal on all axes

One full cycle consists of five rotations of the main axle.

---

## Assembly

- Fully snap-fit construction
- No assembly video is available yet (planned for a future update)

---

## Status

This project is under active development.  
This README is temporary and will be expanded with additional documentation and media.

</details>
