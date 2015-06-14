/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : C51_conf.h
*
*功能/function  : C51库配置文件/config head file
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-05-28
*
*说明/other     : 在此文件中选择单片机型号
									to choose MCU type in this file
******************************************************************/
#ifndef __C51_CONFIG_H
#define __C51_CONFIG_H

#include "sys_type.h"

#include "C51_SOC.h"


//**----------------------------------------------------------
//**--修改一：CPU频率
#define CPU_FAN		((double)11059200)   //系统时钟频率,使用不同频率时修改
	

//**----------------------------------------------------------
//**--修改二：CPU类型,部分类型不支持
//**--注意: 型号只可以选择一个----
//#define     STC10Fxx

//#define     STC11F0xE
//#define     STC11FxxXE

#define     STC12C5Axx
//#define     STC12C52xx
//#define     STC12C56xx
//#define     STC12C54xx
//#define     STC12Cxx52

//#define     STC15F20xEA
//#define     STC15F2KxxS2
//#define     STC15F4xxAD

//#define     STC15W10x
//#define     STC15W1KxxS
//#define     STC15W1KxxPWM
//#define     STC15W1K2xS
//#define     STC15W2Kxx
//#define     STC15W4xxS
//#define     STC15W4xxAS
//#define     STC15W4KxxS4


//**----------------------------------------------------------
//**--修改三：库裁剪,不需要的库直接注销,以减小代码大小
//#define  LIB_GPIO_USE     //由于引脚的输出输入功能都使用了宏定义[见C51_GPIO.H],该库只增加了引脚功能设置,会增大526Byte的code,不建议使用
//#define  LIB_ADC_USE      //ADC库,会增大大约100Byte的code
//#define  LIB_EEPROM_USE   //EEPROM库,会增大大约300Byte的code
#define  LIB_UART_USE     //Uart库




#ifdef  EN_TYPE_SELECT
#include "c51_inc.h"
#endif


#endif