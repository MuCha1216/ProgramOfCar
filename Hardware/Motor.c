#include "stm32f10x.h"                  // Device header

#include "PWM.h"
#include "Delay.h"

void Motor_Init(void)
{
	PWM_Init();
}

void Motor_Speed(uint8_t speed1,uint8_t speed2,uint8_t speed3,uint8_t speed4)
{
	TIM_SetCompare1(TIM4,speed1);
	TIM_SetCompare2(TIM4,speed2);
	TIM_SetCompare3(TIM4,speed3);
	TIM_SetCompare4(TIM4,speed4);
}

void Motor_Run(uint8_t Speed,uint16_t time)
{	
	if(Speed>100)
	{
		Speed = 100;
	}
	if(Speed<0)
	{
		Speed = 0;
	}
	Motor_Speed(Speed,0,Speed,0);
	
	Delay_ms(time);
}

void Motor_Back(uint8_t Speed,uint16_t time)
{	
	if(Speed>100)
	{
		Speed = 100;
	}
	if(Speed<0)
	{
		Speed = 0;
	}
	Motor_Speed(0,Speed,0,Speed);
	
	Delay_ms(time);
}

void Motor_Left(uint8_t Speed,uint16_t time)
{	
	if(Speed>100)
	{
		Speed = 100;
	}
	if(Speed<0)
	{
		Speed = 0;
	}
	Motor_Speed(0,0,Speed,0);
	
	Delay_ms(time);
}
	
void Motor_Right(uint8_t Speed,uint16_t time)
{	
	if(Speed>100)
	{
		Speed = 100;
	}
	if(Speed<0)
	{
		Speed = 0;
	}
	Motor_Speed(Speed,0,0,0);
	
	Delay_ms(time);
}

void Motor_Stop(void)
{
	Motor_Speed(0,0,0,0);
}

void Motor_Spin(uint8_t Speed,uint16_t time)
{	
	if(Speed>100)
	{
		Speed = 100;
	}
	if(Speed<0)
	{
		Speed = 0;
	}
	Motor_Speed(Speed,0,0,Speed);
	
	Delay_ms(time);
}
