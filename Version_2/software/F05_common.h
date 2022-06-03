/*********************************************************
*Copyright (C), 2016-2027, Shanghai ESSE IC Co., Ltd.
*文件名:	common.h
*作  者:	ESSE
*版  本:	V1.00
*日  期:	2017/05/06
*描  述:	公共头文件
*备  注:	通用数据类型和宏定义
**********************************************************/
#ifndef   __COMMON_H__
#define   __COMMON_H__

/* 定义数据类型 */
typedef unsigned char  uchar;	//无符号8位整型变量
typedef unsigned int   uint;	//无符号16位整型变量 
typedef unsigned long  ulong;   //无符号32位整型变量

typedef unsigned char  INT8U;   //无符号8位整型变量
typedef signed   char  INT8S;   //有符号8位整型变量
typedef unsigned int   INT16U;  //无符号16位整型变量 
typedef signed   int   INT16S;  //有符号16位整型变量
typedef unsigned long  INT32U;  //无符号32位整型变量
typedef signed   long  INT32S;	//有符号32位整型变量
typedef float          FP32;    //单精度浮点型变量 
typedef double         FP64;    //双精度浮点型变量

//CLK 
#define  HRC_16M_EN   CLK_PR=0XA5;  CLK_C1 |= 0X01; CLK_PR=0X5a;  
#define  HRC_16M_DIS  CLK_PR=0XA5;  CLK_C1 &= 0Xfe; CLK_PR=0X5a;  
#define  HRC_XOSC_EN  CLK_PR=0XA5;  CLK_C1 |= 0X02; CLK_PR=0X5a;  
#define  HRC_XOSC_DIS CLK_PR=0XA5;  CLK_C1 |= 0Xfd; CLK_PR=0X5a; 

#define  SYSCK_DIV1   CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_PR=0X5a;
#define  SYSCK_DIV2   CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X01; CLK_PR=0X5a;
#define  SYSCK_DIV4   CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X02; CLK_PR=0X5a;
#define  SYSCK_DIV8   CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X03; CLK_PR=0X5a;
#define  SYSCK_DIV16  CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X03; CLK_PR=0X5a;
#define  SYSCK_DIV32  CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X04; CLK_PR=0X5a;
#define  SYSCK_DIV64  CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X05; CLK_PR=0X5a;
#define  SYSCK_DIV128 CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X06; CLK_PR=0X5a;
#define  SYSCK_DIV256 CLK_PR=0XA5;  CLK_C0 &= 0Xf0; CLK_C0 |= 0X07; CLK_PR=0X5a;


#define  WKUP_T_4US   CLK_PR=0XA5;  WKUP_T = 0X08;  CLK_PR=0X5a; 
#define  WKUP_T_8US   CLK_PR=0XA5;  WKUP_T = 0X18;  CLK_PR=0X5a; 
#define  WKUP_T_DEF   CLK_PR=0XA5;  WKUP_T = 0Xff;  CLK_PR=0X5a; 
//iap
#define  Page0   0x0000
#define  Page1   0x0200
#define  Page2   0x0400
#define  Page3   0x0600
#define  Page4   0x0800
#define  Page5   0x0a00
#define  Page6   0x0c00
#define  Page7   0x0e00
#define  Page8   0x1000
#define  Page9   0x1200
#define  Page10  0x1400
#define  Page11  0x1600
#define  Page12  0x1800
#define  Page13  0x1a00
#define  Page14  0x1c00
#define  Page15  0x1e00
#define  Page16  0x2000
#define  Page17  0x2200
#define  Page18  0x2400
#define  Page19  0x2600
#define  Page20  0x2800
#define  Page21  0x2a00
#define  Page22  0x2c00
#define  Page23  0x2e00
#define  Page24  0x3000
#define  Page25  0x3200
#define  Page26  0x3400
#define  Page27  0x3600
#define  Page28  0x3800
#define  Page29  0x3a00
#define  Page30  0x3c00
#define  Page31  0x3e00

#define  D_page0 0x8200
#define  D_page1 0x8300
//wdt
#define  CLR_WDT      WDT_OP = 0X5A
#define  WDT_T_8192MS WDT_C  = 0X10
#define  WDT_T_4096MS WDT_C  = 0X11
#define  WDT_T_2048MS WDT_C  = 0X12
#define  WDT_T_1024MS WDT_C  = 0X13
#define  WDT_T_512MS  WDT_C  = 0X14
#define  WDT_T_256MS  WDT_C  = 0X15
#define  WDT_T_128MS  WDT_C  = 0X16
#define  WDT_T_64MS   WDT_C  = 0X17
#define  WDT_T_32MS   WDT_C  = 0X18
#define  WDT_T_16MS   WDT_C  = 0X19
#define  WDT_T_8MS    WDT_C  = 0X1a
#define  WDT_T_4MS    WDT_C  = 0X1b
#define  WDT_T_2MS    WDT_C  = 0X1c

#define  WDT_LRC_8192MS WDT_C  = 0X10
#define  WDT_LRC_4096MS WDT_C  = 0X11
#define  WDT_LRC_2048MS WDT_C  = 0X12
#define  WDT_LRC_1024MS WDT_C  = 0X13
#define  WDT_LRC_512MS  WDT_C  = 0X14
#define  WDT_LRC_256MS  WDT_C  = 0X15
#define  WDT_LRC_128MS  WDT_C  = 0X16
#define  WDT_LRC_64MS   WDT_C  = 0X17
#define  WDT_LRC_32MS   WDT_C  = 0X18
#define  WDT_LRC_16MS   WDT_C  = 0X19
#define  WDT_LRC_8MS    WDT_C  = 0X1a
#define  WDT_LRC_4MS    WDT_C  = 0X1b
#define  WDT_LRC_2MS    WDT_C  = 0X1c

#define  WDT_SYSCLK_8MS    WDT_C  = 0X00
#define  WDT_SYSCLK_4MS    WDT_C  = 0X01
#define  WDT_SYSCLK_2MS    WDT_C  = 0X02
#define  WDT_SYSCLK_1MS    WDT_C  = 0X03
#define  WDT_SYSCLK_512US  WDT_C  = 0X04
//low power
#define  SLEEP_MD     PCON = 0X50;  PCON = 0X01; PCON = 0XA0  
#define  IDLE_MD      PCON = 0X50;  PCON = 0X02; PCON = 0XA0  

//P0_FUN设置/////////////////////////////////////////
#define  P07_FUN_0  P0_FUNH &= 0X3F
#define  P07_FUN_1  P0_FUNH &= 0X3F; P0_FUNH |= 0X40
#define  P07_FUN_2  P0_FUNH &= 0X3F; P0_FUNH |= 0X80
#define  P07_FUN_3                   P0_FUNH |= 0XC0

#define  P06_FUN_0  P0_FUNH &= 0XCF
#define  P06_FUN_1  P0_FUNH &= 0XCF; P0_FUNH |= 0X10
#define  P06_FUN_2  P0_FUNH &= 0XCF; P0_FUNH |= 0X20
#define  P06_FUN_3                   P0_FUNH |= 0X30

#define  P05_FUN_0  P0_FUNH &= 0XF3
#define  P05_FUN_1  P0_FUNH &= 0XF3; P0_FUNH |= 0X04
#define  P05_FUN_2  P0_FUNH &= 0XF3; P0_FUNH |= 0X08
#define  P05_FUN_3                   P0_FUNH |= 0X0C

#define  P04_FUN_0  P0_FUNH &= 0XFC
#define  P04_FUN_1  P0_FUNH &= 0XFC; P0_FUNH |= 0X01
#define  P04_FUN_2  P0_FUNH &= 0XFC; P0_FUNH |= 0X02; 
#define  P04_FUN_3                   P0_FUNH |= 0X03

#define  P03_FUN_0  P0_FUNL &= 0X3F
#define  P03_FUN_1  P0_FUNL &= 0X3F; P0_FUNL |= 0X40
#define  P03_FUN_2  P0_FUNL &= 0X3F; P0_FUNL |= 0X80
#define  P03_FUN_3  P0_FUNL |= 0XC0

#define  P02_FUN_0  P0_FUNL &= 0XCF
#define  P02_FUN_1  P0_FUNL &= 0XCF; P0_FUNL |= 0X10
#define  P02_FUN_2  P0_FUNL &= 0XCF; P0_FUNL |= 0X20
#define  P02_FUN_3                   P0_FUNL |= 0X30

#define  P01_FUN_0  P0_FUNL &= 0XF3
#define  P01_FUN_1  P0_FUNL &= 0XF3; P0_FUNL |= 0X04
#define  P01_FUN_2  P0_FUNL &= 0XF3; P0_FUNL |= 0X08
#define  P01_FUN_3                   P0_FUNL |= 0X0C

#define  P00_FUN_0  P0_FUNL &= 0XFC
#define  P00_FUN_1  P0_FUNL &= 0XFC; P0_FUNL |= 0X01
#define  P00_FUN_2  P0_FUNL &= 0XFC; P0_FUNL |= 0X02
#define  P00_FUN_3                   P0_FUNL |= 0X03

//P1_FUN设置/////////////////////////////////////////
#define  P17_FUN_0  P1_FUNH &= 0X3F
#define  P17_FUN_1  P1_FUNH &= 0X3F; P1_FUNH |= 0X40
#define  P17_FUN_2  P1_FUNH &= 0X3F; P1_FUNH |= 0X80
#define  P17_FUN_3                   P1_FUNH |= 0XC0

#define  P16_FUN_0  P1_FUNH &= 0XCF
#define  P16_FUN_1  P1_FUNH &= 0XCF; P1_FUNH |= 0X10
#define  P16_FUN_2  P1_FUNH &= 0XCF; P1_FUNH |= 0X20
#define  P16_FUN_3                   P1_FUNH |= 0X30

#define  P15_FUN_0  P1_FUNH &= 0XF3
#define  P15_FUN_1  P1_FUNH &= 0XF3; P1_FUNH |= 0X04
#define  P15_FUN_2  P1_FUNH &= 0XF3; P1_FUNH |= 0X08
#define  P15_FUN_3                   P1_FUNH |= 0X0C

#define  P14_FUN_0  P1_FUNH &= 0XFC
#define  P14_FUN_1  P1_FUNH &= 0XFC; P1_FUNH |= 0X01
#define  P14_FUN_2  P1_FUNH &= 0XFC; P1_FUNH |= 0X02
#define  P14_FUN_3                   P1_FUNH |= 0X03

#define  P13_FUN_0  P1_FUNL &= 0X3F
#define  P13_FUN_1  P1_FUNL &= 0X3F; P1_FUNL |= 0X40
#define  P13_FUN_2  P1_FUNL &= 0X3F; P1_FUNL |= 0X80
#define  P13_FUN_3                   P1_FUNL |= 0XC0

#define  P12_FUN_0  P1_FUNL &= 0XCF
#define  P12_FUN_1  P1_FUNL &= 0XCF; P1_FUNL |= 0X10
#define  P12_FUN_2  P1_FUNL &= 0XCF; P1_FUNL |= 0X20
#define  P12_FUN_3                   P1_FUNL |= 0X30

#define  P11_FUN_0  P1_FUNL &= 0XF3
#define  P11_FUN_1  P1_FUNL &= 0XF3; P1_FUNL |= 0X04
#define  P11_FUN_2  P1_FUNL &= 0XF3; P1_FUNL |= 0X08
#define  P11_FUN_3                   P1_FUNL |= 0X0C

#define  P10_FUN_0  P1_FUNL &= 0XFC
#define  P10_FUN_1  P1_FUNL &= 0XFC; P1_FUNL |= 0X01
#define  P10_FUN_2  P1_FUNL &= 0XFE; P1_FUNL |= 0X02
#define  P10_FUN_3                   P1_FUNL |= 0X03

//P2_FUN设置/////////////////////////////////////////
#define  P21_FUN_0  P2_FUNL &= 0XF3
#define  P21_FUN_1  P2_FUNL &= 0XF3; P2_FUNL |= 0X04
#define  P21_FUN_2  P2_FUNL &= 0XF3; P2_FUNL |= 0X08
#define  P21_FUN_3                   P2_FUNL |= 0X0C

#define  P20_FUN_0  P2_FUNL &= 0XFC
#define  P20_FUN_1  P2_FUNL &= 0XFC; P2_FUNL |= 0X01
#define  P20_FUN_2  P2_FUNL &= 0XFE; P2_FUNL |= 0X02
#define  P20_FUN_3                   P2_FUNL |= 0X03
//输出控制
#define  P00_SET    P0_0 = 1
#define  P01_SET    P0_1 = 1
#define  P02_SET    P0_2 = 1
#define  P03_SET    P0_3 = 1
#define  P04_SET    P0_4 = 1
#define  P05_SET    P0_5 = 1
#define  P06_SET    P0_6 = 1
#define  P07_SET    P0_7 = 1
#define  P0_SET     P0_DAT = 0XFF

#define  P10_SET    P1_0 = 1
#define  P11_SET    P1_1 = 1
#define  P12_SET    P1_2 = 1
#define  P13_SET    P1_3 = 1
#define  P14_SET    P1_4 = 1
#define  P15_SET    P1_5 = 1
#define  P16_SET    P1_6 = 1
#define  P17_SET    P1_7 = 1
#define  P1_SET     P1_DAT = 0XFF

#define  P20_SET    P2_0 = 1
#define  P21_SET    P2_1 = 1
#define  P2_SET     P2_DAT = 0XFF

#define  P00_CLR    P0_0 = 0
#define  P01_CLR    P0_1 = 0
#define  P02_CLR    P0_2 = 0
#define  P03_CLR    P0_3 = 0
#define  P04_CLR    P0_4 = 0
#define  P05_CLR    P0_5 = 0
#define  P06_CLR    P0_6 = 0
#define  P07_CLR    P0_7 = 0
#define  P0_CLR     P0_DAT = 0

#define  P10_CLR    P1_0 = 0
#define  P11_CLR    P1_1 = 0
#define  P12_CLR    P1_2 = 0
#define  P13_CLR    P1_3 = 0
#define  P14_CLR    P1_4 = 0
#define  P15_CLR    P1_5 = 0
#define  P16_CLR    P1_6 = 0
#define  P17_CLR    P1_7 = 0
#define  P1_CLR     P1_DAT = 0

#define  P20_CLR    P2_0 = 0
#define  P21_CLR    P2_1 = 0
#define  P2_CLR     P2_DAT = 0

#define  P00_REVS    P0_0 = ~P0_0
#define  P01_REVS    P0_1 = ~P0_1
#define  P02_REVS    P0_2 = ~P0_2
#define  P03_REVS    P0_3 = ~P0_3
#define  P04_REVS    P0_4 = ~P0_4
#define  P05_REVS    P0_5 = ~P0_5
#define  P06_REVS    P0_6 = ~P0_6
#define  P07_REVS    P0_7 = ~P0_7
#define  P0_REVS     P0_DAT = ~P0_DAT

#define  P10_REVS    P1_0 = ~P1_0
#define  P11_REVS    P1_1 = ~P1_1
#define  P12_REVS    P1_2 = ~P1_2
#define  P13_REVS    P1_3 = ~P1_3
#define  P14_REVS    P1_4 = ~P1_4
#define  P15_REVS    P1_5 = ~P1_5
#define  P16_REVS    P1_6 = ~P1_6
#define  P17_REVS    P1_7 = ~P1_7
#define  P1_REVS     P1_DAT = ~P1_DAT

#define  P20_REVS    P2_0 = ~P2_0
#define  P21_REVS    P2_1 = ~P2_1
#define  P2_REVS     P2_DAT = ~P2_DAT
//IO输出设置
#define  P00_OUT_EN     P0_OE |= 0X01
#define  P01_OUT_EN     P0_OE |= 0X02
#define  P02_OUT_EN     P0_OE |= 0X04
#define  P03_OUT_EN     P0_OE |= 0X08
#define  P04_OUT_EN     P0_OE |= 0X10
#define  P05_OUT_EN     P0_OE |= 0X20
#define  P06_OUT_EN     P0_OE |= 0X40
#define  P07_OUT_EN     P0_OE |= 0X80
#define  P0_OUT_EN      P0_OE  = 0XFF

#define  P00_OUT_DIS    P0_OE &= 0XFE
#define  P01_OUT_DIS    P0_OE &= 0XFD
#define  P02_OUT_DIS    P0_OE &= 0XFB
#define  P03_OUT_DIS    P0_OE &= 0XF7
#define  P04_OUT_DIS    P0_OE &= 0XEF
#define  P05_OUT_DIS    P0_OE &= 0XDF
#define  P06_OUT_DIS    P0_OE &= 0XBF
#define  P07_OUT_DIS    P0_OE &= 0X7F
#define  P0_OUT_DIS     P0_OE  = 0X00

#define  P10_OUT_EN     P1_OE |= 0X01
#define  P11_OUT_EN     P1_OE |= 0X02
#define  P12_OUT_EN     P1_OE |= 0X04
#define  P13_OUT_EN     P1_OE |= 0X08
#define  P14_OUT_EN     P1_OE |= 0X10
#define  P15_OUT_EN     P1_OE |= 0X20
#define  P16_OUT_EN     P1_OE |= 0X40
#define  P17_OUT_EN     P1_OE |= 0X80
#define  P1_OUT_EN      P1_OE  = 0XFF

#define  P10_OUT_DIS    P1_OE &= 0XFE
#define  P11_OUT_DIS    P1_OE &= 0XFD
#define  P12_OUT_DIS    P1_OE &= 0XFB
#define  P13_OUT_DIS    P1_OE &= 0XF7
#define  P14_OUT_DIS    P1_OE &= 0XEF
#define  P15_OUT_DIS    P1_OE &= 0XDF
#define  P16_OUT_DIS    P1_OE &= 0XBF
#define  P17_OUT_DIS    P1_OE &= 0X7F
#define  P1_OUT_DIS     P1_OE  = 0X00

#define  P20_OUT_EN     P2_OE |= 0X01
#define  P21_OUT_EN     P2_OE |= 0X02
#define  P2_OUT_EN      P2_OE  = 0XFF

#define  P20_OUT_DIS    P2_OE &= 0XFE
#define  P21_OUT_DIS    P2_OE &= 0XFD
#define  P2_OUT_DIS     P2_OE  = 0X00

//IO输入设置
#define  P00_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X01;  PORT_C0 &= 0XFE  
#define  P01_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X02;  PORT_C0 &= 0XFE
#define  P02_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X04;  PORT_C0 &= 0XFE
#define  P03_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X08;  PORT_C0 &= 0XFE
#define  P04_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X10;  PORT_C0 &= 0XFE
#define  P05_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X20;  PORT_C0 &= 0XFE
#define  P06_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X40;  PORT_C0 &= 0XFE
#define  P07_IN_EN     PORT_C0 |= 0X01; P0_IE |= 0X80;  PORT_C0 &= 0XFE
#define  P0_IN_EN      PORT_C0 |= 0X01; P0_IE  = 0XFF;  PORT_C0 &= 0XFE

#define  P00_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XFE;  PORT_C0 &= 0XFE
#define  P01_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XFD;  PORT_C0 &= 0XFE
#define  P02_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XFB;  PORT_C0 &= 0XFE
#define  P03_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XF7;  PORT_C0 &= 0XFE
#define  P04_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XEF;  PORT_C0 &= 0XFE
#define  P05_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XDF;  PORT_C0 &= 0XFE
#define  P06_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0XBF;  PORT_C0 &= 0XFE
#define  P07_IN_DIS    PORT_C0 |= 0X01; P0_IE &= 0X7F;  PORT_C0 &= 0XFE
#define  P0_IN_DIS     PORT_C0 |= 0X01; P0_IE  = 0X00;  PORT_C0 &= 0XFE

#define  P10_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X01;  PORT_C0 &= 0XFE
#define  P11_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X02;  PORT_C0 &= 0XFE
#define  P12_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X04;  PORT_C0 &= 0XFE
#define  P13_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X08;  PORT_C0 &= 0XFE
#define  P14_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X10;  PORT_C0 &= 0XFE
#define  P15_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X20;  PORT_C0 &= 0XFE
#define  P16_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X40;  PORT_C0 &= 0XFE
#define  P17_IN_EN     PORT_C0 |= 0X01; P1_IE |= 0X80;  PORT_C0 &= 0XFE
#define  P1_IN_EN      PORT_C0 |= 0X01; P1_IE  = 0XFF;  PORT_C0 &= 0XFE

#define  P10_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XFE;  PORT_C0 &= 0XFE
#define  P11_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XFD;  PORT_C0 &= 0XFE
#define  P12_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XFB;  PORT_C0 &= 0XFE
#define  P13_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XF7;  PORT_C0 &= 0XFE
#define  P14_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XEF;  PORT_C0 &= 0XFE
#define  P15_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XDF;  PORT_C0 &= 0XFE
#define  P16_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0XBF;  PORT_C0 &= 0XFE
#define  P17_IN_DIS    PORT_C0 |= 0X01; P1_IE &= 0X7F;  PORT_C0 &= 0XFE
#define  P1_IN_DIS     PORT_C0 |= 0X01; P1_IE  = 0X00;  PORT_C0 &= 0XFE

#define  P20_IN_EN     PORT_C0 |= 0X01; P2_IE |= 0X01;  PORT_C0 &= 0XFE
#define  P21_IN_EN     PORT_C0 |= 0X01; P2_IE |= 0X02;  PORT_C0 &= 0XFE
#define  P2_IN_EN      PORT_C0 |= 0X01; P2_IE  = 0XFF;  PORT_C0 &= 0XFE

#define  P20_IN_DIS    PORT_C0 |= 0X01; P2_IE &= 0XFE;  PORT_C0 &= 0XFE
#define  P21_IN_DIS    PORT_C0 |= 0X01; P2_IE &= 0XFD;  PORT_C0 &= 0XFE
#define  P2_IN_DIS     PORT_C0 |= 0X01; P2_IE  = 0X00;  PORT_C0 &= 0XFE

//上拉设置
#define  P00_PU_EN     P0_PUE |= 0X01
#define  P01_PU_EN     P0_PUE |= 0X02
#define  P02_PU_EN     P0_PUE |= 0X04
#define  P03_PU_EN     P0_PUE |= 0X08
#define  P04_PU_EN     P0_PUE |= 0X10
#define  P05_PU_EN     P0_PUE |= 0X20
#define  P06_PU_EN     P0_PUE |= 0X40
#define  P07_PU_EN     P0_PUE |= 0X80

#define  P10_PU_EN     P1_PUE |= 0X01
#define  P11_PU_EN     P1_PUE |= 0X02
#define  P12_PU_EN     P1_PUE |= 0X04
#define  P13_PU_EN     P1_PUE |= 0X08
#define  P14_PU_EN     P1_PUE |= 0X10
#define  P15_PU_EN     P1_PUE |= 0X20
#define  P16_PU_EN     P1_PUE |= 0X40
#define  P17_PU_EN     P1_PUE |= 0X80

#define  P20_PU_EN     P2_PUE |= 0X01
#define  P21_PU_EN     P2_PUE |= 0X02

#define  P00_PU_DIS    P0_PUE &= 0Xfe
#define  P01_PU_DIS    P0_PUE &= 0Xfd
#define  P02_PU_DIS    P0_PUE &= 0Xfb
#define  P03_PU_DIS    P0_PUE &= 0Xf7
#define  P04_PU_DIS    P0_PUE &= 0Xef
#define  P05_PU_DIS    P0_PUE &= 0Xdf
#define  P06_PU_DIS    P0_PUE &= 0Xbf
#define  P07_PU_DIS    P0_PUE &= 0X7f

#define  P10_PU_DIS    P1_PUE &= 0Xfe
#define  P11_PU_DIS    P1_PUE &= 0Xfd
#define  P12_PU_DIS    P1_PUE &= 0Xfb
#define  P13_PU_DIS    P1_PUE &= 0Xf7
#define  P14_PU_DIS    P1_PUE &= 0Xef
#define  P15_PU_DIS    P1_PUE &= 0Xdf
#define  P16_PU_DIS    P1_PUE &= 0Xbf
#define  P17_PU_DIS    P1_PUE &= 0X7f

#define  P20_PU_DIS    P2_PUE &= 0Xfe
#define  P21_PU_DIS    P2_PUE &= 0Xfd

//下拉设置
#define  P00_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X01; PORT_C0 &= 0XFD 
#define  P01_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X02; PORT_C0 &= 0XFD
#define  P02_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X04; PORT_C0 &= 0XFD
#define  P03_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X08; PORT_C0 &= 0XFD
#define  P04_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X10; PORT_C0 &= 0XFD
#define  P05_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X20; PORT_C0 &= 0XFD
#define  P06_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X40; PORT_C0 &= 0XFD
#define  P07_PD_EN     PORT_C0 |=0X02; P0_PDE |= 0X80; PORT_C0 &= 0XFD

#define  P10_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X01; PORT_C0 &= 0XFD
#define  P11_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X02; PORT_C0 &= 0XFD
#define  P12_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X04; PORT_C0 &= 0XFD
#define  P13_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X08; PORT_C0 &= 0XFD
#define  P14_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X10; PORT_C0 &= 0XFD
#define  P15_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X20; PORT_C0 &= 0XFD
#define  P16_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X40; PORT_C0 &= 0XFD
#define  P17_PD_EN     PORT_C0 |=0X02; P1_PDE |= 0X80; PORT_C0 &= 0XFD

#define  P20_PD_EN     PORT_C0 |=0X02; P2_PDE |= 0X01; PORT_C0 &= 0XFD
#define  P21_PD_EN     PORT_C0 |=0X02; P2_PDE |= 0X02; PORT_C0 &= 0XFD

#define  P00_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xfe; PORT_C0 &= 0XFD
#define  P01_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xfd; PORT_C0 &= 0XFD
#define  P02_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xfb; PORT_C0 &= 0XFD
#define  P03_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xf7; PORT_C0 &= 0XFD
#define  P04_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xef; PORT_C0 &= 0XFD
#define  P05_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xdf; PORT_C0 &= 0XFD
#define  P06_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0Xbf; PORT_C0 &= 0XFD
#define  P07_PD_DIS    PORT_C0 |=0X02; P0_PDE &= 0X7f; PORT_C0 &= 0XFD

#define  P10_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xfe; PORT_C0 &= 0XFD
#define  P11_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xfd; PORT_C0 &= 0XFD
#define  P12_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xfb; PORT_C0 &= 0XFD
#define  P13_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xf7; PORT_C0 &= 0XFD
#define  P14_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xef; PORT_C0 &= 0XFD
#define  P15_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xdf; PORT_C0 &= 0XFD
#define  P16_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0Xbf; PORT_C0 &= 0XFD
#define  P17_PD_DIS    PORT_C0 |=0X02; P1_PDE &= 0X7f; PORT_C0 &= 0XFD

#define  P20_PD_DIS    PORT_C0 |=0X02; P2_PDE &= 0Xfe; PORT_C0 &= 0XFD
#define  P21_PD_DIS    PORT_C0 |=0X02; P2_PDE &= 0Xfd; PORT_C0 &= 0XFD

//P0开漏设置
#define  P00_OD_EN     P0_ODE  |= 0x01
#define  P01_OD_EN     P0_ODE  |= 0x02
#define  P02_OD_EN     P0_ODE  |= 0x04
#define  P03_OD_EN     P0_ODE  |= 0x08
#define  P04_OD_EN     P0_ODE  |= 0x10
#define  P05_OD_EN     P0_ODE  |= 0x20
#define  P06_OD_EN     P0_ODE  |= 0x40
#define  P07_OD_EN     P0_ODE  |= 0x80

#define  P00_OD_DIS    P0_ODE  &= 0xfe
#define  P01_OD_DIS    P0_ODE  &= 0xfd
#define  P02_OD_DIS    P0_ODE  &= 0xfb
#define  P03_OD_DIS    P0_ODE  &= 0xf7
#define  P04_OD_DIS    P0_ODE  &= 0xef
#define  P05_OD_DIS    P0_ODE  &= 0xdf
#define  P06_OD_DIS    P0_ODE  &= 0xbf
#define  P07_OD_DIS    P0_ODE  &= 0x7f

//P1开漏设置
#define  P10_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x01;  PORT_C0 &= 0Xef
#define  P11_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x02;  PORT_C0 &= 0Xef
#define  P12_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x04;  PORT_C0 &= 0Xef
#define  P13_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x08;  PORT_C0 &= 0Xef
#define  P14_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x10;  PORT_C0 &= 0Xef
#define  P15_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x20;  PORT_C0 &= 0Xef
#define  P16_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x40;  PORT_C0 &= 0Xef
#define  P17_OD_EN     PORT_C0 |= 0X10; P0_ODE  |= 0x80;  PORT_C0 &= 0Xef
     
#define  P10_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xfe;  PORT_C0 &= 0Xef
#define  P11_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xfd;  PORT_C0 &= 0Xef
#define  P12_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xfb;  PORT_C0 &= 0Xef
#define  P13_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xf7;  PORT_C0 &= 0Xef
#define  P14_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xef;  PORT_C0 &= 0Xef
#define  P15_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xdf;  PORT_C0 &= 0Xef
#define  P16_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0xbf;  PORT_C0 &= 0Xef
#define  P17_OD_DIS    PORT_C0 |= 0X10; P0_ODE  &= 0x7f;  PORT_C0 &= 0Xef

//P2开漏设置
#define  P20_OD_EN     PORT_C0 |= 0X20; P0_ODE  |= 0x01;  PORT_C0 &= 0Xdf
#define  P21_OD_EN     PORT_C0 |= 0X20; P0_ODE  |= 0x02;  PORT_C0 &= 0Xdf
     
#define  P20_OD_DIS    PORT_C0 |= 0X20; P0_ODE  &= 0xfe;  PORT_C0 &= 0Xdf
#define  P21_OD_DIS    PORT_C0 |= 0X20; P0_ODE  &= 0xfd;  PORT_C0 &= 0Xdf

//IO中断设置选择1
#define  P01_POS_INT_EN   EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE |= 0x01
#define  P02_POS_INT_EN   EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE |= 0x02
#define  P04_POS_INT_EN   EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE |= 0x04
#define  P05_POS_INT_EN   EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE |= 0x08
#define  P06_POS_INT_EN   EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE |= 0x10
#define  P07_POS_INT_EN   EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE |= 0x20
#define  P10_POS_INT_EN   EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE |= 0x40
#define  P11_POS_INT_EN   EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE |= 0x80

#define  P01_POS_INT_DIS  EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P02_POS_INT_DIS  EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P04_POS_INT_DIS  EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P05_POS_INT_DIS  EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P06_POS_INT_DIS  EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P07_POS_INT_DIS  EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P10_POS_INT_DIS  EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P11_POS_INT_DIS  EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P01_NEG_INT_EN   EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINT_MSL |=0x01; EINTn_IE |= 0x01
#define  P02_NEG_INT_EN   EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINT_MSL |=0x04; EINTn_IE |= 0x02
#define  P04_NEG_INT_EN   EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINT_MSL |=0x10; EINTn_IE |= 0x04
#define  P05_NEG_INT_EN   EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINT_MSL |=0x40; EINTn_IE |= 0x08
#define  P06_NEG_INT_EN   EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINT_MSH |=0x01; EINTn_IE |= 0x10
#define  P07_NEG_INT_EN   EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINT_MSH |=0x04; EINTn_IE |= 0x20
#define  P10_NEG_INT_EN   EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINT_MSH |=0x10; EINTn_IE |= 0x40
#define  P11_NEG_INT_EN   EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINT_MSH |=0x40; EINTn_IE |= 0x80
                            
#define  P01_NEG_INT_DIS  EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P02_NEG_INT_DIS  EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P04_NEG_INT_DIS  EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P05_NEG_INT_DIS  EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P06_NEG_INT_DIS  EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P07_NEG_INT_DIS  EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P10_NEG_INT_DIS  EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P11_NEG_INT_DIS  EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P01_EDGE_INT_EN  EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINT_MSL |=0x02; EINTn_IE |= 0x01
#define  P02_EDGE_INT_EN  EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINT_MSL |=0x08; EINTn_IE |= 0x02
#define  P04_EDGE_INT_EN  EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINT_MSL |=0x20; EINTn_IE |= 0x04
#define  P05_EDGE_INT_EN  EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINT_MSL |=0x80; EINTn_IE |= 0x08
#define  P06_EDGE_INT_EN  EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINT_MSH |=0x02; EINTn_IE |= 0x10
#define  P07_EDGE_INT_EN  EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINT_MSH |=0x08; EINTn_IE |= 0x20
#define  P10_EDGE_INT_EN  EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINT_MSH |=0x20; EINTn_IE |= 0x40
#define  P11_EDGE_INT_EN  EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINT_MSH |=0x80; EINTn_IE |= 0x80
    
#define  P01_EDGE_INT_DIS EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P02_EDGE_INT_DIS EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P04_EDGE_INT_DIS EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P05_EDGE_INT_DIS EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P06_EDGE_INT_DIS EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P07_EDGE_INT_DIS EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P10_EDGE_INT_DIS EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P11_EDGE_INT_DIS EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P01_LV_INT_EN    EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINT_MSL |=0x03; EINTn_IE |= 0x01
#define  P02_LV_INT_EN    EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINT_MSL |=0x0c; EINTn_IE |= 0x02
#define  P04_LV_INT_EN    EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINT_MSL |=0x30; EINTn_IE |= 0x04
#define  P05_LV_INT_EN    EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINT_MSL |=0xc0; EINTn_IE |= 0x08
#define  P06_LV_INT_EN    EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINT_MSH |=0x03; EINTn_IE |= 0x10
#define  P07_LV_INT_EN    EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINT_MSH |=0x0c; EINTn_IE |= 0x20
#define  P10_LV_INT_EN    EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINT_MSH |=0x30; EINTn_IE |= 0x40
#define  P11_LV_INT_EN    EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINT_MSH |=0xc0; EINTn_IE |= 0x80
    
#define  P01_LV_INT_DIS   EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P02_LV_INT_DIS   EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P04_LV_INT_DIS   EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P05_LV_INT_DIS   EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P06_LV_INT_DIS   EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P07_LV_INT_DIS   EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P10_LV_INT_DIS   EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P11_LV_INT_DIS   EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

//IO中断设置选择2
#define  P12_POS_INT_EN   EINT_IOS |=0x01;  EINT_MSL &=0xfc; EINTn_IE |= 0x01
#define  P13_POS_INT_EN   EINT_IOS |=0x02;  EINT_MSL &=0xf3; EINTn_IE |= 0x02
#define  P14_POS_INT_EN   EINT_IOS |=0x04;  EINT_MSL &=0xcf; EINTn_IE |= 0x04
#define  P15_POS_INT_EN   EINT_IOS |=0x08;  EINT_MSL &=0x3f; EINTn_IE |= 0x08
#define  P16_POS_INT_EN   EINT_IOS |=0x10;  EINT_MSH &=0xfc; EINTn_IE |= 0x10
#define  P17_POS_INT_EN   EINT_IOS |=0x20;  EINT_MSH &=0xf3; EINTn_IE |= 0x20
#define  P20_POS_INT_EN   EINT_IOS |=0x40;  EINT_MSH &=0xcf; EINTn_IE |= 0x40
#define  P21_POS_INT_EN   EINT_IOS |=0x80;  EINT_MSH &=0x3f; EINTn_IE |= 0x80

#define  P12_POS_INT_DIS  EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P13_POS_INT_DIS  EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P14_POS_INT_DIS  EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P15_POS_INT_DIS  EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P16_POS_INT_DIS  EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P17_POS_INT_DIS  EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P20_POS_INT_DIS  EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P21_POS_INT_DIS  EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P12_NEG_INT_EN   EINT_IOS |=0x01;  EINT_MSL &=0xfc; EINT_MSL |=0x01; EINTn_IE |= 0x01
#define  P13_NEG_INT_EN   EINT_IOS |=0x02;  EINT_MSL &=0xf3; EINT_MSL |=0x04; EINTn_IE |= 0x02
#define  P14_NEG_INT_EN   EINT_IOS |=0x04;  EINT_MSL &=0xcf; EINT_MSL |=0x10; EINTn_IE |= 0x04
#define  P15_NEG_INT_EN   EINT_IOS |=0x08;  EINT_MSL &=0x3f; EINT_MSL |=0x40; EINTn_IE |= 0x08
#define  P16_NEG_INT_EN   EINT_IOS |=0x10;  EINT_MSH &=0xfc; EINT_MSH |=0x01; EINTn_IE |= 0x10
#define  P17_NEG_INT_EN   EINT_IOS |=0x20;  EINT_MSH &=0xf3; EINT_MSH |=0x04; EINTn_IE |= 0x20
#define  P20_NEG_INT_EN   EINT_IOS |=0x40;  EINT_MSH &=0xcf; EINT_MSH |=0x10; EINTn_IE |= 0x40
#define  P21_NEG_INT_EN   EINT_IOS |=0x80;  EINT_MSH &=0x3f; EINT_MSH |=0x40; EINTn_IE |= 0x80
                            
#define  P12_NEG_INT_DIS  EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P13_NEG_INT_DIS  EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P14_NEG_INT_DIS  EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P15_NEG_INT_DIS  EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P16_NEG_INT_DIS  EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P17_NEG_INT_DIS  EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P20_NEG_INT_DIS  EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P21_NEG_INT_DIS  EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P12_EDGE_INT_EN  EINT_IOS |=0x01;  EINT_MSL &=0xfc; EINT_MSL |=0x02; EINTn_IE |= 0x01
#define  P13_EDGE_INT_EN  EINT_IOS |=0x02;  EINT_MSL &=0xf3; EINT_MSL |=0x08; EINTn_IE |= 0x02
#define  P14_EDGE_INT_EN  EINT_IOS |=0x04;  EINT_MSL &=0xcf; EINT_MSL |=0x20; EINTn_IE |= 0x04
#define  P15_EDGE_INT_EN  EINT_IOS |=0x08;  EINT_MSL &=0x3f; EINT_MSL |=0x80; EINTn_IE |= 0x08
#define  P16_EDGE_INT_EN  EINT_IOS |=0x10;  EINT_MSH &=0xfc; EINT_MSH |=0x02; EINTn_IE |= 0x10
#define  P17_EDGE_INT_EN  EINT_IOS |=0x20;  EINT_MSH &=0xf3; EINT_MSH |=0x08; EINTn_IE |= 0x20
#define  P20_EDGE_INT_EN  EINT_IOS |=0x40;  EINT_MSH &=0xcf; EINT_MSH |=0x20; EINTn_IE |= 0x40
#define  P21_EDGE_INT_EN  EINT_IOS |=0x80;  EINT_MSH &=0x3f; EINT_MSH |=0x80; EINTn_IE |= 0x80
    
#define  P12_EDGE_INT_DIS EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P13_EDGE_INT_DIS EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P14_EDGE_INT_DIS EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P15_EDGE_INT_DIS EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P16_EDGE_INT_DIS EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P17_EDGE_INT_DIS EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P20_EDGE_INT_DIS EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P21_EDGE_INT_DIS EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P12_LV_INT_EN    EINT_IOS |=0x01;  EINT_MSL &=0xfc; EINT_MSL |=0x03; EINTn_IE |= 0x01
#define  P13_LV_INT_EN    EINT_IOS |=0x02;  EINT_MSL &=0xf3; EINT_MSL |=0x0c; EINTn_IE |= 0x02
#define  P14_LV_INT_EN    EINT_IOS |=0x04;  EINT_MSL &=0xcf; EINT_MSL |=0x30; EINTn_IE |= 0x04
#define  P15_LV_INT_EN    EINT_IOS |=0x08;  EINT_MSL &=0x3f; EINT_MSL |=0xc0; EINTn_IE |= 0x08
#define  P16_LV_INT_EN    EINT_IOS |=0x10;  EINT_MSH &=0xfc; EINT_MSH |=0x03; EINTn_IE |= 0x10
#define  P17_LV_INT_EN    EINT_IOS |=0x20;  EINT_MSH &=0xf3; EINT_MSH |=0x0c; EINTn_IE |= 0x20
#define  P20_LV_INT_EN    EINT_IOS |=0x40;  EINT_MSH &=0xcf; EINT_MSH |=0x30; EINTn_IE |= 0x40
#define  P21_LV_INT_EN    EINT_IOS |=0x80;  EINT_MSH &=0x3f; EINT_MSH |=0xc0; EINTn_IE |= 0x80
    
#define  P12_LV_INT_DIS   EINT_IOS &=0xfe;  EINT_MSL &=0xfc; EINTn_IE &= 0xfe
#define  P13_LV_INT_DIS   EINT_IOS &=0xfd;  EINT_MSL &=0xf3; EINTn_IE &= 0xfd
#define  P14_LV_INT_DIS   EINT_IOS &=0xfb;  EINT_MSL &=0xcf; EINTn_IE &= 0xfb
#define  P15_LV_INT_DIS   EINT_IOS &=0xf7;  EINT_MSL &=0x3f; EINTn_IE &= 0xf7
#define  P16_LV_INT_DIS   EINT_IOS &=0xef;  EINT_MSH &=0xfc; EINTn_IE &= 0xef
#define  P17_LV_INT_DIS   EINT_IOS &=0xdf;  EINT_MSH &=0xf3; EINTn_IE &= 0xdf
#define  P20_LV_INT_DIS   EINT_IOS &=0xbf;  EINT_MSH &=0xcf; EINTn_IE &= 0xbf
#define  P21_LV_INT_DIS   EINT_IOS &=0x7f;  EINT_MSH &=0x3f; EINTn_IE &= 0x7f

#define  P12_INT_IF_CLR   EINT0_IF = 0x00  
#define  P13_INT_IF_CLR   EINT1_IF = 0x00
#define  P14_INT_IF_CLR   EINT2_IF = 0x00
#define  P15_INT_IF_CLR   EINT3_IF = 0x00
#define  P16_INT_IF_CLR   EINT4_IF = 0x00
#define  P17_INT_IF_CLR   EINT5_IF = 0x00
#define  P20_INT_IF_CLR   EINT6_IF = 0x00
#define  P21_INT_IF_CLR   EINT7_IF = 0x00

#define  P01_INT_IF_CLR   EINT0_IF = 0x00
#define  P02_INT_IF_CLR   EINT1_IF = 0x00
#define  P04_INT_IF_CLR   EINT2_IF = 0x00
#define  P05_INT_IF_CLR   EINT3_IF = 0x00
#define  P06_INT_IF_CLR   EINT4_IF = 0x00
#define  P07_INT_IF_CLR   EINT5_IF = 0x00
#define  P10_INT_IF_CLR   EINT6_IF = 0x00
#define  P11_INT_IF_CLR   EINT7_IF = 0x00

//中断控制
#define  GIE_EN       GIE = 0X01
#define  INT0_EN      INT0_IE = 0X01
#define  INT1_EN      INT1_IE = 0X01
#define  INT2_EN      INT2_IE = 0X01
#define  INT3_EN      INT3_IE = 0X01
#define  INT4_EN      INT4_IE = 0X01
#define  INT5_EN      INT5_IE = 0X01
#define  INT6_EN      INT6_IE = 0X01

#define  GIE_DIS      GIE = 0x00 
#define  INT0_DIS     INT0_IE = 0X00
#define  INT1_DIS     INT1_IE = 0X00
#define  INT2_DIS     INT2_IE = 0X00
#define  INT3_DIS     INT3_IE = 0X00
#define  INT4_DIS     INT4_IE = 0X00
#define  INT5_DIS     INT5_IE = 0X00
#define  INT6_DIS     INT6_IE = 0X00

#define  INT0_PI_EN   INT0_IP = 0X01
#define  INT1_PI_EN   INT1_IP = 0X01
#define  INT2_PI_EN   INT2_IP = 0X01
#define  INT3_PI_EN   INT3_IP = 0X01
#define  INT4_PI_EN   INT4_IP = 0X01
#define  INT5_PI_EN   INT5_IP = 0X01
#define  INT6_PI_EN   INT6_IP = 0X01

#define  INT0_PI_DIS  INT0_IP = 0X00
#define  INT1_PI_DIS  INT1_IP = 0X00
#define  INT2_PI_DIS  INT2_IP = 0X00
#define  INT3_PI_DIS  INT3_IP = 0X00
#define  INT4_PI_DIS  INT4_IP = 0X00
#define  INT5_PI_DIS  INT5_IP = 0X00
#define  INT6_PI_DIS  INT6_IP = 0X00

#define  INT0_IF_CLR  INT0_IF = 0X00
#define  INT1_IF_CLR  INT1_IF = 0X00
#define  INT2_IF_CLR  INT2_IF = 0X00
#define  INT3_IF_CLR  INT3_IF = 0X00
#define  INT4_IF_CLR  INT4_IF = 0X00
#define  INT5_IF_CLR  INT5_IF = 0X00
#define  INT6_IF_CLR  INT6_IF = 0X00
#define  INT_IF_CLR   INTn_IF = 0X00

#define  INT0_IF_SET  INT0_IF = 0X01
#define  INT1_IF_SET  INT1_IF = 0X01
#define  INT2_IF_SET  INT2_IF = 0X01
#define  INT3_IF_SET  INT3_IF = 0X01
#define  INT4_IF_SET  INT4_IF = 0X01
#define  INT5_IF_SET  INT5_IF = 0X01
#define  INT6_IF_SET  INT6_IF = 0X01

//TMR 中断
#define  TMR0_INT_EN  TMRn_IE |=0X01
#define  TMR1_INT_EN  TMRn_IE |=0X02
#define  TMR2_INT_EN  TMRn_IE |=0X04
#define  TMR3_INT_EN  TMRn_IE |=0X08

#define  TMR0_INT_DIS TMRn_IE &=0Xfe
#define  TMR1_INT_DIS TMRn_IE &=0Xfd
#define  TMR2_INT_DIS TMRn_IE &=0Xfb
#define  TMR3_INT_DIS TMRn_IE &=0Xf7

#define  TMR0_INT_IF_CLR TMR0_IF =0X00
#define  TMR1_INT_IF_CLR TMR1_IF =0X00
#define  TMR2_INT_IF_CLR TMR2_IF =0X00
#define  TMR3_INT_IF_CLR TMR3_IF =0X00

//CAP 中断
#define  CAP0_INT_EN  CAPn_IE |=0X01
#define  CAP1_INT_EN  CAPn_IE |=0X02
#define  CAP2_INT_EN  CAPn_IE |=0X04

#define  CAP0_INT_DIS CAPn_IE &=0Xfe
#define  CAP1_INT_DIS CAPn_IE &=0Xfd
#define  CAP2_INT_DIS CAPn_IE &=0Xfb

#define  CAP0_INT_IF_CLR CAP0_IF =0X00
#define  CAP1_INT_IF_CLR CAP1_IF =0X00
#define  CAP2_INT_IF_CLR CAP2_IF =0X00

//PWM 中断
#define  PWM0_INT_EN  PWMn_IE |=0X01
#define  PWM1_INT_EN  PWMn_IE |=0X02
#define  PWM2_INT_EN  PWMn_IE |=0X04
#define  STP0_INT_EN  PWMn_IE |=0X10
#define  STP1_INT_EN  PWMn_IE |=0X20
#define  STP2_INT_EN  PWMn_IE |=0X40

#define  PWM0_INT_DIS PWMn_IE &=0Xfe
#define  PWM1_INT_DIS PWMn_IE &=0Xfd
#define  PWM2_INT_DIS PWMn_IE &=0Xfb
#define  STP0_INT_DIS PWMn_IE &=0Xef
#define  STP1_INT_DIS PWMn_IE &=0Xdf
#define  STP2_INT_DIS PWMn_IE &=0Xbf

#define  PWM0_INT_IF_CLR PWM0_IF =0X00
#define  PWM1_INT_IF_CLR PWM1_IF =0X00
#define  PWM2_INT_IF_CLR PWM2_IF =0X00
#define  STP0_INT_IF_CLR STP0_IF =0X00
#define  STP1_INT_IF_CLR STP1_IF =0X00
#define  STP2_INT_IF_CLR STP2_IF =0X00

//uart 中断
#define  UART_RX_INT_EN  UARTn_IE |=0X01
#define  UART_TX_INT_EN  UARTn_IE |=0X02

#define  UART_RX_INT_DIS UARTn_IE &=0Xfe
#define  UART_TX_INT_DIS UARTn_IE &=0Xfd

//IIC 中断
#define  IIC_INT_EN  IICn_IE |=0X10
#define  IIC_INT_DIS IICn_IE &=0Xef

#define  IIC_INT_IF_CLR IIC_IF =0X00

//SPI 中断
#define  SPI_INT_EN  SPIn_IE |=0X40
#define  SPI_INT_DIS SPIn_IE &=0Xbf

#define  SPI_INT_IF_CLR SPI_IF =0X00

//模拟中断
#define  TK_INT_EN    AN_IE |=0X01
#define  ADC_INT_EN   AN_IE |=0X04
#define  LVD_INT_EN   AN_IE |=0X10
#define  CCM_INT_EN   AN_IE |=0X40

#define  TK_INT_DIS   AN_IE &=0Xfe
#define  ADC_INT_DIS  AN_IE &=0Xfb
#define  LVD_INT_DIS  AN_IE &=0Xef
#define  CCM_INT_DIS  AN_IE &=0Xbf

#define  TK_INT_IF_CLR  TK_IF =0X00
#define  ADC_INT_IF_CLR ADC_IF =0X00
#define  LVD_INT_IF_CLR LVD_IF =0X00
#define  CCM_INT_IF_CLR CCM_IF =0X00

//TMR0
#define  TMR0_PST_1    TMR0_C0 &= 0xf0 
#define  TMR0_PST_2    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x01
#define  TMR0_PST_3    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x02
#define  TMR0_PST_4    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x03
#define  TMR0_PST_5    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x04
#define  TMR0_PST_6    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x05
#define  TMR0_PST_7    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x06
#define  TMR0_PST_8    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x07
#define  TMR0_PST_9    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x08
#define  TMR0_PST_10   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x09
#define  TMR0_PST_11   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0a
#define  TMR0_PST_12   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0b
#define  TMR0_PST_13   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0c
#define  TMR0_PST_14   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0d
#define  TMR0_PST_15   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0e
#define  TMR0_PST_16   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0f

#define  TMR0_SYSCLK   TMR0_C0 &= 0xcf
#define  TMR0_EXCK     TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x10
#define  TMR0_LRC      TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x20
#define  TMR0_XOSC     TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x30

#define  TMR0_DIV8_EN  TMR0_C0 |= 0x40  
#define  TMR0_DIV8_DIS TMR0_C0 &= 0xbf

#define  TMR0_EN       TMR0_C0 |= 0x80
#define  TMR0_DIS      TMR0_C0 &= 0x7f

#define  TMR0_GE_H_EN  TMR0_C1 = 0X01
#define  TMR0_GE_L_EN  TMR0_C1 = 0X03

#define  TMR0_GE_H_DIS TMR0_C1 = 0X00
#define  TMR0_GE_L_DIS TMR0_C1 = 0X00

#define  TMR0_CLR      TMR0L = 0X00;     TMR0H = 0X00

//TMR1
#define  TMR1_PST_1    TMR1_C0 &= 0xf0 
#define  TMR1_PST_2    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x01
#define  TMR1_PST_3    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x02
#define  TMR1_PST_4    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x03
#define  TMR1_PST_5    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x04
#define  TMR1_PST_6    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x05
#define  TMR1_PST_7    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x06
#define  TMR1_PST_8    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x07
#define  TMR1_PST_9    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x08
#define  TMR1_PST_10   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x09
#define  TMR1_PST_11   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0a
#define  TMR1_PST_12   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0b
#define  TMR1_PST_13   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0c
#define  TMR1_PST_14   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0d
#define  TMR1_PST_15   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0e
#define  TMR1_PST_16   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0f

#define  TMR1_SYSCLK   TMR1_C0 &= 0xcf
#define  TMR1_EXCK     TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x10
#define  TMR1_LRC      TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x20
#define  TMR1_XOSC     TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x30

#define  TMR1_DIV8_EN  TMR1_C0 |= 0x40  
#define  TMR1_DIV8_DIS TMR1_C0 &= 0xbf

#define  TMR1_EN       TMR1_C0 |= 0x80  
#define  TMR1_DIS      TMR1_C0 &= 0x7f

#define  TMR1_GE_H_EN  TMR1_C1 = 0X01
#define  TMR1_GE_L_EN  TMR1_C1 = 0X03

#define  TMR1_GE_H_DIS TMR1_C1 = 0X00
#define  TMR1_GE_L_DIS TMR1_C1 = 0X00

#define  TMR1_CLR      TMR1L = 0X00;     TMR1H = 0X00

//TMR2
#define  TMR2_PST_1    TMR2_C0 &= 0xf0 
#define  TMR2_PST_2    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x01
#define  TMR2_PST_3    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x02
#define  TMR2_PST_4    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x03
#define  TMR2_PST_5    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x04
#define  TMR2_PST_6    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x05
#define  TMR2_PST_7    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x06
#define  TMR2_PST_8    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x07
#define  TMR2_PST_9    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x08
#define  TMR2_PST_10   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x09
#define  TMR2_PST_11   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0a
#define  TMR2_PST_12   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0b
#define  TMR2_PST_13   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0c
#define  TMR2_PST_14   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0d
#define  TMR2_PST_15   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0e
#define  TMR2_PST_16   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0f

#define  TMR2_SYSCLK   TMR2_C0 &= 0xcf
#define  TMR2_EXCK     TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x10
#define  TMR2_LRC      TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x20
#define  TMR2_XOSC     TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x30

#define  TMR2_DIV8_EN  TMR2_C0 |= 0x40  
#define  TMR2_DIV8_DIS TMR2_C0 &= 0xbf

#define  TMR2_EN       TMR2_C0 |= 0x80
#define  TMR2_DIS      TMR2_C0 &= 0x7f

#define  TMR2_GE_H_EN  TMR2_C1 = 0X01
#define  TMR2_GE_L_EN  TMR2_C1 = 0X03

#define  TMR2_GE_H_DIS TMR2_C1 = 0X00
#define  TMR2_GE_L_DIS TMR2_C1 = 0X00

#define  TMR2_CLR      TMR2L = 0X00;     TMR2H = 0X00

//TMR3
#define  TMR3_PST_1    TMR3_C0 &= 0xf0 
#define  TMR3_PST_2    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x01
#define  TMR3_PST_3    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x02
#define  TMR3_PST_4    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x03
#define  TMR3_PST_5    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x04
#define  TMR3_PST_6    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x05
#define  TMR3_PST_7    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x06
#define  TMR3_PST_8    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x07
#define  TMR3_PST_9    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x08
#define  TMR3_PST_10   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x09
#define  TMR3_PST_11   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0a
#define  TMR3_PST_12   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0b
#define  TMR3_PST_13   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0c
#define  TMR3_PST_14   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0d
#define  TMR3_PST_15   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0e
#define  TMR3_PST_16   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0f

#define  TMR3_SYSCLK   TMR3_C0 &= 0xcf
#define  TMR3_EXCK     TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x10
#define  TMR3_LRC      TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x20
#define  TMR3_XOSC     TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x30

#define  TMR3_DIV8_EN  TMR3_C0 |= 0x40  
#define  TMR3_DIV8_DIS TMR3_C0 &= 0xbf

#define  TMR3_EN       TMR3_C0 |= 0x80  
#define  TMR3_DIS      TMR3_C0 &= 0x7f

#define  TMR3_GE_H_EN  TMR3_C1 = 0X01
#define  TMR3_GE_L_EN  TMR3_C1 = 0X03

#define  TMR3_GE_H_DIS TMR3_C1 = 0X00
#define  TMR3_GE_L_DIS TMR3_C1 = 0X00

#define  TMR3_CLR      TMR3L = 0X00;     TMR3H = 0X00

//CAP0
#define  CAP0_MD_DIS   CAP0_C &= 0Xfc
#define  CAP0_ADD_MD   CAP0_C &= 0Xfc;    CAP0_C |= 0X02
#define  CAP0_CLR_MD   CAP0_C |= 0X03

#define  CAP0_TMR0_S   CAP0_C &= 0Xf3
#define  CAP0_TMR1_S   CAP0_C &= 0Xf3;    CAP0_C |= 0X04
#define  CAP0_TMR2_S   CAP0_C &= 0Xf3;    CAP0_C |= 0X08
#define  CAP0_TMR3_S   CAP0_C |= 0X0c

#define  CAP0_CAP_1    CAP0_C &= 0Xcf
#define  CAP0_CAP_4    CAP0_C &= 0Xcf;    CAP0_C |= 0X10 
#define  CAP0_CAP_8    CAP0_C &= 0Xcf;    CAP0_C |= 0X20
#define  CAP0_CAP_16   CAP0_C |= 0X30

#define  CAP0_CAP_NONE CAP0_C &= 0X3f
#define  CAP0_CAP_POS  CAP0_C &= 0X3f;    CAP0_C |= 0X40 
#define  CAP0_CAP_NEG  CAP0_C &= 0X3f;    CAP0_C |= 0X80
#define  CAP0_CAP_EDGE CAP0_C |= 0Xc0

//CAP1
#define  CAP1_MD_DIS   CAP1_C &= 0Xfc
#define  CAP1_ADD_MD   CAP1_C &= 0Xfc;    CAP1_C |= 0X02
#define  CAP1_CLR_MD   CAP1_C |= 0X03

#define  CAP1_TMR0_S   CAP1_C &= 0Xf3
#define  CAP1_TMR1_S   CAP1_C &= 0Xf3;    CAP1_C |= 0X04
#define  CAP1_TMR2_S   CAP1_C &= 0Xf3;    CAP1_C |= 0X08
#define  CAP1_TMR3_S   CAP1_C |= 0X0c

#define  CAP1_CAP_1    CAP1_C &= 0Xcf
#define  CAP1_CAP_4    CAP1_C &= 0Xcf;    CAP1_C |= 0X10 
#define  CAP1_CAP_8    CAP1_C &= 0Xcf;    CAP1_C |= 0X20
#define  CAP1_CAP_16   CAP1_C |= 0X30

#define  CAP1_CAP_NONE CAP1_C &= 0X3f
#define  CAP1_CAP_POS  CAP1_C &= 0X3f;    CAP1_C |= 0X40 
#define  CAP1_CAP_NEG  CAP1_C &= 0X3f;    CAP1_C |= 0X80
#define  CAP1_CAP_EDGE CAP1_C |= 0Xc0

//CAP2
#define  CAP2_MD_DIS   CAP2_C &= 0Xfc
#define  CAP2_ADD_MD   CAP2_C &= 0Xfc;    CAP2_C |= 0X02
#define  CAP2_CLR_MD   CAP2_C |= 0X03

#define  CAP2_TMR0_S   CAP2_C &= 0Xf3
#define  CAP2_TMR1_S   CAP2_C &= 0Xf3;    CAP2_C |= 0X04
#define  CAP2_TMR2_S   CAP2_C &= 0Xf3;    CAP2_C |= 0X08
#define  CAP2_TMR3_S   CAP2_C |= 0X0c

#define  CAP2_CAP_1    CAP2_C &= 0Xcf
#define  CAP2_CAP_4    CAP2_C &= 0Xcf;    CAP2_C |= 0X10 
#define  CAP2_CAP_8    CAP2_C &= 0Xcf;    CAP2_C |= 0X20
#define  CAP2_CAP_16   CAP2_C |= 0X30

#define  CAP2_CAP_NONE CAP2_C &= 0X3f
#define  CAP2_CAP_POS  CAP2_C &= 0X3f;    CAP2_C |= 0X40 
#define  CAP2_CAP_NEG  CAP2_C &= 0X3f;    CAP2_C |= 0X80
#define  CAP2_CAP_EDGE CAP2_C |= 0Xc0

//PWM0
#define  PWM0_MD_DIS   PWM0_C &= 0Xfc
#define  PWM0_MD_EN    PWM0_C &= 0Xfc;    PWM0_C |= 0X01 

#define  PWM0_TMR0_S   PWM0_C &= 0Xf3
#define  PWM0_TMR1_S   PWM0_C &= 0Xf3;    PWM0_C |= 0X04
#define  PWM0_TMR2_S   PWM0_C &= 0Xf3;    PWM0_C |= 0X08
#define  PWM0_TMR3_S   PWM0_C |= 0X0c

#define  PWM0_NOR_MD   PWM0_C &= 0Xcf
#define  PWM0_PH_MD    PWM0_C |= 0X30

#define  PWM0_STP_DIS  PWM0_C &= 0X3f
#define  PWM0_STP_LV   PWM0_C &= 0X3f;    PWM0_C |= 0x40
#define  PWM0_STP_SOFT PWM0_C |= 0xc0

#define  PWM0_CH0_POS  PWM0_OC &= 0xec;   PWM0_OC |= 0x01;
#define  PWM0_CH0_NEG  PWM0_OC &= 0xec;   PWM0_OC |= 0x02;

#define  PWM0_CH1_POS  PWM0_OC &= 0xd3;   PWM0_OC |= 0x24;
#define  PWM0_CH1_NEG  PWM0_OC &= 0xd3;   PWM0_OC |= 0x08;

#define  PWM0_CH0_N_DY PWM0_OC &= 0XBf  
#define  PWM0_CH0_P_DY PWM0_OC |= 0X40    

#define  PWM0_CH1_N_DY PWM0_OC &= 0X7f
#define  PWM0_CH1_P_DY PWM0_OC |= 0X80

//PWM1
#define  PWM1_MD_DIS   PWM1_C &= 0Xfc
#define  PWM1_MD_EN    PWM1_C &= 0Xfc;    PWM1_C |= 0X01 

#define  PWM1_TMR0_S   PWM1_C &= 0Xf3
#define  PWM1_TMR1_S   PWM1_C &= 0Xf3;    PWM1_C |= 0X04
#define  PWM1_TMR2_S   PWM1_C &= 0Xf3;    PWM1_C |= 0X08
#define  PWM1_TMR3_S   PWM1_C &= 0Xf3;    PWM1_C |= 0X0c

#define  PWM1_NOR_MD   PWM1_C &= 0Xcf
#define  PWM1_PH_MD    PWM1_C |= 0X30

#define  PWM1_STP_DIS  PWM1_C &= 0X3f
#define  PWM1_STP_LV   PWM1_C &= 0X3f;    PWM1_C |= 0x40
#define  PWM1_STP_SOFT PWM1_C |= 0xc0

#define  PWM1_CH0_POS  PWM1_OC &= 0xec;   PWM1_OC |= 0x11;
#define  PWM1_CH0_NEG  PWM1_OC &= 0xec;   PWM1_OC |= 0x02;

#define  PWM1_CH1_POS  PWM1_OC &= 0xd3;   PWM1_OC |= 0x24;
#define  PWM1_CH1_NEG  PWM1_OC &= 0xd3;   PWM1_OC |= 0x08;

#define  PWM1_CH0_N_DY PWM1_OC &= 0XBf  
#define  PWM1_CH0_P_DY PWM1_OC |= 0X40    

#define  PWM1_CH1_N_DY PWM1_OC &= 0X7f  
#define  PWM1_CH1_P_DY PWM1_OC |= 0X80    

//PWM2
#define  PWM2_MD_DIS   PWM2_C &= 0Xfc
#define  PWM2_MD_EN    PWM2_C &= 0Xfc;    PWM2_C |= 0X01 

#define  PWM2_TMR0_S   PWM2_C &= 0Xf3
#define  PWM2_TMR1_S   PWM2_C &= 0Xf3;    PWM2_C |= 0X04
#define  PWM2_TMR2_S   PWM2_C &= 0Xf3;    PWM2_C |= 0X08
#define  PWM2_TMR3_S   PWM2_C &= 0Xf3;    PWM2_C |= 0X0c

#define  PWM2_NOR_MD   PWM2_C &= 0Xcf
#define  PWM2_PH_MD    PWM2_C |= 0X30

#define  PWM2_STP_DIS  PWM2_C &= 0X3f
#define  PWM2_STP_LV   PWM2_C &= 0X3f;    PWM2_C |= 0x40
#define  PWM2_STP_SOFT PWM2_C |= 0xc0

#define  PWM2_CH0_POS  PWM2_OC &= 0xec;   PWM2_OC |= 0x11;
#define  PWM2_CH0_NEG  PWM2_OC &= 0xec;   PWM2_OC |= 0x02;

#define  PWM2_CH1_POS  PWM2_OC &= 0xd3;   PWM2_OC |= 0x24;
#define  PWM2_CH1_NEG  PWM2_OC &= 0xd3;   PWM2_OC |= 0x08;

#define  PWM2_CH0_N_DY PWM2_OC &= 0XBf  
#define  PWM2_CH0_P_DY PWM2_OC |= 0X40    

#define  PWM2_CH1_N_DY PWM2_OC &= 0X7f  
#define  PWM2_CH1_P_DY PWM2_OC |= 0X80    


//UART TX
#define  UART_TX_DIS       UART_TXC = 0X00
#define  UART_TX8_1S       UART_TXC = 0X02
#define  UART_TX8_2S       UART_TXC = 0X0a

#define  UART_TX9_1S_ODD   UART_TXC = 0X06
#define  UART_TX9_2S_ODD   UART_TXC = 0X0e

#define  UART_TX9_1S_EVEN  UART_TXC = 0X16
#define  UART_TX9_2S_EVEN  UART_TXC = 0X1e

#define  UART_TX9_1S_D0    UART_TXC = 0X26
#define  UART_TX9_2S_D0    UART_TXC = 0X2e

#define  UART_TX9_1S_D1    UART_TXC = 0X26
#define  UART_TX9_2S_D1    UART_TXC = 0X2e

//UART RX
#define  UART_RX_DIS       UART_RXC = 0X00

#define  UART_RX8          UART_RXC = 0X01
#define  UART_RX9_D        UART_RXC = 0X02
#define  UART_RX9_ODD      UART_RXC = 0X03
#define  UART_RX9_EVEN     UART_RXC = 0X0b

#define  UART_TXM_DIS      UART_TXM &= 0X3f
#define  UART_TXM_H        UART_TXM &= 0X3f;   UART_TXM |= 0X40
#define  UART_TXM_L        UART_TXM &= 0X3f;   UART_TXM |= 0X80

//iic
#define   IIC_FLT_1         IIC_C0 &= 0X0F          
#define   IIC_FLT_2         IIC_C0 &= 0X0F;     IIC_C0 |= 0X10          
#define   IIC_FLT_3         IIC_C0 &= 0X0F;     IIC_C0 |= 0X20          
#define   IIC_FLT_4         IIC_C0 &= 0X0F;     IIC_C0 |= 0X30          
#define   IIC_FLT_5         IIC_C0 &= 0X0F;     IIC_C0 |= 0X40          
#define   IIC_FLT_6         IIC_C0 &= 0X0F;     IIC_C0 |= 0X50          
#define   IIC_FLT_7         IIC_C0 &= 0X0F;     IIC_C0 |= 0X60          
#define   IIC_FLT_8         IIC_C0 &= 0X0F;     IIC_C0 |= 0X70          
#define   IIC_FLT_9         IIC_C0 &= 0X0F;     IIC_C0 |= 0X80          
#define   IIC_FLT_10        IIC_C0 &= 0X0F;     IIC_C0 |= 0X90          
#define   IIC_FLT_11        IIC_C0 &= 0X0F;     IIC_C0 |= 0Xa0          
#define   IIC_FLT_12        IIC_C0 &= 0X0F;     IIC_C0 |= 0Xb0          
#define   IIC_FLT_13        IIC_C0 &= 0X0F;     IIC_C0 |= 0Xc0          
#define   IIC_FLT_14        IIC_C0 &= 0X0F;     IIC_C0 |= 0Xd0          
#define   IIC_FLT_15        IIC_C0 &= 0X0F;     IIC_C0 |= 0Xe0          
#define   IIC_FLT_16        IIC_C0 &= 0X0F;     IIC_C0 |= 0Xf0          

#define   IIC_SSINT_EN      IIC_C0 &= 0xf7     //start stop 产生中断
#define   IIC_SSINT_DIS     IIC_C0 |= 0x08     //start stop 不产生中断

#define   IIC_DIS           IIC_C0 &= 0xf8
#define   IIC_M_MD          IIC_C0 &= 0xf8;     IIC_C0 |= 0x01
#define   IIC_M_WT_MD       IIC_C0 &= 0xf8;     IIC_C0 |= 0x05

#define   IIC_S_MD          IIC_C0 &= 0xf8;     IIC_C0 |= 0x03
#define   IIC_S_WT_MD       IIC_C0 &= 0xf8;     IIC_C0 |= 0x07

//#define   IIC_START_TG      IIC_C1 |= 0X04;     while((IIC_C1&0x04)==0x04){}
//#define   IIC_STOP_TG       IIC_C1 |= 0X08;     while((IIC_C1&0x08)==0x08){}

#define   IIC_ACK_TG        IIC_C1 &= 0XFE
#define   IIC_NACK_TG       IIC_C1 |= 0X01

#define   IIC_WAIT_CLR      IIC_C1 |= 0X02

#define   IIC_OV_DIS        IIC_TOC = 0X00
#define   IIC_OV_D64        IIC_TOC = 0X80
#define   IIC_OV_D128       IIC_TOC = 0X81
#define   IIC_OV_D256       IIC_TOC = 0X83
#define   IIC_OV_D512       IIC_TOC = 0X87
#define   IIC_OV_D1024      IIC_TOC = 0X8f
#define   IIC_OV_D2048      IIC_TOC = 0X9f
#define   IIC_OV_D4096      IIC_TOC = 0Xaf
#define   IIC_OV_D8192      IIC_TOC = 0Xbf

//ADC
#define    ADC_EN           ADC_C0 |= 0x80;   ADC_C2 |=0x08 
#define    ADC_DIS          ADC_C0 &= 0x7f;   ADC_C2 &=0xf7 
#define    ADC_TG           ADC_C0 |= 0x40

#define    ADC_P21_AN0      ADC_C0 = 0X80
#define    ADC_P20_AN1      ADC_C0 = 0X81 
#define    ADC_P17_AN2      ADC_C0 = 0X82 
#define    ADC_P16_AN3      ADC_C0 = 0X83
#define    ADC_P15_AN4      ADC_C0 = 0X84
#define    ADC_P14_AN5      ADC_C0 = 0X85
#define    ADC_P13_AN6      ADC_C0 = 0X86
#define    ADC_P12_AN7      ADC_C0 = 0X87
#define    ADC_P11_AN8      ADC_C0 = 0X88
#define    ADC_P10_AN9      ADC_C0 = 0X89
#define    ADC_P07_AN10     ADC_C0 = 0X8a
#define    ADC_TEMP_AN11    ADC_C0 = 0X8b
#define    ADC_DIV2VDD      ADC_C0 = 0X8c
#define    ADC_DIV4VDD      ADC_C0 = 0X8d
#define    ADC_AN_DIS       ADC_C0 = 0X8f

#define    ADC_5V_SET       ADC_C1 |= 0X08
#define    ADC_3P3V_SET     ADC_C1 &= 0XF7;   VREF_C = 0XEB 

#define    ADC_RVDD         ADC_C1 &= 0x0c;   ADC_C1 |= 0X12; ADC_C2 = 0Xeb
#define    ADC_RVDD_AVG1    ADC_C1 &= 0x0c;   ADC_C1 |= 0X12; ADC_C2 = 0Xcb
#define    ADC_RVDD_AVG2    ADC_C1 &= 0x0c;   ADC_C1 |= 0X12; ADC_C2 = 0Xdb
#define    ADC_RVDD_AVG4    ADC_C1 &= 0x0c;   ADC_C1 |= 0X12; ADC_C2 = 0Xeb
#define    ADC_RVDD_AVG8    ADC_C1 &= 0x0c;   ADC_C1 |= 0X12; ADC_C2 = 0Xfb

#define    ADC_RVREF25      ADC_C1 &= 0x0c;   ADC_C1 |= 0X42; ADC_C2 = 0Xeb; VREF_C = 0XEB
#define    ADC_RVREF25_AVG1 ADC_C1 &= 0x0c;   ADC_C1 |= 0X42; ADC_C2 = 0Xcb; VREF_C = 0XEB
#define    ADC_RVREF25_AVG2 ADC_C1 &= 0x0c;   ADC_C1 |= 0X42; ADC_C2 = 0Xdb; VREF_C = 0XEB
#define    ADC_RVREF25_AVG4 ADC_C1 &= 0x0c;   ADC_C1 |= 0X42; ADC_C2 = 0Xeb; VREF_C = 0XEB
#define    ADC_RVREF25_AVG8 ADC_C1 &= 0x0c;   ADC_C1 |= 0X42; ADC_C2 = 0Xfb; VREF_C = 0XEB

#define    ADC_RVREF20      ADC_C1 &= 0x0c;   ADC_C1 |= 0X52; ADC_C2 = 0Xeb; VREF_C = 0XEB
#define    ADC_RVREF20_AVG1 ADC_C1 &= 0x0c;   ADC_C1 |= 0X52; ADC_C2 = 0Xcb; VREF_C = 0XEB
#define    ADC_RVREF20_AVG2 ADC_C1 &= 0x0c;   ADC_C1 |= 0X52; ADC_C2 = 0Xdb; VREF_C = 0XEB
#define    ADC_RVREF20_AVG4 ADC_C1 &= 0x0c;   ADC_C1 |= 0X52; ADC_C2 = 0Xeb; VREF_C = 0XEB
#define    ADC_RVREF20_AVG8 ADC_C1 &= 0x0c;   ADC_C1 |= 0X52; ADC_C2 = 0Xfb; VREF_C = 0XEB

#define    ADC_RVDD_2       ADC_C1 &= 0x0c;   ADC_C1 |= 0X62; ADC_C2 = 0Xeb
#define    ADC_RVDD_2_AVG1  ADC_C1 &= 0x0c;   ADC_C1 |= 0X62; ADC_C2 = 0Xcb
#define    ADC_RVDD_2_AVG2  ADC_C1 &= 0x0c;   ADC_C1 |= 0X62; ADC_C2 = 0Xdb
#define    ADC_RVDD_2_AVG4  ADC_C1 &= 0x0c;   ADC_C1 |= 0X62; ADC_C2 = 0Xeb
#define    ADC_RVDD_2_AVG8  ADC_C1 &= 0x0c;   ADC_C1 |= 0X62; ADC_C2 = 0Xfb

#define    ADC_RVDD_4       ADC_C1 &= 0x0c;   ADC_C1 |= 0X72; ADC_C2 = 0Xeb
#define    ADC_RVDD_4_AVG1  ADC_C1 &= 0x0c;   ADC_C1 |= 0X72; ADC_C2 = 0Xcb
#define    ADC_RVDD_4_AVG2  ADC_C1 &= 0x0c;   ADC_C1 |= 0X72; ADC_C2 = 0Xdb
#define    ADC_RVDD_4_AVG4  ADC_C1 &= 0x0c;   ADC_C1 |= 0X72; ADC_C2 = 0Xeb
#define    ADC_RVDD_4_AVG8  ADC_C1 &= 0x0c;   ADC_C1 |= 0X72; ADC_C2 = 0Xfb

#define    ADC_RVREFP       ADC_C1 &= 0x0c;   ADC_C1 |= 0X82; ADC_C2 = 0Xeb
#define    ADC_RVREFP_AVG1  ADC_C1 &= 0x0c;   ADC_C1 |= 0X82; ADC_C2 = 0Xcb
#define    ADC_RVREFP_AVG2  ADC_C1 &= 0x0c;   ADC_C1 |= 0X82; ADC_C2 = 0Xdb
#define    ADC_RVREFP_AVG4  ADC_C1 &= 0x0c;   ADC_C1 |= 0X82; ADC_C2 = 0Xeb
#define    ADC_RVREFP_AVG8  ADC_C1 &= 0x0c;   ADC_C1 |= 0X82; ADC_C2 = 0Xfb

//VREF
#define  VREF_EN  VREF_C = 0XEB
#define  TK_VREF_EN  TK_VREF_C = 0X08


#define    LVD_EN      LVD_C0 |= 0X80
#define    LVD_DIS     LVD_C0 &= 0X7f

#define    LVD_FLT_EN  LVD_C0 |= 0X20
#define    LVD_FLT_DIS LVD_C0 &= 0Xdf

#define    LVD_CLK_LRC   LVD_C0 |= 0X10
#define    LVD_CLK_SYS   LVD_C0 &= 0Xef

#define    LVD_VDD_2P2 LVD_C0 = 0XA0
#define    LVD_VDD_2P5 LVD_C0 = 0XA1
#define    LVD_VDD_2P8 LVD_C0 = 0XA2
#define    LVD_VDD_3P1 LVD_C0 = 0XA3
#define    LVD_VDD_3P4 LVD_C0 = 0XA4
#define    LVD_VDD_3P7 LVD_C0 = 0XA5
#define    LVD_VDD_4P0 LVD_C0 = 0XA6
#define    LVD_VDD_4P3 LVD_C0 = 0XA7

#define    LVD_LVD_IN_1P25 LVD_C0 = 0XA8

#endif
