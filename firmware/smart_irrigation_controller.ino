#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define SOIL_PIN A0
#define RELAY_PIN 7

#define DRY_THRESHOLD 650
#define SAMPLE_COUNT 10

const unsigned long WATERING_INTERVAL_MS = 300000UL;   // 5 minutes
const unsigned long PUMP_RUNTIME_MS      = 3000UL;     // 3 seconds
const unsigned long SAMPLE_DELAY_MS      = 60000UL;    // 1 minute
const float HUMIDITY_CUTOFF              = 80.0;

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
  // Active-low relay assumed
  digitalWrite(RELAY_PIN, on ? LOW : HIGH);
}

void runPumpCycle(unsigned long currentTime) {
  Serial.println("Soil dry. Activating irrigation cycle.");
  setPumpState(true);
  delay(PUMP_RUNTIME_MS);
  setPumpState(false);
  lastWateringTime = currentTime;
}

void printTelemetry(int soil, float temperature, float humidity) {
  Serial.print("Soil Moisture: ");
  Serial.print(soil);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  setPumpState(false);

  Serial.println("Smart Irrigation Controller Starting");
  Serial.print("Dry threshold: ");
  Serial.println(DRY_THRESHOLD);
}

void loop() {
  unsigned long now = millis();

  int soil = readSoilMoistureAverage();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Sensor read error: DHT22 returned invalid data.");
    delay(SAMPLE_DELAY_MS);
    return;
  }

  printTelemetry(soil, temperature, humidity);

  if (soil > DRY_THRESHOLD && humidity < HUMIDITY_CUTOFF && canWaterNow(now)) {
    runPumpCycle(now);
  } else {
    Serial.println("No watering cycle triggered.");
  }

  delay(SAMPLE_DELAY_MS);
}