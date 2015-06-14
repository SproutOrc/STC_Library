/******************************************************************
*    			STC-51库/STC-51 library file
*
*文件名/file    : c51_timer.c
*
*功能/function  : C51库定时器文件
*
*协议/licence   : GPL开源/open GPL
*
*作者/author    : J.H.Chen
*
*时间/time      : 2015-06-10
*
*说明/other     : 定时器使用定时器0,请勿修改定时器0相关代码
******************************************************************/
#include "C51_Lib.h"

#define TL0_1  0xE0		//定时初值
#define TH0_1  0xB1		//定时初值


static struct
{
	unsigned int base;
  unsigned int cnt;
	unsigned char isOverflow;
	unsigned char isEnable;
}delayType;

static uint16 base;
static timer0_t  *timer_list,*p;
static timer0_t timer_head;
/******************************************************************************
 * FunctionName : timer0init
 * Description  : 定时器0初始化
 * Parameters   : none
 * Returns      : none
 * Other        : 16位自动重载模式  1ms时基
*******************************************************************************/
void timer0init()
{
	base = 65535-CPU_FAN/12000.0;
	AUXR &= 0x7F;		//12T定时器模式
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = (uint8)(base&0x00FF);		
	TH0 = base>>8;		
	TF0 = 0;		
	TR0 = 1;
	
	timer_head.next = NULL; //链表头不存储信息
	timer_list = &timer_head;
	
	ET0 = 1;
	EA = 1;
}

/******************************************************************************
 * FunctionName : timer0handler
 * Description  : 定时器0中断处理, 1ms时间定时器
 * Parameters   : none
 * Returns      : none
 * Other        : none
*******************************************************************************/
static void timer0handler()interrupt VECTOR_TIM0
{
	TL0 = (uint8)(base&0x00FF);		
	TH0 = base>>8;
	
  p = timer_list;
	
	while(p->next != NULL)//忽略链表头
	{
		if(++(p->next->cnt) >= p->next->period)
		{
			p->next->Timer0Func(p->next->timer_arg);
			if(p->next->Timer_Status == Timer_Status_repeat) 
				p->next->cnt = 0;
			else  //单次定时结束,解绑功能
				p->next = p->next->next;
		}
		p = p->next;
	}
	
	if(delayType.isEnable==1 && ++delayType.cnt >= delayType.base)  
	{
		delayType.isEnable = 0;  //关闭延时器
		delayType.isOverflow = 1; //置位溢出位
	}
	
}


/******************************************************************************
 * FunctionName : delay_ms
 * Description  : 毫秒级定时
 * Parameters   : ms - 定时时间 ms
 * Returns      : 误差-1ms
*******************************************************************************/
void delay_ms(uint16 ms)
{
	TR0 = 0;		//定时器0开始计时
	delayType.base = ms;
	delayType.cnt = 0;
	delayType.isOverflow = 0;
	delayType.isEnable = 1;
	TR0 = 1;		//定时器0开始计时
	while(delayType.isOverflow == 0);
}


/******************************************************************************
 * FunctionName : timer_disarm
 * Description  : 定时器取消功能绑定
 * Parameters   : timer--已经定义的功能变量
 * Returns      : 误差-1ms
*******************************************************************************/
void timer_disarm(timer0_t *timer)
{
	p = timer_list;
	while(p->next != NULL)  //忽略链表头
	{
		if(p->next == timer)
		{
			p->next = p->next->next; //此处不做指针检查,因为node创建的时候NEXT指针已经置NULL
			return;
		}
		p = p->next; //下移
	}
}

/******************************************************************************
 * FunctionName : timer_arm
 * Description  : 定时器功能绑定
 * Parameters   : timer--已经定义的功能变量   period--定时周期,ms
                  Timer_Status--工作模式,单次定时或者重复定时
 * Returns      : 误差-1ms
*******************************************************************************/
void timer_arm(timer0_t *timer, uint32 period, Timer_Status_Def Timer_Status)
{
	p = timer_list;
	while(p->next != NULL) 
		p = p->next; //下移
	
	timer->next = NULL;
	timer->period = period;
	timer->cnt = 0; 
	timer->Timer_Status = Timer_Status;
	
	p->next = timer;
}

/******************************************************************************
 * FunctionName : timer_setfn
 * Description  : 定时器功能绑定对应函数
 * Parameters   : timer--已经定义的功能变量   *timerfn--函数指针
                  timer_arg--函数预设参数
 * Returns      : 误差-1ms
*******************************************************************************/
void timer_setfn(timer0_t *timer, sysTimer0Func *timerfn, uint8 timer_arg)
{
	timer->Timer0Func = timerfn;
	timer->timer_arg = timer_arg;
}