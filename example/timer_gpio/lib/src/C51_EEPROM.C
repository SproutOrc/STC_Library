/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_eeprom.c
*
*功能/function  : C51库eeprom操作
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-06-12
*
*说明/other     : 
******************************************************************/
#include "C51_Lib.h"
#include <intrins.h>

#ifdef LIB_EEPROM_USE
/******************************************************
 * FunctionName : DisableEEPROM
 * Description  : 禁止访问EEPROM
 * Parameters   : none
 * Returns      : none
******************************************************/
void	EEPROM_Disable(void)
{
	IAP_CONTR = 0;			//禁止IAP/IAP操作
	IAP_CMD   = 0;			//去除IAP/IAP命令
	IAP_TRIG  = 0;			//防止IAP/IAP命令误触发
	IAP_ADDRH = 0xff;		//清0地址高字节
	IAP_ADDRL = 0xff;		//清0地址低字节，指向非EEPROM区，防止误操作
}


/******************************************************
 * FunctionName : EEPROM_read
 * Description  : EEPROM读区操作
 * Parameters   : addr--要读取地址  buf--存储缓冲区
                  num--读取字节数
 * Returns      : none
******************************************************/
void EEPROM_read(uint16 addr, uint8 *buf, uint16 num)
{
	EA = 0;	
	IAP_CONTR = ENABLE_IAP;	 //允许EEP操作
	IAP_CMD = EEPROM_READ;	 //可读
	do
	{
		IAP_ADDRH = addr / 256;		//送地址高字节（地址需要改变时才需重新送地址）
		IAP_ADDRL = addr % 256;		//送地址低字节
		IAP_TRIG = 0X5A;
		IAP_TRIG = 0XA5;						
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		*buf = IAP_DATA;
		addr++;
		buf++;
	}while(--num);

	EEPROM_Disable();
	EA = 1;	
}


/******************************************************
 * FunctionName : EEPROM_read
 * Description  : EEPROM读区操作
 * Parameters   : addr--要写入的地址  buf--存储缓冲区
                  num--写入字节数
 * Returns      : none
******************************************************/
void EEPROM_write(uint16 addr,uint8 *buf,uint16 num)
{
	EA = 0;	

	IAP_CONTR = ENABLE_IAP;	 //允许EEP操作
	IAP_CMD = EEPROM_WRITE;	 //可写
	do
	{
		IAP_ADDRH = addr / 256;		//送地址高字节
		IAP_ADDRL = addr % 256;		//送地址低字节
		IAP_DATA  = *buf;			//送数据到IAP_DATA
		IAP_TRIG = 0X5A;
		IAP_TRIG = 0XA5;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		addr++;
		buf++;
	}while(--num);

	EEPROM_Disable();
	EA = 1;		
}



/******************************************************
 * FunctionName : EEPROM_SectorErase
 * Description  : EEPROM扇区擦除
 * Parameters   : addr--要擦除的地址
 * Returns      : none
******************************************************/
void EEPROM_SectorErase(uint16 addr)
{
	EA = 0;	
	
	IAP_CONTR = ENABLE_IAP;	 //允许EEP操作
	IAP_CMD = EEPROM_ERASE;	 //可读
	IAP_ADDRL = addr;
	IAP_ADDRH = addr>>8;
	IAP_TRIG = 0X5A;
	IAP_TRIG = 0XA5;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	EEPROM_Disable();
	EA = 1;	
}
#endif
