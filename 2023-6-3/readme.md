# 2023年国赛第三题
![Alt text](image.png)
## 初始化，流水灯使用循环操作，需要连接19号引脚的4号外部中断
```CPP
void setup()
{
    pinMode(22, INPUT);
    pinMode(19, INPUT);
    for (int i = 31; i <= 38; i++)
        pinMode(i, OUTPUT);
    for (int i = 31; i <= 38; i++)
        digitalWrite(i, 1);
    attachInterrupt(4, f, RISING);
}
```
## 按钮的按下处理
```CPP
if (digitalRead(22) and a == 0)
{
    while (digitalRead(22))
    {
        ;//松开的时候才往下执行
    }
    a = 1;
}
```
## 31-38引脚号和高低都需要随机，随机数函数是左开右闭
```CPP
if (a == 1)
{
    n = random(31, 39);
    s = random(0, 2);
    digitalWrite(n, s);
    delay(100);
}
```
## 中断处理，将标志变量a赋值为2，来满足最后一条要求
```CPP
void f()
{
    a = 2;
    for (int i = 31; i <= 38; i++)
        digitalWrite(i, 1);
}
```