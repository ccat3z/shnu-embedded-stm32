#include "system/sys.h"
#include "system/delay.h"
#include "system/usart.h"
#include "hardware/led.h"
#include "hardware/key.h"

int main(void)
{
    u8 len;	
	u16 times=0; 
    Cache_Enable();                 //打开L1-Cache
    HAL_Init();				        //初始化HAL库
    Stm32_Clock_Init(432,25,2,9);   //设置时钟,216Mhz 
    delay_init(216);                //延时初始化
	uart_init(115200);		        //串口初始化
    LED_Init();                     //初始化LED

    while(1)
    {
       if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\nyou send\r\n");
            switch (*((uint8_t*)USART_RX_BUF)) {
				case 'l':
					LED0_Toggle;
				  break;
				case 'r':
					LED1_Toggle;
				  break;
			}
			HAL_UART_Transmit(&UART1_Handler,(uint8_t*)USART_RX_BUF,len,1000);	//发送接收到的数据
			while(__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_TC)!=SET);		//等待发送结束
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\nALIENTEK STM32F7开发板 串口实验\r\n");
				printf("正点原子@ALIENTEK\r\n\r\n\r\n");
			}
			if(times%200==0)printf("请输入数据,以回车键结束\r\n");  
			// if(times%30==0)LED0_Toggle;//闪烁LED,提示系统正在运行.
			delay_ms(10);   
		}
	}
}