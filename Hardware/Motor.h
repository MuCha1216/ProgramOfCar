#ifndef _MOTOR_H
#define _MOTOR_H

void Motor_Init(void);
void Motor_Speed(uint8_t speed1,uint8_t speed2,uint8_t speed3,uint8_t speed4);
void Motor_Run(uint8_t Speed,uint16_t time);
void Motor_Back(uint8_t Speed,uint16_t time);
void Motor_Left(uint8_t Speed,uint16_t time);	
void Motor_Right(uint8_t Speed,uint16_t time);
void Motor_Stop(void);
void Motor_Spin(uint8_t Speed,uint16_t time);
#endif
