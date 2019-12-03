#ifndef _EXTI_H
#define _EXTI_H
#include "../system/sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F7开发板
//外部中断驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/11/27
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

void EXTI_Init(void); //外部中断初始化

uint8_t exti_received;

#define KEY_UP_EXTI 1
#define KEY0_EXTI (1 << 1)
#define KEY1_EXTI (1 << 2)
#define KEY2_EXTI (1 << 3)

#endif
