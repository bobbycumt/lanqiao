#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C mylcd(32, 16, 2);

int a[32][3] = {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}, {11, 0, 0}, {12, 0, 0}, {13, 0, 0}, {14, 0, 0}, {15, 0, 0}, {15, 1, 0}, {14, 1, 0}, {13, 1, 0}, {12, 1, 0}, {11, 1, 0}, {10, 1, 0}, {9, 1, 0}, {8, 1, 0}, {7, 1, 0}, {6, 1, 0}, {5, 1, 0}, {4, 1, 0}, {3, 1, 0}, {2, 1, 0}, {1, 10, 0}, {0, 1, 0}};
int mx = -1;
int c = 0;

void setup()
{
    mylcd.init();
    mylcd.backlight();
    pinMode(22, INPUT);
}

void loop()
{
    if (digitalRead(22))
    {
        delay(2000);
        for (int i = 0; i < 32; i++)
        {
            a[i][2] = random(0, 10);
            mylcd.setCursor(a[i][0], a[i][1]);
            mylcd.print(String(a[i][2]));
        }
        while (c <= 32)
        {
            for (int i = 0; i < 32; i++)
            {
                if (a[i][2] > mx)
                {
                    mx = a[i][2];
                }
            }
            for (int i = 0; i < 32; i++)
            {
                if (a[i][2] == mx)
                {
                    a[i][2] = -1;
                    mylcd.setCursor(a[i][0], a[i][1]);
                    mylcd.print(" ");
                    c++;
                }
            }
            mx=-1;
            delay(2000);
        }
        c=0;
    }
}
