/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_eeprom.h
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
#ifndef	__C51_EEPROM_H
#define	__C51_EEPROM_H


#define EEPROM_READ   1
#define EEPROM_WRITE  2
#define EEPROM_ERASE  3
#define ENABLE_IAP    0X82


void	EEPROM_Disable(void);

void EEPROM_read(uint16 addr, uint8 *buf, uint16 num);

void EEPROM_write(uint16 addr,uint8 *buf,uint16 num);

void EEPROM_SectorErase(uint16 addr);


#endif