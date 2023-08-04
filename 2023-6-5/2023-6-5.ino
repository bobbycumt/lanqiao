#include <IRremote.h>
unsigned long code;
void setup()
{
  // put your setup code here, to run once:
  IrReceiver.begin(2);
  Serial.begin(9600);
  Serial.println("123");
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode())
  {
    code = IrReceiver.decodedIRData.decodedRawData;
    code>>=16;
    Serial.println(code,HEX);
    IrReceiver.resume();
  }  
  if(code==0xf310)
  {
    Serial.println("1");
  }
}
