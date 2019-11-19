#include "system/sys.h"
#include "system/delay.h"
#include "system/usart.h"
#include "hardware/exti.h"

int main(void) {
    Cache_Enable();                 //打开L1-Cache
    HAL_Init();				        //初始化HAL库
    Stm32_Clock_Init(432,25,2,9);   //设置时钟,216Mhz 
    delay_init(216);                //延时初始化
	uart_init(115200);		        //串口初始化
    LED_Init();                     //初始化LED
    EXTI_Init();                    //外部中断初始化
    while(1)
    {
        printf("OK\r\n");           //打印OK提示程序运行
        delay_ms(1000);             //每隔1s打印一次 
	} 
}