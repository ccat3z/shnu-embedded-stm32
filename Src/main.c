#include "system/sys.h"
#include "system/delay.h"
#include "system/usart.h" 
void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
while(nCount--){}
}

int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;

	Cache_Enable();                 //打开L1-Cache
	HAL_Init();				        //初始化HAL库
	Stm32_Clock_Init(432,25,2,9);   //设置时钟,216Mhz 
	__HAL_RCC_GPIOB_CLK_ENABLE();           //开启GPIOB时钟

	GPIO_Initure.Pin=GPIO_PIN_0|GPIO_PIN_1; //PB1,0
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
	GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
	GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
	HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	Delay(0x1FFFFFF);

	while(1)
	{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		Delay(0x1FFFFFF);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
	}
}
