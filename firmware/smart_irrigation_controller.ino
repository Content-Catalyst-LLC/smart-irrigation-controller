#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define SOIL_PIN A0
#define RELAY_PIN 7

#define DRY_THRESHOLD 650
#define SAMPLE_COUNT 10

const unsigned long WATERING_INTERVAL_MS = 300000UL;
const unsigned long PUMP_RUNTIME_MS = 3000UL;
const unsigned long SAMPLE_DELAY_MS = 60000UL;

DHT dht(DHTPIN, DHTTYPE);
unsigned long lastWateringTime = 0;

int readSoilMoistureAverage() {
  long total = 0;
  for (int i = 0; i < SAMPLE_COUNT; i++) {
    total += analogRead(SOIL_PIN);
    delay(10);
  }
  return total / SAMPLE_COUNT;
}

bool canWaterNow(unsigned long currentTime) {
  return (currentTime - lastWateringTime) >= WATERING_INTERVAL_MS;
}

void setPumpState(bool on) {
  digitalWrite(RELAY_PIN, on ? LOW : HIGH);
}

void runPumpCycle(unsigned long currentTime) {
  Serial.println("Soil dry. Activating irrigation cycle.");
  setPumpState(true);
  delay(PUMP_RUNTIME_MS);
  setPumpState(false);
  lastWateringTime = currentTime;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  setPumpState(false);
}

void loop() {
  unsigned long now = millis();
  int soil = readSoilMoistureAverage();

  Serial.print("Soil: ");
  Serial.println(soil);

  if (soil > DRY_THRESHOLD && canWaterNow(now)) {
    runPumpCycle(now);
  }

  delay(SAMPLE_DELAY_MS);
}
