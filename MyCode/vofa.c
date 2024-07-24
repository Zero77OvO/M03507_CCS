/*
 * @Author: WSY
 * @Date: 2023-06-10 10:25:08
 * @LastEditors: WSY
 * @LastEditTime: 2024-07-18 21:36:19
 * @FilePath: \empty_LP_MSPM0G3507_nortos_ticlang\VOFA.c
 * @Description: ...
 * 日落飞景秀长河,天地壮我行色
 * Copyright (c) 2023 by WSY, All Rights Reserved.
 */

#include <my_headfile.h>


/**
 * @description: 联合体，使用强制类型转换会使得存储空间的数据发生变化
 * @return {*}
 */
typedef union
{
    float fdata;
    uint32_t ldata;
} FloatLongType;

/**
 * @description: 这里进行换算，把传入的浮点类型变量传递到数组前四位
 * @param {float} f 需要传输的数据
 * @param {uint8_t} byte[] 传递数组
 * @param {int} Lcnt 当前所在发送位数,从0开始
 * @return {*}
 */
void VOFAFloat2Byte(float f, uint8_t byte[], int Lcnt)
{
    Lcnt = Lcnt * 4;
    FloatLongType f1;
    f1.fdata = f;
    byte[Lcnt] = (uint8_t)f1.ldata;
    byte[Lcnt + 1] = (uint8_t)(f1.ldata >> 8);
    byte[Lcnt + 2] = (uint8_t)(f1.ldata >> 16);
    byte[Lcnt + 3] = (uint8_t)(f1.ldata >> 24);
}
/**
 * @description: 帧尾添加
 * @param {uint8_t} byte 传入数组
 * @param {int} Lcnt 所在位数, = 传递数据个数
 * @return {*}
 */
void VOFATrail(uint8_t byte[], int Lcnt)
{
    Lcnt = Lcnt * 4;
    byte[Lcnt] = 0x00;
    byte[Lcnt + 1] = 0x00;
    byte[Lcnt + 2] = 0x80;
    byte[Lcnt + 3] = 0x7f;
}
/**
 * @description: VOFA数据发送 宏定义更改传递数组大小
 * @return {*}
 */
#define USERDATANUM 3               // 数据位数
#define DATANUM USERDATANUM * 4 + 4 // 用户无需更改
uint8_t transData[DATANUM] = {0};

extern float pitch, roll, yaw;

void VOFATransmit(void)
{
    
    // 主函数发送ADC采集数据
    //---------------用户数据--------------

    VOFAFloat2Byte(KP_R, transData, 0);
    VOFAFloat2Byte(KI_R, transData, 1);
    VOFAFloat2Byte(KD_R, transData, 2);

    VOFAFloat2Byte(yaw, transData, 5);
//    VOFAFloat2Byte((float)gyroMsg[2], transData, 2);
//    VOFAFloat2Byte((float)accMsg[0], transData, 3);
//    VOFAFloat2Byte((float)accMsg[1], transData, 4);
//    VOFAFloat2Byte((float)accMsg[2], transData, 5);
    //--------------- 结束 ----------------
    VOFATrail(transData, USERDATANUM);

    for (int i = 0; i < DATANUM; i++)
    {
        DL_UART_Main_transmitData(UART3, transData[i]);
        while (DL_UART_isTXFIFOFull(UART3))
        {
        };
   }
}
