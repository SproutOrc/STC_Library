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

timer0_t timer_led,timer_led1;

/******************************************************
 * FunctionName : user_init
 * Description  : 初始化函数,用于系统初始化
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_init()
{
	GPIO_InitTypeDef iGPIO;
	iGPIO.GPIO_Pin = GPIO_Pin_7;
	iGPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_P3,&iGPIO);
}


//翻转led端口
void led_fn(uint8 arg)
{
	GPIO_Write_Pin(P1,GPIO_Pin_2,!GPIO_Read_Pin(P1,GPIO_Pin_2));
}

//300ms翻转LED端口
void led_fn_1(uint8 arg)
{
	GPIO_Write_Pin(P1,GPIO_Pin_2,arg);
	
	timer_disarm(&timer_led1);
	timer_setfn(&timer_led1,(sysTimer0Func)led_fn_1,arg==1?0:1);
	timer_arm(&timer_led1,300,Timer_Status_repeat);  //定时300ms,重复
}

/******************************************************
 * FunctionName : user_application
 * Description  : 用户APP程序段
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_application()
{
	
	GPIO_Write_Pin(P1,GPIO_Pin_2,0);
	GPIO_Write_Pin(P1,GPIO_Pin_3,0);
	
	timer_disarm(&timer_led);
	timer_setfn(&timer_led,(sysTimer0Func)led_fn,1);
	timer_arm(&timer_led,2000,Timer_Status_once);  //定时2000ms,不重复
	
	timer_disarm(&timer_led1);
	timer_setfn(&timer_led1,(sysTimer0Func)led_fn_1,1);
	timer_arm(&timer_led1,300,Timer_Status_repeat);  //定时300ms,重复
	
	while(true)
	{
		GPIO_Write_Pin(P3,GPIO_Pin_7,1);
		delay_ms(100);
		GPIO_Write_Pin(P3,GPIO_Pin_7,0);
		delay_ms(100);
	}
}