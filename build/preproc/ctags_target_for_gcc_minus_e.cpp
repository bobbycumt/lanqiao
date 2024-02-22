# 1 "E:\\arduino_sketch\\lanqiao\\test\\test.ino"
String s = "";
int a, b = 0;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("****请选择功能****");
    Serial.println("1->圆面积计算");
    Serial.println("2->长方形面积计算");
    Serial.println("3->灯控制");
    while (!Serial.available())
        ;
    while (Serial.available())
    {
        s = Serial.readString();
        s.trim();
    }
    if (s.toInt() == 1)
    {
        Serial.println("请输入半径值：");
        while (!Serial.available())
            ;
        while (Serial.available())
        {
            s = Serial.readString();
            s.trim();
        }
        Serial.println(s.toInt() * 2);
        s = "";
    }
    else if (s.toInt() == 2)
    {
        Serial.println("请输入a：");
        while (!Serial.available())
            ;
        while (Serial.available())
        {
            s = Serial.readString();
            s.trim();
        }
        a = s.toInt();

        Serial.println("请输入b：");
        while (!Serial.available())
            ;
        while (Serial.available())
        {
            s = Serial.readString();
            s.trim();
        }
        b = s.toInt();
        Serial.println(a * b);
        s = "";
    }
}
