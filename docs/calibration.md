# Calibration Guide

## Why Calibration Matters

Capacitive soil moisture sensors do not provide an absolute soil water content value. Their analog output depends on:

- soil type
- salinity
- temperature
- container geometry
- insertion depth
- local water distribution

Calibration is therefore required for each build.

## Procedure

1. Insert the sensor into clearly wet soil
2. Record the analog reading
3. Insert the sensor into moderately moist soil
4. Record the analog reading
5. Insert the sensor into dry soil
6. Record the analog reading
7. Select a dryness threshold based on the desired watering behavior

## Example

- Wet soil: `350`
- Moist soil: `500`
- Dry soil: `750`
- Suggested threshold: `650`

## Notes

- Recalibrate if soil type changes
- Recalibrate if sensor depth changes
- Validate threshold choice over several watering cycles
- A single threshold may not generalize well across all plant types or soil conditions