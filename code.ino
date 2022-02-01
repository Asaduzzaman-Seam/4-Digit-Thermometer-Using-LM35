#include<SevSeg.h>
SevSeg sevSeg;
unsigned int myTemp;

void setup() {
  Serial.begin(9600);
  byte numDigits = 4;
  byte ccDPins[] = {A0, A1, A2, A3};
  byte segDPins[] = {8,9,10,11,12,13,6,7};

  sevSeg.begin(COMMON_CATHODE, numDigits, ccDPins, segDPins, false, false, false, false);
  sevSeg.setBrightness(100);
  analogReference(INTERNAL);
}

void loop() {
  unsigned long prMillis = millis();
  while( millis() - prMillis < 2000 )
  {
    sevSeg.refreshDisplay();
  }
  myTemp = acqTemp();
  sevSeg.setNumber(myTemp , 2, LOW);

}

unsigned int acqTemp()
{
  float temp = (float) 100*(1.1/1023)*analogRead(A4);
  Serial.print(" Room temperature is - ");
  Serial.print(temp, 2);
  Serial.println(" deg C");
  temp = 100*temp;
  return ((unsigned int)temp);
}
