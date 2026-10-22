#include "stm32f10x.h"                  // Device header

void IRTracking_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStracture;
	GPIO_InitStracture.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStracture.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 ;
	GPIO_InitStracture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStracture);
	
	GPIO_InitStracture.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStracture.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 ;
	GPIO_InitStracture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStracture);
}

uint8_t LeftIRTracking_Get(void)
{
	return (BitAction)GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}

uint8_t RightIRTracking_Get(void)
{
	return (BitAction)GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12);
}

uint8_t LeftIRObstacle_Get(void)
{
	return (BitAction)GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
}

uint8_t RightIRObstacle_Get(void)
{
	return (BitAction)GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12);
}

