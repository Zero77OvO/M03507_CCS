/*
 * @Author: 不会是Wsy吧
 * @Date: 2023-07-24 17:53:28
 * @LastEditTime: 2024-07-18 21:30:30
 * @FilePath: \empty_LP_MSPM0G3507_nortos_ticlang\VOFA.h
 * @Description:
 * 十年生死两茫茫，写程序，到天亮。千行代码，Bug何处藏。||QQ：123010257
 */
#ifndef __VOFA_H
#define __VOFA_H

#include "ti_msp_dl_config.h"

void VOFAFloat2Byte(float f, uint8_t byte[], int Lcnt);
void VOFATransmit(void);
void VOFATrail(uint8_t byte[], int Lcnt);

#endif

