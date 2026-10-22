#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStracture;
	GPIO_InitStracture.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStracture.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 ;
	GPIO_InitStracture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStracture);
	
	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStracture;
	TIM_TimeBaseInitStracture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStracture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStracture.TIM_Period = 100 - 1; //以10Khz的速度计一万个数,也就是一秒时间
	TIM_TimeBaseInitStracture.TIM_Prescaler =  7200 - 1; //72M/7200=10kHz
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStracture);
	
	TIM_OCInitTypeDef TIM_OCInitStracture;
	TIM_OCStructInit(&TIM_OCInitStracture);
	TIM_OCInitStracture.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStracture.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStracture.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStracture.TIM_Pulse = 0;//CCR
	TIM_OC1Init(TIM4,&TIM_OCInitStracture);
	
	TIM_OC2Init(TIM4,&TIM_OCInitStracture);
	TIM_OC3Init(TIM4,&TIM_OCInitStracture);
	TIM_OC4Init(TIM4,&TIM_OCInitStracture);
	
	
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	
	TIM_Cmd(TIM4,ENABLE);
}
