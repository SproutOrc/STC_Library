/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_gpio.h
*
*功能/function  : C51库GPIO操作文件
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-06-10
*
*说明/other     : none
******************************************************************/
#include "C51_Lib.h"

#ifdef LIB_GPIO_USE
/******************************************************
 * FunctionName : GPIO_Init
 * Description  : GPIO初始化
 * Parameters   : GPIO--指定端口,P0~P5 
                  GPIO_InitStruct--初始化类型
 * Returns      : none
******************************************************/
void GPIO_Init(uint8 GPIO, GPIO_InitTypeDef* GPIO_InitStruct)
{
	if(!IS_GPIO_TYPE(GPIO))
		return;
	if(!IS_GPIOMode_Type(GPIO_InitStruct->GPIO_Mode))
		return;
	
	switch(GPIO)
	{
		case GPIO_P0:
		{
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_PullUp)		P0M1 &= ~GPIO_InitStruct->GPIO_Pin,	P0M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //上拉准双向口
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_FLOATING)	P0M1 |=  GPIO_InitStruct->GPIO_Pin,	P0M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //浮空输入
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_OD)		P0M1 |=  GPIO_InitStruct->GPIO_Pin,	P0M0 |=  GPIO_InitStruct->GPIO_Pin;	 //开漏输出
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_PP)		P0M1 &= ~GPIO_InitStruct->GPIO_Pin,	P0M0 |=  GPIO_InitStruct->GPIO_Pin;	 //推挽输出
		}
		break;
		
		case GPIO_P1:
		{
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_PullUp)		P1M1 &= ~GPIO_InitStruct->GPIO_Pin,	P1M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //上拉准双向口
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_FLOATING)	P1M1 |=  GPIO_InitStruct->GPIO_Pin,	P1M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //浮空输入
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_OD)		P1M1 |=  GPIO_InitStruct->GPIO_Pin,	P1M0 |=  GPIO_InitStruct->GPIO_Pin;	 //开漏输出
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_PP)		P1M1 &= ~GPIO_InitStruct->GPIO_Pin,	P1M0 |=  GPIO_InitStruct->GPIO_Pin;	 //推挽输出
		}
		break;
		
		case GPIO_P2:
		{
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_PullUp)		P2M1 &= ~GPIO_InitStruct->GPIO_Pin,	P2M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //上拉准双向口
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_FLOATING)	P2M1 |=  GPIO_InitStruct->GPIO_Pin,	P2M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //浮空输入
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_OD)		P2M1 |=  GPIO_InitStruct->GPIO_Pin,	P2M0 |=  GPIO_InitStruct->GPIO_Pin;	 //开漏输出
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_PP)		P2M1 &= ~GPIO_InitStruct->GPIO_Pin,	P2M0 |=  GPIO_InitStruct->GPIO_Pin;	 //推挽输出
		}
		break;
		
		case GPIO_P3:
		{
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_PullUp)		P3M1 &= ~GPIO_InitStruct->GPIO_Pin,	P3M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //上拉准双向口
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_FLOATING)	P3M1 |=  GPIO_InitStruct->GPIO_Pin,	P3M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //浮空输入
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_OD)		P3M1 |=  GPIO_InitStruct->GPIO_Pin,	P3M0 |=  GPIO_InitStruct->GPIO_Pin;	 //开漏输出
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_PP)		P3M1 &= ~GPIO_InitStruct->GPIO_Pin,	P3M0 |=  GPIO_InitStruct->GPIO_Pin;	 //推挽输出
		}
		break;
		
		case GPIO_P4:
		{
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_PullUp)		P4M1 &= ~GPIO_InitStruct->GPIO_Pin,	P4M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //上拉准双向口
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_FLOATING)	P4M1 |=  GPIO_InitStruct->GPIO_Pin,	P4M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //浮空输入
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_OD)		P4M1 |=  GPIO_InitStruct->GPIO_Pin,	P4M0 |=  GPIO_InitStruct->GPIO_Pin;	 //开漏输出
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_PP)		P4M1 &= ~GPIO_InitStruct->GPIO_Pin,	P4M0 |=  GPIO_InitStruct->GPIO_Pin;	 //推挽输出
		}
		break;
		
		case GPIO_P5:
		{
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_PullUp)		P5M1 &= ~GPIO_InitStruct->GPIO_Pin,	P5M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //上拉准双向口
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_FLOATING)	P5M1 |=  GPIO_InitStruct->GPIO_Pin,	P5M0 &= ~GPIO_InitStruct->GPIO_Pin;	 //浮空输入
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_OD)		P5M1 |=  GPIO_InitStruct->GPIO_Pin,	P5M0 |=  GPIO_InitStruct->GPIO_Pin;	 //开漏输出
			if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_Out_PP)		P5M1 &= ~GPIO_InitStruct->GPIO_Pin,	P5M0 |=  GPIO_InitStruct->GPIO_Pin;	 //推挽输出
		}
		break;
	}
}
#endif