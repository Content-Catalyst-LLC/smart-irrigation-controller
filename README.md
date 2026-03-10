# Smart Irrigation Controller

An Arduino-based smart irrigation controller that uses a capacitive soil moisture sensor and relay-controlled pump to water only when the soil is dry.

This project is designed as a reproducible prototype for engineers, students, and researchers interested in embedded sensing, control systems, and water-efficient irrigation.

## Overview

Traditional irrigation systems often rely on fixed timers rather than measured soil conditions. This prototype replaces timer-based watering with a simple feedback loop:

Soil Sensor → Arduino → Decision Logic → Relay → Pump → Soil

The controller reads soil moisture, compares the reading to a calibrated dryness threshold, and activates irrigation only when needed.

## Features

- Capacitive soil moisture sensing
- Relay-controlled irrigation pump
- Configurable dryness threshold
- Sample averaging for noise reduction
- Watering lockout interval to prevent rapid repeat cycles
- Optional DHT22 environmental sensing support

## Repository Structure

- `firmware/` — Arduino firmware
- `docs/` — setup and calibration documentation
- `data/` — example sensor readings
- `hardware/` — wiring diagrams and schematics
- `BOM.csv` — bill of materials

## Hardware

- Arduino Uno or Nano
- Capacitive soil moisture sensor
- 5V relay module
- 5V submersible pump
- External 5V power supply for pump
- Breadboard and jumper wires
- Optional DHT22 sensor

## Basic Operation

1. Read soil moisture from analog pin A0
2. Average multiple samples
3. Compare value to a dryness threshold
4. If dry, activate relay and run pump briefly
5. Wait for lockout interval before allowing another watering cycle

## Notes

This is a prototype reference design, not a field-hardened agricultural controller. Engineers adapting it for real deployment should validate:

- sensor calibration
- pump duty cycle
- enclosure and moisture protection
- long-term sensor drift
- electrical isolation and power stability

## License

This project is released under the MIT License.

See `LICENSE` for details.