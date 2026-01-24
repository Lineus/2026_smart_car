//
// Created by sixPigs on 2026/1/21.
//

#ifndef CHARIOT_WHEEL_H
#define CHARIOT_WHEEL_H

#include "Emm_V5.h"
void Emm_V5_Global_Speed(int speed1, int speed2, int speed3, int speed4, int acc); //速度模式控制四个电机
void Emm_V5_Global_Pos(uint8_t dir, uint16_t vel, uint8_t acc, uint32_t clk, int raF, int snF); //位置模式控制四个电机转弯

#endif //CHARIOT_WHEEL_H