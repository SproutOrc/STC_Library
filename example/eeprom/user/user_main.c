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
#include <string.h>


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


/******************************************************
 * FunctionName : user_application
 * Description  : 用户APP程序段
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_application()
{
	char buf[64];
	memset(buf,0,64);
	memcpy(buf,"Hello EEPROM..\n",15);
	EEPROM_SectorErase(0);  //擦除扇区0
	EEPROM_write(0,buf,15); //写EEPROM
	delay_ms(2000);  //延时
	memset(buf,0,64); //清空buf
	EEPROM_read(0,buf,15); //读取EEPROM
	UartwriteStr(buf,0);  //通过串口发送读取内容
	while(true)
	{
	}
}