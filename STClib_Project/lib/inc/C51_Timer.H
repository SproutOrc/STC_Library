/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_timer.h
*
*功能/function  : C51库定时器文件
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-06-10
*
*说明/other     : 定时器使用定时器0
******************************************************************/
#ifndef __TIMER_C51_H
#define	__TIMER_C51_H

#include "stdint.h"
#include "sys_type.h"

typedef enum
{
	Timer_Status_close,    //关闭
	Timer_Status_once,     //单次启动
	Timer_Status_repeat = 0xFF,   //重复定时
}Timer_Status_Def;

typedef void sysTimer0Func(uint8 timer_arg);

typedef struct _Timer0_t_
{
	struct _Timer0_t_   *next;     //
	uint32               period;   //周期
	uint32               cnt;      //计数器
	Timer_Status_Def     Timer_Status; //状态
	sysTimer0Func       *Timer0Func;   //功能
	uint8                timer_arg;    //参数
}timer0_t;




void timer0init();

void delay_ms(uint16 ms);

void timer_disarm(timer0_t *timer);

void timer_setfn(timer0_t *timer, sysTimer0Func *timerfn, uint8 timer_arg);

void timer_arm(timer0_t *timer, uint32 period, Timer_Status_Def Timer_Status);

#endif