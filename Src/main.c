#include "system/sys.h"
#include "system/delay.h"
#include "system/usart.h"
#include "hardware/exti.h"
#include <string.h>

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
        handle_key_exti(KEY0_EXTI, "a\n");
        handle_key_exti(KEY1_EXTI, "b\n");
        handle_key_exti(KEY2_EXTI, "c\n");
        handle_key_exti(KEY_UP_EXTI, "d\n");
	} 
}

void handle_key_exti(uint8_t flag, char* msg) {
    if (exti_received & flag) {
        HAL_UART_Transmit(&UART1_Handler, msg, strlen(msg), 0xFFFF);
        exti_received &= ~flag;
    }
}