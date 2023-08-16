# 2023年6月国赛第二题
![Alt text](image.png)

## 包含必须要有wire，否则不运行
```CPP
#include <TM1650.h>
#include <Wire.h>
```
## setup中要初始化iic总线和数码管对象
```CPP
Wire.begin();
seg.init();
```
## 两组循环，每组循环两层，第一组循环外层是0-9，因为第四位不显示，所以先处理10秒以内的读数。内层循环为100毫秒跑秒。
```CPP
for (int i = 0; i <= 9; i++)
{
    for (int j = 0; j <= 9; j++)
    {
        delay(100);
        sprintf(s, " %d%d0", i, j);
        seg.displayString(s);
    }
}
```
## 第二组处理10秒以上，因为占两位数，最后只数到1490，把1500单独显示
```CPP
for (int i = 10; i <= 14; i++)
{
    for (int j = 0; j <= 9; j++)
    {
        delay(100);
        sprintf(s, "%d%d0", i, j);
        seg.displayString(s);
    }
}
```
## 因为最后要停止跑秒，把程序扔进死循环
```CPP
while (1);
```
