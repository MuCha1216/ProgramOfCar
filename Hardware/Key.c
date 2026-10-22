#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStracture;
	GPIO_InitStracture.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStracture.GPIO_Pin = GPIO_Pin_15 ;
	GPIO_InitStracture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStracture);
	
	GPIO_InitStracture.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStracture.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStracture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStracture);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum;
	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)==0);
		Delay_ms(20);
		KeyNum = 1;
	}
	return KeyNum;
}
