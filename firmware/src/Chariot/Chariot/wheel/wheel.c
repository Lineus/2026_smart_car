//
// Created by sixPigs on 2026/1/21.
//

#include "wheel.h"
void setAllSpeed(int speed1,int speed2,int speed3,int speed4,int acc) {
    static uint8_t cmd[36] = {0};
    cmd[0]=0x00;
    cmd[1]=0xAA;
    cmd[2]=0x00;
    cmd[3]=0x24;

    cmd[4] =  01;                       // 地址
    cmd[5] =  0xF6;                       // 功能码
    cmd[6] =  01;                        // 方向
    cmd[7] =  (uint8_t)(speed1 >> 8);        // 速度(RPM)高8位字节
    cmd[8] =  (uint8_t)(speed1 >> 0);        // 速度(RPM)低8位字节
    cmd[9] =  acc;                        // 加速度，注意：0是直接启动
    cmd[10] =  0x00;                        // 多机同步运动标志
    cmd[11] =  0x6B;

    cmd[12] =  01;                       // 地址
    cmd[13] =  0xF6;                       // 功能码
    cmd[14] =  01;                        // 方向
    cmd[15] =  (uint8_t)(speed2 >> 8);        // 速度(RPM)高8位字节
    cmd[16] =  (uint8_t)(speed2 >> 0);        // 速度(RPM)低8位字节
    cmd[17] =  acc;                        // 加速度，注意：0是直接启动
    cmd[18] =  0x00;                        // 多机同步运动标志
    cmd[19] =  0x6B;

    cmd[20] =  01;                       // 地址
    cmd[21] =  0xF6;                       // 功能码
    cmd[22] =  01;                        // 方向
    cmd[23] =  (uint8_t)(speed3 >> 8);        // 速度(RPM)高8位字节
    cmd[24] =  (uint8_t)(speed3 >> 0);        // 速度(RPM)低8位字节
    cmd[25] =  acc;                        // 加速度，注意：0是直接启动
    cmd[26] =  0x00;                        // 多机同步运动标志
    cmd[27] =  0x6B;

    cmd[28] =  01;                       // 地址
    cmd[29] =  0xF6;                       // 功能码
    cmd[30] =  01;                        // 方向
    cmd[31] =  (uint8_t)(speed4 >> 8);        // 速度(RPM)高8位字节
    cmd[32] =  (uint8_t)(speed4 >> 0);        // 速度(RPM)低8位字节
    cmd[33] =  acc;                        // 加速度，注意：0是直接启动
    cmd[34] =  0x00;                        // 多机同步运动标志
    cmd[35] =  0x6B;
}