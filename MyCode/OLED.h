#ifndef __OLED_H__
#define __OLED_H__

#include "stdint.h"

void OLED_I2C_Init(void);

int I2C_WriteByte(uint8_t addr,uint8_t data);

void OLED_WR_CMD(unsigned char I2C_Command);

void OLED_WR_DATA(unsigned char I2C_Data);

void OLED_Init(void);

void OLED_Set_Pos(unsigned char x,unsigned char y);

void OLED_Fill(unsigned char Fill_Data);

void OLED_CLS(void);

void OLED_ON(void);

void OLED_OFF(void);

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size,uint8_t Color_Turn);
void OLED_ShowString(uint8_t x,uint8_t y,char*chr,uint8_t Char_Size, uint8_t Color_Turn);
void OLED_ShowNum(uint8_t x,uint8_t y,unsigned int num,uint8_t len,uint8_t size2, uint8_t Color_Turn);
void OLED_Showdecimal(uint8_t x,uint8_t y,float num,uint8_t z_len,uint8_t f_len,uint8_t size2, uint8_t Color_Turn);
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no, uint8_t Color_Turn);
void OLED_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *  BMP,uint8_t Color_Turn);

void OLED_work(void);

#endif

