int n, s, a;

void setup()
{
    pinMode(22, INPUT);
    pinMode(19, INPUT);
    for (int i = 31; i <= 38; i++)
        pinMode(i, OUTPUT);
    for (int i = 31; i <= 38; i++)
        digitalWrite(i, 1);
    attachInterrupt(digitalPinToInterrupt(19), f, RISING);
}
void loop()
{
    if (digitalRead(22) and a == 0)
    {
        while (digitalRead(22))
        {
            ;
        }
        a = 1;
    }
    if (a == 1)
    {
        n = random(31, 39);
        s = random(0, 2);
        digitalWrite(n, s);
        delay(100);
    }
}

void f()
{
    a = 2;
    for (int i = 31; i <= 38; i++)
        digitalWrite(i, 1);
}