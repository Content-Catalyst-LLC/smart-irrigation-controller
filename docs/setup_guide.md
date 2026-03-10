# Setup Guide

## Purpose

This guide explains how to assemble and test the Smart Irrigation Controller prototype.

## Wiring Overview

### Arduino Connections

- `A0` → soil moisture sensor analog output
- `D2` → DHT22 data
- `D7` → relay control
- `5V` → sensor VCC
- `GND` → common ground

### Pump Circuit

- Pump power should be supplied by an external 5V supply
- The relay switches the pump circuit
- Do not power the pump directly from the Arduino

## Build Steps

1. Connect the capacitive soil moisture sensor to `A0`, `5V`, and `GND`
2. Connect the relay module control input to `D7`
3. Connect the optional DHT22 sensor to `D2`, `5V`, and `GND`
4. Wire the pump through the relay using an external 5V supply
5. Upload `smart_irrigation_controller.ino` to the Arduino
6. Open the Serial Monitor at `9600` baud
7. Insert the moisture sensor into soil and observe readings
8. Adjust the dryness threshold after calibration

## Safety Notes

- Keep electrical connections away from water
- Use proper insulation in wet environments
- Confirm relay behavior before connecting the pump
- Some relay modules are active-low and may switch unexpectedly if not initialized correctly

## Validation

Before relying on the prototype, verify:

- dry and wet soil produce clearly different readings
- relay switching is stable
- pump runtime delivers a reasonable amount of water
- sensor placement reflects the target soil region