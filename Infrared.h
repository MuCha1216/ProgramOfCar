#ifndef _INFRARED_H
#define _INFRARED_H

uint8_t IRremote_Counttime(void);

void Infrared_Init(void);
void EXTI9_5_IRQHandler(void);
extern uint32_t ReceiveData;
extern uint8_t  ReceiveFlag;

#endif
