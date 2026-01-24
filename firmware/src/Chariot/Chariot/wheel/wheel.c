//
// Created by sixPigs on 2026/1/21.
//

#include "wheel.h"

void Emm_V5_Global_Speed(int speed1, int speed2, int speed3, int speed4, int acc)
{
    static uint8_t cmd[37] = {0};

    // 装载命令
    cmd[0] = 0x00;
    cmd[1] = 0xAA;
    cmd[2] = 0x00;
    cmd[3] = 0x25;


    cmd[4] = 0x01; // 地址
    cmd[5] = 0xF6; // 功能码
    cmd[6] = 0x00;
    if (speed1 < 0)
    {
        cmd[6] = 0x01;
        speed1 *= -1;
    } // 方向
    cmd[7] = (uint8_t)(speed1 >> 8); // 速度(RPM)高8位字节
    cmd[8] = (uint8_t)(speed1 >> 0); // 速度(RPM)低8位字节
    cmd[9] = acc; // 加速度，注意：0是直接启动
    cmd[10] = 0x00; // 多机同步运动标志
    cmd[11] = 0x6B; // 校验字节


    cmd[12] = 0x02; // 地址
    cmd[13] = 0xF6; // 功能码
    cmd[14] = 0x00;
    if (speed2 < 0)
    {
        cmd[14] = 0x01;
        speed2 *= -1;
    } // 方向
    cmd[15] = (uint8_t)(speed2 >> 8); // 速度(RPM)高8位字节
    cmd[16] = (uint8_t)(speed2 >> 0); // 速度(RPM)低8位字节
    cmd[17] = acc; // 加速度，注意：0是直接启动
    cmd[18] = 0x00; // 多机同步运动标志
    cmd[19] = 0x6B; // 校验字节


    cmd[20] = 0x03; // 地址
    cmd[21] = 0xF6; // 功能码
    cmd[22] = 0x00;
    if (speed3 < 0)
    {
        cmd[23] = 0x01;
        speed3 *= -1;
    } // 方向
    cmd[23] = (uint8_t)(speed3 >> 8); // 速度(RPM)高8位字节
    cmd[24] = (uint8_t)(speed3 >> 0); // 速度(RPM)低8位字节
    cmd[25] = acc; // 加速度，注意：0是直接启动
    cmd[26] = 0x00; // 多机同步运动标志
    cmd[27] = 0x6B; // 校验字节


    cmd[28] = 0x04; // 地址
    cmd[29] = 0xF6; // 功能码
    cmd[30] = 0x00;
    if (speed4 < 0)
    {
        cmd[30] = 0x01;
        speed4 *= -1;
    } // 方向
    cmd[31] = (uint8_t)(speed4 >> 8); // 速度(RPM)高8位字节
    cmd[32] = (uint8_t)(speed4 >> 0); // 速度(RPM)低8位字节
    cmd[33] = acc; // 加速度，注意：0是直接启动
    cmd[34] = 0x00; // 多机同步运动标志
    cmd[35] = 0x6B; // 校验字节


    cmd[36] = 0x6B;
    // 发送命令
    usart_SendCmd(cmd, 37);
}

void Emm_V5_Global_Pos(uint8_t dir, uint16_t vel, uint8_t acc, uint32_t clk, int raF, int snF)
{
    static uint8_t cmd[57] = {0};

    //转载命令
    cmd[0] = 0x00;
    cmd[1] = 0xAA;
    cmd[2] = 0x00;
    cmd[3] = 0x39;


    cmd[4] = 1; // 地址
    cmd[5] = 0xFD; // 功能码
    cmd[6] = !dir; // 方向，0为左转，1为右转
    cmd[7] = (uint8_t)(vel >> 8); // 速度(RPM)高8位字节
    cmd[8] = (uint8_t)(vel >> 0); // 速度(RPM)低8位字节
    cmd[9] = acc; // 加速度，注意：0是直接启动
    cmd[10] = (uint8_t)(clk >> 24); // 脉冲数(bit24 - bit31)
    cmd[11] = (uint8_t)(clk >> 16); // 脉冲数(bit16 - bit23)
    cmd[12] = (uint8_t)(clk >> 8); // 脉冲数(bit8  - bit15)
    cmd[13] = (uint8_t)(clk >> 0); // 脉冲数(bit0  - bit7 )
    cmd[14] = raF; // 相位/绝对标志，false为相对运动，true为绝对值运动
    cmd[15] = snF; // 多电机命令中，位置模式运动命令中的多机同步标志用于控制是否返回到位命令：地址 + 功能码 + 9F + 校验码，0为到位不返回，1为到位返回；
    cmd[16] = 0x6B; // 校验字节


    cmd[17] = 2; // 地址
    cmd[18] = 0xFD; // 功能码
    cmd[19] = !dir; // 方向，0为左转，1为右转
    cmd[20] = (uint8_t)(vel >> 8); // 速度(RPM)高8位字节
    cmd[21] = (uint8_t)(vel >> 0); // 速度(RPM)低8位字节
    cmd[22] = acc; // 加速度，注意：0是直接启动
    cmd[23] = (uint8_t)(clk >> 24); // 脉冲数(bit24 - bit31)
    cmd[24] = (uint8_t)(clk >> 16); // 脉冲数(bit16 - bit23)
    cmd[25] = (uint8_t)(clk >> 8); // 脉冲数(bit8  - bit15)
    cmd[26] = (uint8_t)(clk >> 0); // 脉冲数(bit0  - bit7 )
    cmd[27] = raF; // 相位/绝对标志，false为相对运动，true为绝对值运动
    cmd[28] = snF; // 多电机命令中，位置模式运动命令中的多机同步标志用于控制是否返回到位命令：地址 + 功能码 + 9F + 校验码，0为到位不返回，1为到位返回；
    cmd[29] = 0x6B; // 校验字节


    cmd[30] = 3; // 地址
    cmd[31] = 0xFD; // 功能码
    cmd[32] = dir; // 方向，0为左转，1为右转
    cmd[33] = (uint8_t)(vel >> 8); // 速度(RPM)高8位字节
    cmd[34] = (uint8_t)(vel >> 0); // 速度(RPM)低8位字节
    cmd[35] = acc; // 加速度，注意：0是直接启动
    cmd[36] = (uint8_t)(clk >> 24); // 脉冲数(bit24 - bit31)
    cmd[37] = (uint8_t)(clk >> 16); // 脉冲数(bit16 - bit23)
    cmd[38] = (uint8_t)(clk >> 8); // 脉冲数(bit8  - bit15)
    cmd[39] = (uint8_t)(clk >> 0); // 脉冲数(bit0  - bit7 )
    cmd[40] = raF; // 相位/绝对标志，false为相对运动，true为绝对值运动
    cmd[41] = snF; // 多电机命令中，位置模式运动命令中的多机同步标志用于控制是否返回到位命令：地址 + 功能码 + 9F + 校验码，0为到位不返回，1为到位返回；
    cmd[42] = 0x6B; // 校验字节


    cmd[43] = 4; // 地址
    cmd[44] = 0xFD; // 功能码
    cmd[45] = dir; // 方向，0为左转，1为右转
    cmd[46] = (uint8_t)(vel >> 8); // 速度(RPM)高8位字节
    cmd[47] = (uint8_t)(vel >> 0); // 速度(RPM)低8位字节
    cmd[48] = acc; // 加速度，注意：0是直接启动
    cmd[49] = (uint8_t)(clk >> 24); // 脉冲数(bit24 - bit31)
    cmd[50] = (uint8_t)(clk >> 16); // 脉冲数(bit16 - bit23)
    cmd[51] = (uint8_t)(clk >> 8); // 脉冲数(bit8  - bit15)
    cmd[52] = (uint8_t)(clk >> 0); // 脉冲数(bit0  - bit7 )
    cmd[53] = raF; // 相位/绝对标志，false为相对运动，true为绝对值运动
    cmd[54] = snF; // 多电机命令中，位置模式运动命令中的多机同步标志用于控制是否返回到位命令：地址 + 功能码 + 9F + 校验码，0为到位不返回，1为到位返回；
    cmd[55] = 0x6B; // 校验字节


    cmd[56] = 0x6B;
    //发送命令
    usart_SendCmd(cmd, 57);
}