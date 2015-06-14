/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_hardware_intt.c
*
*功能/function  : C51库硬件初始化文件
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

void SystemInit()
{
	timer0init();
}