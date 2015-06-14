/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : C51_ADC.h
*
*功能/function  : C51库ADC文件/adc file
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-05-28
*
*说明/other     : 用于ADC采样
******************************************************************/
#ifndef __C51_ADC_H
#define __C51_ADC_H

#include "stdint.h"
#include "sys_type.h"


#define ADC_POWER  0X80
#define ADC_FLAG   0X10
#define ADC_START  0X08

#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7

#define ADC_SPEED_540CLOCK		0
#define ADC_SPEED_360CLOCK		1
#define ADC_SPEED_180CLOCK		2
#define ADC_SPEED_90CLOCK		  3


#ifdef LIB_ADC_USE
//读取ADC转换结果
uint16 GetADC_Result(uint8 Channel, uint8 ADC_Speed);
#endif

#endif