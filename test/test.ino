int i;

void setup()
{
    i = 15;
    Serial.begin(9600);
    for (i = 1; i <= 10; i = i + (1))
    {
        Serial.println(i);
    }
    for (i = 10; i >= 1; i = i + (-1))
    {
        Serial.println(i);
    }
    Serial.println(i);
}

void loop()
{
}