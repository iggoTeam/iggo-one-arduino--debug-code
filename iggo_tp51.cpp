#include <Arduino.h>
#include <Wire.h>
#include "tp51.h"
#define POWER PD5

iggo_tp51 tp51;

void setup()
{
  Serial.begin(250000);
  pinMode(POWER, OUTPUT);
  digitalWrite(POWER, 1);
    Serial.println("iggo_tp51 Arduino Test");
    tp51.begin(0x40); // default I2C address is 0x40 and 14-bit measurement resolution
    Serial.print("firmware revision: ");
    switch (tp51.readFirmwareVersion())
    {
    case 0xFF:
        Serial.println("version 1.0");
        break;
    case 0x20:
        Serial.println("version 2.0");
        break;
    default:
        Serial.println("unknow");
            break;
    }
    tp51.setResolution(14) // where num = 14,12,13,11-bits, default is 14
}
void loop()
{
    Serial.print("T=");
    Serial.print(tp51.readTemperature());
    Serial.println("°C");
    delay(300);
}
