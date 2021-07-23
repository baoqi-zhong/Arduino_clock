# Arduino clock

 > 基于Atmega芯片、Arduino平台的桌面时钟.
 > 
 > 具有计时、倒计时、闹钟等功能.
 > 
 > 支持掉电记忆,掉电走时.

## 硬件
* 主控芯片: 所有DIP28封装的Atmega系列.
   > 建议使用Atmega8/Atmega88/Atmega168/Atmega328.FLASH要求8k及以上.
* DS1302实时时钟芯片 + CR1220锂电池.
* 0.8寸共阳一位数码管x4.
* 蜂鸣器

## 软件
* 没有调库,使用Arduino原生函数完成
* 函数式编程. 没用中断 (((因为不会
* 800行代码庆祝~

## 功能
* 查看、调整时间、闹钟. 最多支持271个闹钟((((
* 双精度的计时、倒计时.范围0-59min59s.精度10ms.
* 支持掉电记忆,掉电走时.
   > 5ppm晶振配合足够耐心，周误差能调到2s
* 精度0.1°C的温度显示.
* 自动亮度调节,环境黑暗时自动调暗.

## 更新计划
* 全贴片的PCB调试完毕.~~正在整理资料,随缘更新.~~
   > Atmega系列单片机涨价严重,正在迁移到51核
* 基于esp8266的时钟等PCB到了再说
* 点阵时钟调试完毕.正在整理资料,随缘更新.

