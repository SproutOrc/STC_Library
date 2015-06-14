/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_soc.h
*
*功能/function  : C51库系统定义文件/system statement file
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-05-28
*
*说明/other     : none
******************************************************************/
#ifndef __SOC_C51_H
#define __SOC_C51_H


//**----------------------------------------------------------
//**--CPU中断向量表,请勿修改
#define  VECTOR_INT0     0    //外部中断0
#define  VECTOR_TIM0     1    //定时器中断0
#define  VECTOR_INT1     2    //外部中断1
#define  VECTOR_TIM1     3    //定时器中断1
#define  VECTOR_S1       4    //串口中断1
#define  VECTOR_ADC      5    //ADC中断
#define  VECTOR_LVD      6    //低压保护中断
#define  VECTOR_PCA      7    //PCA中断
#define  VECTOR_S2       8    //串口中断2
#define  VECTOR_SPI      9    //SPI中断
#define  VECTOR_INT2     10   //外部中断2
#define  VECTOR_INT3     11   //外部中断3
#define  VECTOR_TIM2     12   //定时器中断2
#define  VECTOR_INT4     16   //外部中断4
#define  VECTOR_S3       17   //串口中断3
#define  VECTOR_S4       18   //串口中断4
#define  VECTOR_TIM3     19   //定时器中断3
#define  VECTOR_TIM4     20   //定时器中断4
#define  VECTOR_COMPT    21   //比较器中断
#define  VECTOR_PWM      22   //PWM中断

#endif