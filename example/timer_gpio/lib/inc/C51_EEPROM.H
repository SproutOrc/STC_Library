/******************************************************************
*    			STC-51��/STC-51 library file
*
*�ļ���/file    : c51_eeprom.h
*
*����/function  : C51��eeprom����
*
*Э��/licence   : GPL��Դ/open GPL
*
*����/author    : J.H.Chen
*
*ʱ��/time      : 2015-06-12
*
*˵��/other     : 
******************************************************************/
#ifndef	__C51_EEPROM_H
#define	__C51_EEPROM_H

#include "stdint.h"

#define EEPROM_READ   1
#define EEPROM_WRITE  2
#define EEPROM_ERASE  3
#define ENABLE_IAP    0X82


void	EEPROM_Disable(void);

void EEPROM_read(uint16 addr, uint8 *buf, uint16 num);

void EEPROM_write(uint16 addr,uint8 *buf,uint16 num);

void EEPROM_SectorErase(uint16 addr);


#endif