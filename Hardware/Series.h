#ifndef _SERIAL_H
#define _SERIAL_H
#include <stdio.H>
void Serial_Init(void);
void Serial_SendBity(uint8_t Bity);
void Serial_SendArray(uint8_t*Array,uint16_t Length);
void Serial_sengSting(char *String);
uint32_t Serial_Pow(uint32_t X,uint32_t Y);
void Serial_SendNumber(uint32_t Number,uint16_t Length);
void Serial_Printf(char *format,...);

uint8_t Serial_GetRxFlag(void);
uint8_t Serial_GetRxData(void);

#endif
