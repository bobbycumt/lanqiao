#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TM1650.h>

volatile int sta;
volatile int item;
volatile int f;
String s;
LiquidCrystal_I2C mylcd(32, 16, 2);
TM1650 tm_4display;
int mylist[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup()
{
    sta = 0;
    item = 0;
    f = 0;
    s = "";
    mylcd.init();
    mylcd.backlight();
    Wire.begin();
    tm_4display.init();
    tm_4display.clear();
    mylcd.clear();
    pinMode(22, INPUT);
    pinMode(25, INPUT);
    pinMode(29, INPUT);
}

void loop()
{
    if(digitalRead(29))
    {
        while (digitalRead(29))
        {
            ;
        }
        item=random(1000,9999);
    }
    if (digitalRead(22))
    {
        for (int i = 0; i <= 3; i++)
        {
            f = String(String(item).charAt(i)).toInt();
            mylist[f]++;
        }
        for (int i = 0; i <= 9; i++)
        {
            while (mylist[i] > 0)
            {
                s = s + String(i);
                mylist[i]--;
            }
        }
        mylcd.setCursor(0, 0);
        mylcd.print(s);
        mylcd.setCursor(0, 1);
        mylcd.print("");
        s = "";
    }
    if (digitalRead(25))
    {
        for (int i = 0; i <= 3; i++)
        {
            f = String(String(item).charAt(i)).toInt();
            mylist[f]++;
        }
        for (int i = 9; i >= 0; i--)
        {
            while (mylist[i] > 0)
            {
                s = s + String(i);
                mylist[i]--;
            }
        }
        mylcd.setCursor(0, 0);
        mylcd.print("");
        mylcd.setCursor(0, 1);
        mylcd.print(s);
        s = "";
    }
}