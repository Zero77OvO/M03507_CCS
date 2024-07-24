#include "OLED.h"
#include "OLED_Font.h"
#include "ti/driverlib/dl_i2c.h"

#define OLED_I2C I2C0
#define OLED_ADDR   0x3C

void OLED_I2C_Init(void)
{

}

//向OLED寄存器地址写一个byte的数据
int I2C_WriteByte(uint8_t addr,uint8_t data)
{
  uint8_t buff[2] = {0};
  buff[0] = addr;
  buff[1] = data;
  /* Wait for I2C to be Idle */
  while (!(
            DL_I2C_getControllerStatus(OLED_I2C) & DL_I2C_CONTROLLER_STATUS_IDLE))
            ;

        /* Send the packet to the controller.
         * This function will send Start + Stop automatically.
         */
        DL_I2C_startControllerTransfer(OLED_I2C, OLED_ADDR,
            DL_I2C_CONTROLLER_DIRECTION_TX, 2);
        DL_I2C_fillControllerTXFIFO(OLED_I2C, &buff[0], 2);
      /* Poll until the Controller writes all bytes */
      while (DL_I2C_getControllerStatus(OLED_I2C) &
                     DL_I2C_CONTROLLER_STATUS_BUSY_BUS)
                  ;

      /* Trap if there was an error */
      if (DL_I2C_getControllerStatus(OLED_I2C) &
          DL_I2C_CONTROLLER_STATUS_ERROR) {
          /* LED will remain high if there is an error */
          __BKPT(0);
      }
    return 0;
}



//写指令
void OLED_WR_CMD(unsigned char I2C_Command)
{
        I2C_WriteByte(0x00,I2C_Command);
}

//写数据
void OLED_WR_DATA(unsigned char I2C_Data)
{
        I2C_WriteByte(0x40,I2C_Data);
}

//厂家初始化代码
void OLED_Init(void)
{
    OLED_I2C_Init();
        DL_Common_delayCycles(16000000);
        OLED_WR_CMD(0xAE); //display off
        OLED_WR_CMD(0x20); //Set Memory Addressing Mode
        OLED_WR_CMD(0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
        OLED_WR_CMD(0xb0); //Set Page Start Address for Page Addressing Mode,0-7
        OLED_WR_CMD(0xc8); //Set COM Output Scan Direction
        OLED_WR_CMD(0x00); //---set low column address
        OLED_WR_CMD(0x10); //---set high column address
        OLED_WR_CMD(0x40); //--set start line address
        OLED_WR_CMD(0x81); //--set contrast control register
        OLED_WR_CMD(0xff); //áá?èμ÷?ú 0x00~0xff
        OLED_WR_CMD(0xa1); //--set segment re-map 0 to 127
        OLED_WR_CMD(0xa6); //--set normal display
        OLED_WR_CMD(0xa8); //--set multiplex ratio(1 to 64)
        OLED_WR_CMD(0x3F); //
        OLED_WR_CMD(0xa4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
        OLED_WR_CMD(0xd3); //-set display offset
        OLED_WR_CMD(0x00); //-not offset
        OLED_WR_CMD(0xd5); //--set display clock divide ratio/oscillator frequency
        OLED_WR_CMD(0xf0); //--set divide ratio
        OLED_WR_CMD(0xd9); //--set pre-charge period
        OLED_WR_CMD(0x22); //
        OLED_WR_CMD(0xda); //--set com pins hardware configuration
        OLED_WR_CMD(0x12);
        OLED_WR_CMD(0xdb); //--set vcomh
        OLED_WR_CMD(0x20); //0x20,0.77xVcc
        OLED_WR_CMD(0x8d); //--set DC-DC enable
        OLED_WR_CMD(0x14); //
        OLED_WR_CMD(0xaf); //--turn on oled panel

}

//设置光标起始坐标（x,y）
void OLED_Set_Pos(unsigned char x,unsigned char y)
{
        OLED_WR_CMD(0xb0+y);
        OLED_WR_CMD( (x & 0xf0) >> 4 | 0x10 );
        OLED_WR_CMD( (x & 0x0f) | 0x01 );
}

//填充整个屏幕
void OLED_Fill(unsigned char Fill_Data)
{
        unsigned char m,n;

        for(m=0;m<8;m++)
        {
                OLED_WR_CMD(0xb0+m);
                OLED_WR_CMD(0x00);
                OLED_WR_CMD(0x10);

                for(n=0;n<128;n++)
                {
                        OLED_WR_DATA(Fill_Data);
                }
        }
}

//清屏
void OLED_CLS(void)
{
        OLED_Fill(0x00);
}

//将OLED从休眠中唤醒
void OLED_ON(void)
{
        OLED_WR_CMD(0xAF);
        OLED_WR_CMD(0x8D);
        OLED_WR_CMD(0x14);
}

//让OLED休眠 -- 休眠模式下,OLED功耗不到10uA
void OLED_OFF(void)
{
        OLED_WR_CMD(0xAE);
        OLED_WR_CMD(0x8D);
        OLED_WR_CMD(0x10);
}

/**
 * @function: unsigned int oled_pow(uint8_t m,uint8_t n)
 * @description: m^n函数
 * @param {uint8_t} m,n
 * @return {unsigned int} result
 */
unsigned int oled_pow(uint8_t m,uint8_t n)
{
	unsigned int result=1;
	while(n--)result*=m;
	return result;
}

/**
 * @function: void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size,uint8_t Color_Turn)
 * @description: 在OLED12864特定位置开始显示一个字符
 * @param {uint8_t} x字符开始显示的横坐标
 * @param {uint8_t} y字符开始显示的纵坐标
 * @param {uint8_t} chr待显示的字符
 * @param {uint8_t} Char_Size待显示字符的字体大小,选择字体 16/12
 * @param {uint8_t} Color_Turn是否反相显示(1反相、0不反相)
 * @return {*}
 */
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size,uint8_t Color_Turn)
{
	unsigned char c=0,i=0;
		c=chr-' ';//得到偏移后的值
		if(x>128-1){x=0;y=y+2;}
		if(Char_Size ==16)
		{
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
				{
				  if(Color_Turn)
					  OLED_WR_DATA(~F8X16[c*16+i]);
				  else
					  OLED_WR_DATA(F8X16[c*16+i]);
				}
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			    {
				  if(Color_Turn)
					  OLED_WR_DATA(~F8X16[c*16+i+8]);
				  else
					  OLED_WR_DATA(F8X16[c*16+i+8]);
			    }

			}
	     else
	     {
				OLED_Set_Pos(x,y);
				for(i=0;i<6;i++)
			    {
				  if(Color_Turn)
					  OLED_WR_DATA(~F6x8[c][i]);
				  else
					  OLED_WR_DATA(F6x8[c][i]);
			    }
		  }
}



/**
 * @function: void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *chr, uint8_tChar_Size, uint8_t Color_Turn)
 * @description: 在OLED12864特定位置开始显示字符串
 * @param {uint8_t} x待显示字符串的开始横坐标x:0~127
 * @param {uint8_t} y待显示字符串的开始纵坐标 y:0~7，若选择字体大小为16，则两行数字之间需要间隔2，若选择字体大小为12，间隔1
 * @param {uint8_t} *chr待显示的字符串
 * @param {uint8_t} Char_Size待显示字符串的字体大小,选择字体 16/12，16为8X16，12为6x8
 * @param {uint8_t} Color_Turn是否反相显示(1反相、0不反相)
 * @return {*}
 */
void OLED_ShowString(uint8_t x,uint8_t y,char*chr,uint8_t Char_Size, uint8_t Color_Turn)
{
	uint8_t  j=0;
	while (chr[j]!='\0')
	{		OLED_ShowChar(x,y,chr[j],Char_Size, Color_Turn);
			if (Char_Size == 12) //6X8的字体列加6，显示下一个字符
				x += 6;
			else  //8X16的字体列加8，显示下一个字符
				x += 8;

			if (x > 122 && Char_Size==12) //TextSize6x8如果一行不够显示了，从下一行继续显示
			{
				x = 0;
				y++;
			}
			if (x > 120 && Char_Size== 16) //TextSize8x16如果一行不够显示了，从下一行继续显示
			{
				x = 0;
				y++;
			}
			j++;
	}
}

/**
 * @function: void OLED_ShowNum(uint8_t x,uint8_t y,unsigned int num,uint8_t len,uint8_t size2, Color_Turn)
 * @description: 显示数字
 * @param {uint8_t} x待显示的数字起始横坐标,x:0~126
 * @param {uint8_t} y待显示的数字起始纵坐标, y:0~7，若选择字体大小为16，则两行数字之间需要间隔2，若选择字体大小为12，间隔1
 * @param {unsigned int} num:输入的数据
 * @param {uint8_t } len:输入的数据位数
 * @param {uint8_t} size2:输入的数据大小，选择 16/12，16为8X16，12为6x8
 * @param {uint8_t} Color_Turn是否反相显示(1反相、0不反相)
 * @return {*}
 */
void OLED_ShowNum(uint8_t x,uint8_t y,unsigned int num,uint8_t len,uint8_t size2, uint8_t Color_Turn)
{
	uint8_t t,temp;
	uint8_t enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2, Color_Turn);
				continue;
			}else enshow=1;

		}
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2, Color_Turn);
	}
}


/**
 * @function: void OLED_Showdecimal(uint8_t x,uint8_t y,float num,uint8_t z_len,uint8_t f_len,uint8_t size2, uint8_t Color_Turn)
 * @description: 显示正负浮点数
 * @param {uint8_t} x待显示的数字起始横坐标,x:0~126
 * @param {uint8_t} y待显示的数字起始纵坐标, y:0~7，若选择字体大小为16，则两行数字之间需要间隔2，若选择字体大小为12，间隔1
 * @param {float} num:输入的浮点型数据
 * @param {uint8_t } z_ len:整数部分的位数
 * @param {uint8_t } f_len: 小数部分的位数
 * @param {uint8_t} size2:输入的数据大小，选择 16/12，16为8X16，12为6x8
 * @param {uint8_t} Color_Turn是否反相显示(1反相、0不反相)
 * @return {*}
 */
void OLED_Showdecimal(uint8_t x,uint8_t y,float num,uint8_t z_len,uint8_t f_len,uint8_t size2, uint8_t Color_Turn)
{
	uint8_t t,temp,i=0;//i为负数标志位
	uint8_t enshow;
	int z_temp,f_temp;
	if(num<0)
	{
		z_len+=1;
		i=1;
		num=-num;
	}
	z_temp=(int)num;
	//整数部分
	for(t=0;t<z_len;t++)
	{
		temp=(z_temp/oled_pow(10,z_len-t-1))%10;
		if(enshow==0 && t<(z_len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2, Color_Turn);
				continue;
			}
			else
			enshow=1;
		}
		OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2, Color_Turn);
	}
	//小数点
	OLED_ShowChar(x+(size2/2)*(z_len),y,'.',size2, Color_Turn);

	f_temp=(int)((num-z_temp)*(oled_pow(10,f_len)));
  //小数部分
	for(t=0;t<f_len;t++)
	{
		temp=(f_temp/oled_pow(10,f_len-t-1))%10;
		OLED_ShowChar(x+(size2/2)*(t+z_len)+5,y,temp+'0',size2, Color_Turn);
	}
	if(i==1)//如果为负，就将最前的一位赋值‘-’
	{
		OLED_ShowChar(x,y,'-',size2, Color_Turn);
		i=0;
	}
}

/**
 * @function: void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no, uint8_t Color_Turn)
 * @description: 在OLED特定位置开始显示16X16汉字
 * @param {uint8_t} x待显示的汉字起始横坐标x: 0~112，两列汉字之间需要间隔16
 * @param {uint8_t} y待显示的汉字起始纵坐标 y: 0~6 , 两行汉字之间需要间隔2
 * @param {uint8_t} no待显示的汉字编号
 * @param {uint8_t} Color_Turn是否反相显示(1反相、0不反相)
 * @return {*}
 */
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no, uint8_t Color_Turn)
{
	uint8_t t=0;
	OLED_Set_Pos(x,y);
    for(t=0;t<16;t++)
		{
				if (Color_Turn)
					OLED_WR_DATA(~Hzk[2*no][t]); //显示汉字的上半部分
				else
					OLED_WR_DATA(Hzk[2*no][t]); //显示汉字的上半部分
        }

		OLED_Set_Pos(x,y+1);
    for(t=0;t<16;t++)
		{
				if (Color_Turn)
					OLED_WR_DATA(~Hzk[2*no+1][t]); //显示汉字的上半部分
				else
					OLED_WR_DATA(Hzk[2*no+1][t]);//显示汉字的上半部分

         }
}

/**
 * @function: void OLED_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *  BMP,uint8_t Color_Turn)
 * @description: 在OLED特定区域显示BMP图片
 * @param {uint8_t} x0图像开始显示横坐标  x0:0~127
 * @param {uint8_t} y0图像开始显示纵坐标  y0:0~7
 * @param {uint8_t} x1图像结束显示横坐标  x1:1~128
 * @param {uint8_t} y1图像结束显示纵坐标  y1:1~8
 * @param {uint8_t} *BMP待显示的图像数据
 * @param {uint8_t} Color_Turn是否反相显示(1反相、0不反相)
 * @return {*}
 */
void OLED_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *  BMP,uint8_t Color_Turn)
{
   uint32_t j = 0;
   uint8_t x = 0, y = 0;

  if(y1%8==0)
		y = y1/8;
  else
		y = y1/8 + 1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
		{
			if (Color_Turn)
				OLED_WR_DATA(~BMP[j++]);//显示反相图片
			else
				OLED_WR_DATA(BMP[j++]);//显示图片

		}
	}
}


void OLED_work(void)
{
	OLED_Init();
	OLED_CLS();
	
	OLED_ShowChar(0, 0, 'a', 16, 0);
	OLED_ShowCHinese(0, 2, 2, 0);
	OLED_ShowString(0, 4, "aasdfghjkl", 16, 0);
}




