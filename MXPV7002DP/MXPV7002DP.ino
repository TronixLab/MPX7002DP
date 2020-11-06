#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);

int16_t adc2;

float multiplier = 0.1875F;               
float Pc = 0.00F;
float Vout = 0.00F;

void setup() {
  Serial.begin(9600);
  ads.begin();
  ads.setGain(GAIN_TWOTHIRDS);
}

void loop() {
  adc2 = ads.readADC_SingleEnded(2);
  Vout = adc2 * multiplier;

  Pc = map(Vout, 36, 4947, -2000, 2000);
  Pc = constrain(Pc, -2000, 2000);
  Pc = Pc / 1000;

  Serial.print("Vout: ");
  Serial.print(Vout); Serial.print("mV   ");
  Serial.print("Pc: ");
  Serial.print(Pc); Serial.print("kPa   ");
  Serial.println();
  delay(1);
}
