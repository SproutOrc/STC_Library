/******************************************************************
*    			STC-51��/STC-51 library file
*
*�ļ���/file    : C51_conf.h
*
*����/function  : C51�������ļ�/config head file
*
*Э��/licence   : GPL��Դ/open GPL
*
*����/author    : J.H.Chen
*
*ʱ��/time      : 2015-05-28
*
*˵��/other     : �ڴ��ļ���ѡ��Ƭ���ͺ�
									to choose MCU type in this file
******************************************************************/
#ifndef __C51_CONFIG_H
#define __C51_CONFIG_H

#include "sys_type.h"

#include "C51_SOC.h"


//**----------------------------------------------------------
//**--�޸�һ��CPUƵ��
#define CPU_FAN		((double)11059200)   //ϵͳʱ��Ƶ��,ʹ�ò�ͬƵ��ʱ�޸�
	

//**----------------------------------------------------------
//**--�޸Ķ���CPU����,�������Ͳ�֧��
//**--ע��: �ͺ�ֻ����ѡ��һ��----
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
//**--�޸�������ü�,����Ҫ�Ŀ�ֱ��ע��,�Լ�С�����С
//#define  LIB_GPIO_USE     //�������ŵ�������빦�ܶ�ʹ���˺궨��[��C51_GPIO.H],�ÿ�ֻ���������Ź�������,������526Byte��code,������ʹ��
//#define  LIB_ADC_USE      //ADC��,�������Լ100Byte��code
//#define  LIB_EEPROM_USE   //EEPROM��,�������Լ300Byte��code
#define  LIB_UART_USE     //Uart��




#ifdef  EN_TYPE_SELECT
#include "c51_inc.h"
#endif


#endif