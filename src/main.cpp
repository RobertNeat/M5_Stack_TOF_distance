//basic TOF distance measuring - the object distance from the sensor
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup() {
  Serial.begin(115200);
  Wire.begin(26, 32); // SDA, SCL

  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  sensor.startContinuous();
}

void loop() {
  Serial.print("Distance: ");
  Serial.print(sensor.readRangeContinuousMillimeters());
  Serial.println(" mm");

  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }

  delay(1000);
}
