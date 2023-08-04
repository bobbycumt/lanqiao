#include <IRremote.h>

void setup()
{
  // put your setup code here, to run once:
  IrReceiver.begin(2);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode())
  {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(code,HEX);
    IrReceiver.resume();
  }
}
