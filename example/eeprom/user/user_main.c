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
#include <string.h>


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


/******************************************************
 * FunctionName : user_application
 * Description  : �û�APP�����
 * Parameters   : none
 * Returns      : none
******************************************************/
void user_application()
{
	char buf[64];
	memset(buf,0,64);
	memcpy(buf,"Hello EEPROM..\n",15);
	EEPROM_SectorErase(0);  //��������0
	EEPROM_write(0,buf,15); //дEEPROM
	delay_ms(2000);  //��ʱ
	memset(buf,0,64); //���buf
	EEPROM_read(0,buf,15); //��ȡEEPROM
	UartwriteStr(buf,0);  //ͨ�����ڷ��Ͷ�ȡ����
	while(true)
	{
	}
}