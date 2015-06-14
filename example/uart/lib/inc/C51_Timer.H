/******************************************************************
*    			STC-51��/STC-51 library file
*
*�ļ���/file    : c51_timer.h
*
*����/function  : C51�ⶨʱ���ļ�
*
*Э��/licence   : GPL��Դ/open GPL
*
*����/author    : J.H.Chen
*
*ʱ��/time      : 2015-06-10
*
*˵��/other     : ��ʱ��ʹ�ö�ʱ��0
******************************************************************/
#ifndef __TIMER_C51_H
#define	__TIMER_C51_H

#include "stdint.h"
#include "sys_type.h"

typedef enum
{
	Timer_Status_close,    //�ر�
	Timer_Status_once,     //��������
	Timer_Status_repeat = 0xFF,   //�ظ���ʱ
}Timer_Status_Def;

typedef void sysTimer0Func(uint8 timer_arg);

typedef struct _Timer0_t_
{
	struct _Timer0_t_   *next;     //
	uint32               period;   //����
	uint32               cnt;      //������
	Timer_Status_Def     Timer_Status; //״̬
	sysTimer0Func       *Timer0Func;   //����
	uint8                timer_arg;    //����
}timer0_t;




void timer0init();

void delay_ms(uint16 ms);

void timer_disarm(timer0_t *timer);

void timer_setfn(timer0_t *timer, sysTimer0Func *timerfn, uint8 timer_arg);

void timer_arm(timer0_t *timer, uint32 period, Timer_Status_Def Timer_Status);

#endif