#ifndef   __Custom_H__
#define   __Custom_H__
//
/*  BYTE Registers  */
//Core Register
sfr      ACC      = 0xE0;
sfr      B        = 0xF0;
sfr      SP       = 0x81;
sfr      DPL      = 0x82;
sfr      DPH      = 0x83;
sfr      PSW      = 0xD0;
//Peripheral Register
sfr      PCON     = 0x87;
sfr      RST_FLAG = 0xC8;
sfr      INTn_IE  = 0xE8;
sfr      INTn_IF  = 0x88;
sfr      INTn_IP  = 0xF8;
sfr      WDT_C    = 0x84;
sfr      WDT_OP   = 0x85;
sfr      PORT_C0  = 0x8E;
sfr      P0_IE    = 0x8F;
sfr      P0_OE    = 0x8F;
sfr      P1_IE    = 0x91;
sfr      P1_OE    = 0x91;
sfr      P2_IE    = 0x92;
sfr      P2_OE    = 0x92;
sfr      P0_DAT   = 0x80;
sfr      P1_DAT   = 0x90;
sfr      P2_DAT   = 0xA0;
sfr      P0_PUE   = 0x94;
sfr      P0_PDE   = 0x94;
sfr      P1_PUE   = 0x95;
sfr      P1_PDE   = 0x95;
sfr      P2_PUE   = 0x96;
sfr      P2_PDE   = 0x96;
sfr      P0_ODE   = 0x97;
sfr      P1_ODE   = 0x97;
sfr      P2_ODE   = 0x97;
sfr      P0_FUNL  = 0x9A;
sfr      P0_FUNH  = 0x9B;
sfr      P1_FUNL  = 0x9C;
sfr      P1_FUNH  = 0x9D;
sfr      P2_FUNL  = 0x9E;
sfr      EINTn_IE = 0x9F;
sfr      EINTn_IF = 0x98;
sfr      EINT_MSL = 0xA1;
sfr      EINT_MSH = 0xA2;
sfr      EINT_IOS = 0xA3;
sfr      TMRn_IE  = 0xBF;
sfr      TMRn_IF  = 0xA8;
sfr      PWMn_IE  = 0xD9;
sfr      CAPn_IE  = 0xD9;
sfr      PWMn_IF  = 0xB0;
sfr      CAPn_IF  = 0xB0;
sfr      UARTn_IE = 0xE7;
sfr      IICn_IE  = 0xE7;
sfr      SPIn_IE  = 0xE7;
sfr      UARTn_IF = 0xB8;
sfr      IICn_IF  = 0xB8;
sfr      SPIn_IF  = 0xB8;
sfr      AN_IE    = 0xFF;
sfr      AN_IF    = 0xC0;
sfr      HRC_TRML = 0x89;
sfr      HRC_TRMH = 0x8A;
sfr      TMR0_C0  = 0xA4;
sfr      TMR0_C1  = 0xA5;
sfr      TMR0L    = 0xA6;
sfr      TMR0H    = 0xA7;
sfr      TMR0_CYL = 0xA9;
sfr      TMR0_CYH = 0xAA;
sfr      TMR1_C0  = 0xAB;
sfr      TMR1_C1  = 0xAC;
sfr      TMR1L    = 0xAD;
sfr      TMR1H    = 0xAE;
sfr      TMR1_CYL = 0xAF;
sfr      TMR1_CYH = 0xB1;
sfr      TMR2_C0  = 0xB2;
sfr      TMR2_C1  = 0xB3;
sfr      TMR2L    = 0xB4;
sfr      TMR2H    = 0xB5;
sfr      TMR2_CYL = 0xB6;
sfr      TMR2_CYH = 0xB7;
sfr      TMR3_C0  = 0xB9;
sfr      TMR3_C1  = 0xBA;
sfr      TMR3L    = 0xBB;
sfr      TMR3H    = 0xBC;
sfr      TMR3_CYL = 0xBD;
sfr      TMR3_CYH = 0xBE;
sfr      PWM0_C   = 0xC1;
sfr      CAP0_C   = 0xC1;
sfr      PWM0_OC  = 0xC2;
sfr      PWM0_R0L = 0xC3;
sfr      CAP0_DL  = 0xC3;
sfr      PWM0_R0H = 0xC4;
sfr      CAP0_DH  = 0xC4;
sfr      PWM0_R1L = 0xC5;
sfr      PWM0_R1H = 0xC6;
sfr      PWM0_DT  = 0xC7;
sfr      PWM1_C   = 0xC9;
sfr      CAP1_C   = 0xC9;
sfr      PWM1_OC  = 0xCA;
sfr      PWM1_R0L = 0xCB;
sfr      CAP1_DL  = 0xCB;
sfr      PWM1_R0H = 0xCC;
sfr      CAP1_DH  = 0xCC;
sfr      PWM1_R1L = 0xCD;
sfr      PWM1_R1H = 0xCE;
sfr      PWM1_DT  = 0xCF;
sfr      PWM2_C   = 0xD1;
sfr      CAP2_C   = 0xD1;
sfr      PWM2_OC  = 0xD2;
sfr      PWM2_R0L = 0xD3;
sfr      CAP2_DL  = 0xD3;
sfr      PWM2_R0H = 0xD4;
sfr      CAP2_DH  = 0xD4;
sfr      PWM2_R1L = 0xD5;
sfr      PWM2_R1H = 0xD6;
sfr      PWM2_DT  = 0xD7;
sfr      UART_BRL = 0xDA;
sfr      UART_BRH = 0xDB;
sfr      UART_RXC = 0xDC;
sfr      UART_RXB = 0xDD;
sfr      UART_TXC = 0xDE;
sfr      UART_TXB = 0xDF;
sfr      UART_TXM = 0x8E;
sfr      IIC_C0   = 0xE1;
sfr      IIC_C1   = 0xE2;
sfr      IIC_STA  = 0xE3;
sfr      IIC_ADDR = 0xE4;
sfr      IIC_DATA = 0xE5;
sfr      IIC_BRR  = 0xE4;
sfr      IIC_TOC  = 0xE6;
sfr      SPI_C0   = 0x86;
sfr      SPI_C1   = 0x8B;
sfr      SPI_DATA = 0x8C;
sfr      LVD_C0   = 0xEC;
sfr      ADC_C0   = 0xFA;
sfr      ADC_C1   = 0xFB;
sfr      ADC_C2   = 0xFC;
sfr      ADC_DL   = 0xFD;
sfr      ADC_DH   = 0xFE;
sfr      ADC_CMP_C= 0xF7;
sfr      VREF_C   = 0xF6;
sfr      TK_VREF_C= 0xED;
sfr      TK_C0    = 0xEF;
sfr      TK_C1    = 0xEE;
sfr      TK_C2    = 0xF1;
sfr      TK_CHEL  = 0xF2;
sfr      TK_CHEH  = 0xF3;
sfr      TK_CNTL  = 0xF4;
sfr      TK_CNTH  = 0xF5;

sfr      ACP_C0   = 0xED;
sfr      ACP_C1   = 0xEE;
sfr      ACP_C2   = 0xF1;

////System Register
#define IAP_PR    *((unsigned char xdata *)(0x9000))
#define IAP_AS    *((unsigned char xdata *)(0x9001))
#define IAP_AL    *((unsigned char xdata *)(0x9002))
#define IAP_AH    *((unsigned char xdata *)(0x9003))
#define IAP_D     *((unsigned char xdata *)(0x9004))
#define IAP_C0    *((unsigned char xdata *)(0x9005))
#define IAP_C1    *((unsigned char xdata *)(0x9006))
#define CLK_PR    *((unsigned char xdata *)(0x9020))
#define CLK_C0    *((unsigned char xdata *)(0x9021))
#define CLK_C1    *((unsigned char xdata *)(0x9022))
#define PCK_GTC0  *((unsigned char xdata *)(0x9023))
#define PCK_GTC1  *((unsigned char xdata *)(0x9024))
#define CCM_C     *((unsigned char xdata *)(0x9025))
#define CLK_LP    *((unsigned char xdata *)(0x9026))
#define WKUP_T    *((unsigned char xdata *)(0x9027))


#define CAL_PR      *((unsigned char xdata *)(0x9080))
#define IBCAL       *((unsigned char xdata *)(0x9081))
#define VBGCALV     *((unsigned char xdata *)(0x9082))
#define LDOCAL      *((unsigned char xdata *)(0x9083))
#define VBGCALTC    *((unsigned char xdata *)(0x9084))
#define LLDOCAL     *((unsigned char xdata *)(0x9085))
#define VREF_BGCAL  *((unsigned char xdata *)(0x9087))
#define VREF_LDOCAL *((unsigned char xdata *)(0x9088))
#define VREF_TSCAL  *((unsigned char xdata *)(0x908a))
#define ACP_OS      *((unsigned char xdata *)(0x908b))
#define INTOSC_CAP  *((unsigned char xdata *)(0x908c))
#define WDTCAL      *((unsigned char xdata *)(0x908d))

#define TEST_PR     *((unsigned char xdata *)(0x9090))
#define TEST_MODE0  *((unsigned char xdata *)(0x9091))
#define TEST_MODE1  *((unsigned char xdata *)(0x9092))
#define CLK_CAL_C0  *((unsigned char xdata *)(0x9093))
#define CLK_CAL_C1  *((unsigned char xdata *)(0x9094))

////Bit Opteration Mapped
//IO
sbit  P0_0               =     P0_DAT^0;
sbit  P0_1               =     P0_DAT^1;
sbit  P0_2               =     P0_DAT^2;
sbit  P0_3               =     P0_DAT^3;
sbit  P0_4               =     P0_DAT^4;
sbit  P0_5               =     P0_DAT^5;
sbit  P0_6               =     P0_DAT^6;
sbit  P0_7               =     P0_DAT^7;
                         
sbit  P1_0               =     P1_DAT^0;
sbit  P1_1               =     P1_DAT^1;
sbit  P1_2               =     P1_DAT^2;
sbit  P1_3               =     P1_DAT^3;
sbit  P1_4               =     P1_DAT^4;
sbit  P1_5               =     P1_DAT^5;
sbit  P1_6               =     P1_DAT^6;
sbit  P1_7               =     P1_DAT^7;
                         
sbit  P2_0               =     P2_DAT^0;
sbit  P2_1               =     P2_DAT^1;





//INT_IF
sbit  INT6_IF            =     INTn_IF^6;
sbit  INT5_IF            =     INTn_IF^5;
sbit  INT4_IF            =     INTn_IF^4;
sbit  INT3_IF            =     INTn_IF^3;
sbit  INT2_IF            =     INTn_IF^2;
sbit  INT1_IF            =     INTn_IF^1;
sbit  INT0_IF            =     INTn_IF^0;

//TMR_IF
sbit  TMR0_IF            =     TMRn_IF^0;
sbit  TMR1_IF            =     TMRn_IF^1;
sbit  TMR2_IF            =     TMRn_IF^2;
sbit  TMR3_IF            =     TMRn_IF^3;

//PWM_IF
sbit  PWM0_IF            =     PWMn_IF^0;
sbit  PWM1_IF            =     PWMn_IF^1;
sbit  PWM2_IF            =     PWMn_IF^2;
sbit  STP0_IF            =     PWMn_IF^4;
sbit  STP1_IF            =     PWMn_IF^5;
sbit  STP2_IF            =     PWMn_IF^6;

//CAP_IF
sbit  CAP0_IF            =     CAPn_IF^0;
sbit  CAP1_IF            =     CAPn_IF^1;
sbit  CAP2_IF            =     CAPn_IF^2;
//UART_IF
sbit  TX_IF              =     UARTn_IF^1;
sbit  RX_IF              =     UARTn_IF^0;
//IIC_IF
sbit  IIC_IF             =     IICn_IF^4;
//SPI_IF
sbit  SPI_IF             =     SPIn_IF^6;
//AN_IF
sbit  CCM_IF             =     AN_IF^6;
sbit  LVD_IF             =     AN_IF^4;
sbit  ADC_IF             =     AN_IF^2;
sbit  TK_IF              =     AN_IF^0;
sbit  ACP_IF              =     AN_IF^0;
//RST_FLAG
sbit  ROM_OV             =     RST_FLAG^4;
sbit  RSTN_F             =     RST_FLAG^3;
sbit  SRST_F             =     RST_FLAG^2;
sbit  WDTR_F             =     RST_FLAG^1;
sbit  POR_F              =     RST_FLAG^0;
//PSW
sbit  CY                 =     PSW^7;
sbit  AC                 =     PSW^6;
sbit  F0                 =     PSW^5;
sbit  RS1                =     PSW^4;
sbit  RS0                =     PSW^3;
sbit  OV                 =     PSW^2;
sbit  P                  =     PSW^0;
//ACC
//INT_IE
sbit  GIE                =     INTn_IE^7;
sbit  INT6_IE            =     INTn_IE^6;
sbit  INT5_IE            =     INTn_IE^5;
sbit  INT4_IE            =     INTn_IE^4;
sbit  INT3_IE            =     INTn_IE^3;
sbit  INT2_IE            =     INTn_IE^2;
sbit  INT1_IE            =     INTn_IE^1;
sbit  INT0_IE            =     INTn_IE^0;
//B
//INT_IP
sbit  INT6_IP            =     INTn_IP^6;
sbit  INT5_IP            =     INTn_IP^5;
sbit  INT4_IP            =     INTn_IP^4;
sbit  INT3_IP            =     INTn_IP^3;
sbit  INT2_IP            =     INTn_IP^2;
sbit  INT1_IP            =     INTn_IP^1;
sbit  INT0_IP            =     INTn_IP^0;
//
sbit  EINT0_IF           =     EINTn_IF^0;
sbit  EINT1_IF           =     EINTn_IF^1;
sbit  EINT2_IF           =     EINTn_IF^2;
sbit  EINT3_IF           =     EINTn_IF^3;
sbit  EINT4_IF           =     EINTn_IF^4;
sbit  EINT5_IF           =     EINTn_IF^5;
sbit  EINT6_IF           =     EINTn_IF^6;
sbit  EINT7_IF           =     EINTn_IF^7;

//
#endif

