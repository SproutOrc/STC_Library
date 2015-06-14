/******************************************************************
*    			STC-51��/STC-51 library file
*
*�ļ���/file    : user_main.c
*
*����/function  : C51���û��ļ�/user file
*
*Э��/licence   : GPL��Դ/open GPL
*
*����/author    : J.H.Chen
*
*ʱ��/time      : 2015-05-28
*
*˵��/other     : ���ļ���д�û������߼�
                  user application in this file
******************************************************************/
#include "C51_Lib.h"


/******************************************************
 * FunctionName : user_init
 * Description  : ��ʼ������,����ϵͳ��ʼ��
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
 * Description  : �û�APP�����
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