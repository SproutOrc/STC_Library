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

timer0_t timer_led,timer_led1;

/******************************************************
 * FunctionName : user_init
 * Description  : ��ʼ������,����ϵͳ��ʼ��
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


//��תled�˿�
void led_fn(uint8 arg)
{
	GPIO_Write_Pin(P1,GPIO_Pin_2,!GPIO_Read_Pin(P1,GPIO_Pin_2));
}

//300ms��תLED�˿�
void led_fn_1(uint8 arg)
{
	GPIO_Write_Pin(P1,GPIO_Pin_2,arg);
	
	timer_disarm(&timer_led1);
	timer_setfn(&timer_led1,(sysTimer0Func)led_fn_1,arg==1?0:1);
	timer_arm(&timer_led1,300,Timer_Status_repeat);  //��ʱ300ms,�ظ�
}

/******************************************************
 * FunctionName : user_application
 * Description  : �û�APP�����
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_application()
{
	
	GPIO_Write_Pin(P1,GPIO_Pin_2,0);
	GPIO_Write_Pin(P1,GPIO_Pin_3,0);
	
	timer_disarm(&timer_led);
	timer_setfn(&timer_led,(sysTimer0Func)led_fn,1);
	timer_arm(&timer_led,2000,Timer_Status_once);  //��ʱ2000ms,���ظ�
	
	timer_disarm(&timer_led1);
	timer_setfn(&timer_led1,(sysTimer0Func)led_fn_1,1);
	timer_arm(&timer_led1,300,Timer_Status_repeat);  //��ʱ300ms,�ظ�
	
	while(true)
	{
		GPIO_Write_Pin(P3,GPIO_Pin_7,1);
		delay_ms(100);
		GPIO_Write_Pin(P3,GPIO_Pin_7,0);
		delay_ms(100);
	}
}