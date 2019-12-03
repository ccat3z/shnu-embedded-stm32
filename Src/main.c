#include "system/sys.h"
#include "system/delay.h"
#include "system/usart.h"
#include "hardware/led.h"
#include "hardware/timer.h"
/************************************************
 ALIENTEK 阿波罗STM32F7开发板 实验7
 定时器中断实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
    Cache_Enable();                 //打开L1-Cache
    HAL_Init();				        //初始化HAL库
    Stm32_Clock_Init(432,25,2,9);   //设置时钟,216Mhz 
    delay_init(216);                //延时初始化
	uart_init(115200);		        //串口初始化
    LED_Init();                     //初始化LED
    TIM3_Init(5000-1,10800-1);      //定时器3初始化，定时器时钟为108M，分频系数为10800-1，
                                    //所以定时器3的频率为108M/10800=10K，自动重装载为5000-1，那么定时器周期就是500ms
    while(1)
    {
	}  
}
