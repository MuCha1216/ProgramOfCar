#ifndef _IRTRACKING_H
#define _IRTRACKING_H

void IRTracking_Init(void);
uint8_t LeftIRTracking_Get(void);
uint8_t RightIRTracking_Get(void);

uint8_t LeftIRObstacle_Get(void);

uint8_t RightIRObstacle_Get(void);
#endif
