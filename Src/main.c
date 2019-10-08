#include "system/sys.h"
#include "system/delay.h"
#include "system/usart.h"
#include "hardware/led.h"
#include "hardware/key.h"

/************************************************
 ALIENTEK 阿波罗STM32F7开发板 实验2
 按键输入实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

int main(void) {
    u8 key;
    u8 led0sta = 1, led1sta = 1;     // LED0,LED1的当前状态
    Cache_Enable();                  //打开L1-Cache
    HAL_Init();                      //初始化HAL库
    Stm32_Clock_Init(432, 25, 2, 9); //设置时钟,216Mhz
    delay_init(216);                 //延时初始化
    uart_init(115200);               //串口初始化
    LED_Init();                      //初始化LED
    KEY_Init();                      //按键初始化
    int mode = 0;
    while (1) {
        key = KEY_Scan(0); //得到键值
        if (key == WKUP_PRES) {
            mode = (mode + 1) % 4;
        }

        switch (mode) {
        case 0:
            led1sta = 0;
            led0sta = 1;
            break;
        case 1:
            led1sta = 1;
            led0sta = 0;
            break;
        case 2:
            led1sta = 0;
            led0sta = 0;
            break;
        case 3:
            led1sta = 1;
            led0sta = 1;
            break;
        }
        LED0(led0sta); //控制LED0状态
        LED1(led1sta); //控制LED1状态
    }
}
