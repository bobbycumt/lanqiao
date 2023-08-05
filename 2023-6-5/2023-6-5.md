# 2023年国赛第五题
![IMG_0422](https://github.com/bobbycumt/lanqiao/assets/68255033/8dd8538c-c005-48ec-babc-ba5974ecc3bc)

## LCD初始化
```CPP
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32, 16, 2);
```
## 引脚初始化
```CPP
for (int i = 5; i <= 7; i++)
  pinMode(i, OUTPUT);
for (int i = 5; i <= 7; i++)
  digitalWrite(i, 1);
pinMode(A5, INPUT);
pinMode(A6, INPUT);
pinMode(39, INPUT);
```
## 因为占用5 6 7引脚，使用随机数在这个范围随机，然后switch每个值，随机到6时，亮绿灯，执行任务要求。
## 处理3秒内动作时，使用的方法为将3秒时间打碎成10个300ms，也就是执行10次循环，这样能够避免延时太长采集不到动作，或者延时太短一次动作次数增加多次，300ms是调试后比较合适的结果。
```CPP
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
```


