/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_uart.c
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
#include "C51_Lib.h"

#ifdef LIB_UART_USE

serialObj_Def idata serialObj;


/******************************************************************************
 * FunctionName : UartInit
 * Description  : 串口初始化
 * Parameters   : baudrate--要设置的波特率
 * Returns      : none
*******************************************************************************/
void UartInit(uint32 baudrate)		
{
#ifdef   UART_USE_T1
	uint8 base = 0xFF - CPU_FAN/32.0/(double)baudrate + 1;
	PCON &= 0x7F;		 //禁止波特率加倍
	SCON = 0x50;		
	AUXR |= 0x40;		//定时器1为1T模式
	AUXR &= 0xFE;		//串口选择定时器1
	TMOD &= 0x0F;		
	TMOD |= 0x20;		
	TL1 = base;		
	TH1 = base;	
	ET1 = 0;		
	TR1 = 1;	
#else
	uint16 base = 0xFFFF - CPU_FAN/4.0/(double)baudrate;
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = base&0x00FF;		
	T2H = base>>8;		
	AUXR |= 0x10;		//启动定时器2
	
#endif
	ES = 1;
	EA = 1;
	
	serialObj.sndCount = 0;
	serialObj.sndIndex = 0;
	serialObj.revCount = 0;
	serialObj.readIndex = 0;
	serialObj.byteWaitRead = 0;
}


/******************************************************************************
 * FunctionName : softUART_get_byte_num
 * Description  : 获取等待读取字符个数
 * Parameters   :
 * Returns      :
*******************************************************************************/
unsigned char UARTgetByteNum()
{
	return serialObj.byteWaitRead;
}


/******************************************************************************
 * FunctionName : softUART_get_str
 * Description  : 获取接收字符串
 * Parameters   : *str--接收缓冲区  num--要读取的数量
 * Returns      : 状态 当串口缓冲区的数量为零或者小于要读取的数量时,返回false
*******************************************************************************/
bool UARTgetStr(char *str, unsigned char num)
{
	bool res = false;
	char i = 0;
	if(num < serialObj.byteWaitRead) /*当前读取字符数量有效*/
	{		
		res = true;

		serialObj.byteWaitRead -= num;
		serialObj.readIndex += num;

		while(num--)
			*str++ = serialObj.revBuf[i++];
	}
	else if(num == serialObj.byteWaitRead) /*读取当前剩余所有*/
	{
		res = true;
		serialObj.byteWaitRead = 0;
		serialObj.readIndex = 0;
		serialObj.revCount = 0;
		while(num--)
			*str++ = serialObj.revBuf[i++];
	}

	return res;
}


/******************************************************************************
 * FunctionName : UartgetChar
 * Description  : 从串口缓冲区中获取单个字符
 * Parameters   : none
 * Returns      : 返回读取的字符  缓冲区空白则返回EOF
*******************************************************************************/
int UartgetChar()
{
	if(serialObj.readIndex < serialObj.revCount)
	{
		serialObj.byteWaitRead--;
		return serialObj.revBuf[serialObj.readIndex++];
	}
	else
	{
		serialObj.readIndex = 0;
		serialObj.revCount = 0;
		serialObj.byteWaitRead = 0;
		return EOF;
	}
}

/******************************************************************************
 * FunctionName : UartwriteChar
 * Description  : 写单个字符
 * Parameters   : ch - 写入的字符
 * Returns      : none
*******************************************************************************/
void UartwriteChar(char ch)
{
	if(serialObj.sndCount < BUF_SIZE-1)
		serialObj.sndBuf[serialObj.sndCount++] = ch;
	if(serialObj.sndIndex == 0)
		SBUF = ch;
}

/******************************************************************************
 * FunctionName : UartwriteStr
 * Description  : 串口输出字符串
 * Parameters   : *str--写入的字符串  num--发送长度;0自动获取长度
 * Returns      : none
*******************************************************************************/
void  UartwriteStr(char *str, unsigned char num)
{
	if(num)
	{
		while(num--)
		{
			serialObj.sndBuf[serialObj.sndCount++] = *str++;
			if(serialObj.sndCount >= BUF_SIZE-1)
				return;
		}
	}
	else
	{		
		while(*str)
		{
			serialObj.sndBuf[serialObj.sndCount++] = *str++;
			if(serialObj.sndCount >= BUF_SIZE-1)
				return;
		}
	}
	
	if(serialObj.sndIndex == 0)
		SBUF = serialObj.sndBuf[0];	
}

/******************************************************************************
 * FunctionName : SerailInterrupt
 * Description  : 串口中断
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void SerailInterrupt()interrupt VECTOR_S1
{
	if(RI) /*接收中断*/
	{
		RI = 0;
		if(serialObj.revCount < BUF_SIZE-1)
		{
			serialObj.revBuf[serialObj.revCount++] = SBUF;
			serialObj.byteWaitRead++;
		}
	}

	if(TI) /*发送中断*/
	{
		TI = 0;	  
		serialObj.sndIndex += 1;
	    if(serialObj.sndIndex < serialObj.sndCount)
	        SBUF = *(serialObj.sndBuf+serialObj.sndIndex);
	    else
	    {
	      serialObj.sndIndex = 0;
				serialObj.sndCount = 0;
	    }
	}
}

#endif