/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : user_main.c
*
*功能/function  : C51库用户文件/user file
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-05-28
*
*说明/other     : 此文件编写用户程序逻辑
                  user application in this file
******************************************************************/
#include "C51_Lib.h"


/******************************************************
 * FunctionName : user_init
 * Description  : 初始化函数,用于系统初始化
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_init()
{
	UartInit(115200);
}

void uart_fn(uint8 arg)
{
	UartwriteStr("Hello STClib..\n",0);
}


/******************************************************
 * FunctionName : user_application
 * Description  : 用户APP程序段
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_application()
{
	timer0_t timer_led;
	timer_disarm(&timer_led);
	timer_setfn(&timer_led,(sysTimer0Func)uart_fn,1);
	timer_arm(&timer_led,1000,Timer_Status_repeat);
	while(true)
	{
	}
}