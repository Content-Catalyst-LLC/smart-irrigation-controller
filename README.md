# Smart Irrigation Controller

An Arduino-based smart irrigation controller that uses a capacitive soil moisture sensor and relay-controlled pump to water only when the soil is dry.

This project is designed as a reproducible prototype for engineers, students, and researchers interested in embedded sensing, control systems, and water-efficient irrigation.

## Overview

Traditional irrigation systems often rely on fixed timers rather than measured soil conditions. This prototype replaces timer-based watering with a simple feedback loop:

Soil Sensor → Arduino → Decision Logic → Relay → Pump → Soil

## Repository Structure

firmware/ → Arduino code  
docs/ → setup and calibration documentation  
data/ → example sensor readings  
hardware/ → wiring diagrams and schematics  
BOM.csv → bill of materials

## Hardware

Arduino Uno or Nano  
Capacitive soil moisture sensor  
5V relay module  
5V submersible pump  
External 5V pump supply

## License

MIT License
