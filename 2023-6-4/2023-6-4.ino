#include <TM1650.h>
#include <Wire.h>

TM1650 seg;
char *s = " 000";
void setup()
{
  // put your setup code here, to run once:
  Wire.begin();
  seg.init();
  seg.displayOn();
  seg.setBrightness(7);
  seg.displayString(" 000");
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 9; i++)
  {
    for (int j = 0; j <= 9; j++)
    {
      delay(100);
      sprintf(s, " %d%d0", i, j);
      seg.displayString(s);
    }
  }
  for (int i = 10; i <= 14; i++)
  {
    for (int j = 0; j <= 9; j++)
    {
      delay(100);
      sprintf(s, "%d%d0", i, j);
      seg.displayString(s);
    }
  }
  seg.displayString("1500");
  while (1)
    ;
}
