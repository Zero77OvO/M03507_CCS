/*
 * @Author: WSY
 * @Date: 2023-06-10 10:25:08
 * @LastEditors: WSY
 * @LastEditTime: 2024-07-18 21:36:19
 * @FilePath: \empty_LP_MSPM0G3507_nortos_ticlang\VOFA.c
 * @Description: ...
 * ����ɾ��㳤��,���׳����ɫ
 * Copyright (c) 2023 by WSY, All Rights Reserved.
 */

#include <my_headfile.h>


/**
 * @description: �����壬ʹ��ǿ������ת����ʹ�ô洢�ռ�����ݷ����仯
 * @return {*}
 */
typedef union
{
    float fdata;
    uint32_t ldata;
} FloatLongType;

/**
 * @description: ������л��㣬�Ѵ���ĸ������ͱ������ݵ�����ǰ��λ
 * @param {float} f ��Ҫ���������
 * @param {uint8_t} byte[] ��������
 * @param {int} Lcnt ��ǰ���ڷ���λ��,��0��ʼ
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
 * @description: ֡β���
 * @param {uint8_t} byte ��������
 * @param {int} Lcnt ����λ��, = �������ݸ���
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
 * @description: VOFA���ݷ��� �궨����Ĵ��������С
 * @return {*}
 */
#define USERDATANUM 3               // ����λ��
#define DATANUM USERDATANUM * 4 + 4 // �û��������
uint8_t transData[DATANUM] = {0};

extern float pitch, roll, yaw;

void VOFATransmit(void)
{
    
    // ����������ADC�ɼ�����
    //---------------�û�����--------------

    VOFAFloat2Byte(KP_R, transData, 0);
    VOFAFloat2Byte(KI_R, transData, 1);
    VOFAFloat2Byte(KD_R, transData, 2);

    VOFAFloat2Byte(yaw, transData, 5);
//    VOFAFloat2Byte((float)gyroMsg[2], transData, 2);
//    VOFAFloat2Byte((float)accMsg[0], transData, 3);
//    VOFAFloat2Byte((float)accMsg[1], transData, 4);
//    VOFAFloat2Byte((float)accMsg[2], transData, 5);
    //--------------- ���� ----------------
    VOFATrail(transData, USERDATANUM);

    for (int i = 0; i < DATANUM; i++)
    {
        DL_UART_Main_transmitData(UART3, transData[i]);
        while (DL_UART_isTXFIFOFull(UART3))
        {
        };
   }
}
