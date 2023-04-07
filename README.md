# Seeed-Xiao-NRF52840-Battery
Arduino library to sense Seeed Xiao NRF52840 Battery voltage or charging state on non-Mbed 1.0.0 firmware

Examples:
```
#include <Arduino.h>
#include <bluefruit.h>
#include <xiaobattery.h>

Xiao battery;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
// Serial.println(battery.IsChargingBattery());
Serial.println(battery.GetBatteryVoltage());
}
```
