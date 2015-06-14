/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_uart.h
*
*功能/function  : C51库uart操作
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-06-12
*
*说明/other     : 
******************************************************************/
#ifndef __C51_UART_H
#define __C51_UART_H

#include "stdint.h"

#ifndef EOF
#define EOF  ((int)-1)
#endif



#define BUF_SIZE    64


typedef struct
{
	unsigned char sndIndex;   //发送字符指针
	unsigned char sndCount;   //发送计数器
	char sndBuf[BUF_SIZE];    //发送缓冲区

    unsigned char readIndex;  //读字符指针
	unsigned char revCount;	  //接收计算器
	unsigned char byteWaitRead;  //等待用户读的字符数量
	char revBuf[BUF_SIZE];    //接收缓冲区
}serialObj_Def;


void UartInit(uint32 baudrate);

void UartwriteChar(char ch);

void UartwriteStr(char *str, unsigned char num);

bool UARTgetStr(char *str, unsigned char num);

unsigned char UARTgetByteNum();

int UartgetChar();	


#endif