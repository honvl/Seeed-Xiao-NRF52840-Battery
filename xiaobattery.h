#include <Arduino.h>
#include <bluefruit.h>

#define BAT_HIGH_CHARGE 22  // HIGH for 50mA, LOW for 100mA
#define BAT_CHARGE_STATE 23 // LOW for charging, HIGH not charging

class Xiao {
public:
  Xiao();
  float GetBatteryVoltage();
  bool IsChargingBattery();
};

Xiao::Xiao() {
  pinMode(VBAT_ENABLE, OUTPUT);
  pinMode(BAT_CHARGE_STATE, INPUT);

  digitalWrite(BAT_HIGH_CHARGE, HIGH); // charge with 100mA
}

#define VBAT_PER_LBS (0.003515625F) // 3.6 reference and 10 bit resolution

float Xiao::GetBatteryVoltage() {
  digitalWrite(VBAT_ENABLE, LOW);

  uint32_t adcCount = analogRead(PIN_VBAT);
  float adcVoltage = adcCount * VBAT_PER_LBS;
  float vBat = adcVoltage * (1510.0 / 510.0);

  digitalWrite(VBAT_ENABLE, HIGH);

  return vBat;
}

bool Xiao::IsChargingBattery() { return digitalRead(BAT_CHARGE_STATE) == LOW; }