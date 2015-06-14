/******************************************************************
*    			STC-51��/STC-51 library file
*
*�ļ���/file    : c51_soc.h
*
*����/function  : C51��ϵͳ�����ļ�/system statement file
*
*Э��/licence   : GPL��Դ/open GPL
*
*����/author    : J.H.Chen
*
*ʱ��/time      : 2015-05-28
*
*˵��/other     : none
******************************************************************/
#ifndef __SOC_C51_H
#define __SOC_C51_H


//**----------------------------------------------------------
//**--CPU�ж�������,�����޸�
#define  VECTOR_INT0     0    //�ⲿ�ж�0
#define  VECTOR_TIM0     1    //��ʱ���ж�0
#define  VECTOR_INT1     2    //�ⲿ�ж�1
#define  VECTOR_TIM1     3    //��ʱ���ж�1
#define  VECTOR_S1       4    //�����ж�1
#define  VECTOR_ADC      5    //ADC�ж�
#define  VECTOR_LVD      6    //��ѹ�����ж�
#define  VECTOR_PCA      7    //PCA�ж�
#define  VECTOR_S2       8    //�����ж�2
#define  VECTOR_SPI      9    //SPI�ж�
#define  VECTOR_INT2     10   //�ⲿ�ж�2
#define  VECTOR_INT3     11   //�ⲿ�ж�3
#define  VECTOR_TIM2     12   //��ʱ���ж�2
#define  VECTOR_INT4     16   //�ⲿ�ж�4
#define  VECTOR_S3       17   //�����ж�3
#define  VECTOR_S4       18   //�����ж�4
#define  VECTOR_TIM3     19   //��ʱ���ж�3
#define  VECTOR_TIM4     20   //��ʱ���ж�4
#define  VECTOR_COMPT    21   //�Ƚ����ж�
#define  VECTOR_PWM      22   //PWM�ж�

#endif