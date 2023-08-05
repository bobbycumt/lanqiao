#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32, 16, 2);
int n, c = 0, i;
char s[20];
void setup()
{
  // put your setup code here, to run once:
  for (int i = 5; i <= 7; i++)
    pinMode(i, OUTPUT);
  for (int i = 5; i <= 7; i++)
    digitalWrite(i, 1);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(39, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(3000);
  lcd.clear();
  lcd.print("ready go!");
  for (int i = 5; i <= 7; i++)
    analogWrite(i, 255);
  n = random(5, 8);
  switch (n)
  {
  case 5:
    /* code */
    i = 0;
    digitalWrite(6, 1);
    digitalWrite(5, 0);
    digitalWrite(7, 1);
    delay(1000);
    while (i <= 10)
    {
      if (digitalRead(39))
      {
        c++;
        lcd.clear();
        sprintf(s, "good job!x %d", c);
        lcd.print(s);
        break;
      }
      else if (analogRead(A6) <= 500 or (analogRead(A6) >= 600 and analogRead(A6) <= 1023))
      {
        lcd.clear();
        lcd.print("come on!!!");
      }
      i++;
      delay(300);
    }
    break;
  case 6:
    /* code */
    i = 0;
    digitalWrite(6, 0);
    digitalWrite(5, 1);
    digitalWrite(7, 1);
    delay(1000);
    while (i <= 10)
    {
      if (analogRead(A6) >= 600 and analogRead(A6) <= 1023)
      {
        c++;
        lcd.clear();
        sprintf(s, "good job!x %d", c);
        lcd.print(s);
        break;
      }
      else if (analogRead(A6) <= 500 or digitalRead(39))
      {
        lcd.clear();
        lcd.print("come on!!!");
      }
      i++;
      delay(300);
    }
    break;
  case 7:
    /* code */
    i = 0;
    digitalWrite(6, 0);
    digitalWrite(5, 0);
    digitalWrite(7, 1);
    delay(1000);
    while (i <= 10)
    {
      if (analogRead(A6) <= 500)
      {
        c++;
        lcd.clear();
        sprintf(s, "good job!x %d", c);
        lcd.print(s);
        break;
      }
      else if ((analogRead(A6) >= 600 and analogRead(A6) <= 1023) or digitalRead(39))
      {
        lcd.clear();
        lcd.print("come on!!!");
      }
      i++;
      delay(300);
    }
    break;
  default:
    break;
  }
}
