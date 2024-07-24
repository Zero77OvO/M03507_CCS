#include "OLED.h"
#include "OLED_Font.h"
#include "ti/driverlib/dl_i2c.h"

#define OLED_I2C I2C0
#define OLED_ADDR   0x3C

void OLED_I2C_Init(void)
{

}

//��OLED�Ĵ�����ַдһ��byte������
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



//дָ��
void OLED_WR_CMD(unsigned char I2C_Command)
{
        I2C_WriteByte(0x00,I2C_Command);
}

//д����
void OLED_WR_DATA(unsigned char I2C_Data)
{
        I2C_WriteByte(0x40,I2C_Data);
}

//���ҳ�ʼ������
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
        OLED_WR_CMD(0xff); //����?���̡�?�� 0x00~0xff
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

//���ù����ʼ���꣨x,y��
void OLED_Set_Pos(unsigned char x,unsigned char y)
{
        OLED_WR_CMD(0xb0+y);
        OLED_WR_CMD( (x & 0xf0) >> 4 | 0x10 );
        OLED_WR_CMD( (x & 0x0f) | 0x01 );
}

//���������Ļ
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

//����
void OLED_CLS(void)
{
        OLED_Fill(0x00);
}

//��OLED�������л���
void OLED_ON(void)
{
        OLED_WR_CMD(0xAF);
        OLED_WR_CMD(0x8D);
        OLED_WR_CMD(0x14);
}

//��OLED���� -- ����ģʽ��,OLED���Ĳ���10uA
void OLED_OFF(void)
{
        OLED_WR_CMD(0xAE);
        OLED_WR_CMD(0x8D);
        OLED_WR_CMD(0x10);
}

/**
 * @function: unsigned int oled_pow(uint8_t m,uint8_t n)
 * @description: m^n����
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
 * @description: ��OLED12864�ض�λ�ÿ�ʼ��ʾһ���ַ�
 * @param {uint8_t} x�ַ���ʼ��ʾ�ĺ�����
 * @param {uint8_t} y�ַ���ʼ��ʾ��������
 * @param {uint8_t} chr����ʾ���ַ�
 * @param {uint8_t} Char_Size����ʾ�ַ��������С,ѡ������ 16/12
 * @param {uint8_t} Color_Turn�Ƿ�����ʾ(1���ࡢ0������)
 * @return {*}
 */
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size,uint8_t Color_Turn)
{
	unsigned char c=0,i=0;
		c=chr-' ';//�õ�ƫ�ƺ��ֵ
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
 * @description: ��OLED12864�ض�λ�ÿ�ʼ��ʾ�ַ���
 * @param {uint8_t} x����ʾ�ַ����Ŀ�ʼ������x:0~127
 * @param {uint8_t} y����ʾ�ַ����Ŀ�ʼ������ y:0~7����ѡ�������СΪ16������������֮����Ҫ���2����ѡ�������СΪ12�����1
 * @param {uint8_t} *chr����ʾ���ַ���
 * @param {uint8_t} Char_Size����ʾ�ַ����������С,ѡ������ 16/12��16Ϊ8X16��12Ϊ6x8
 * @param {uint8_t} Color_Turn�Ƿ�����ʾ(1���ࡢ0������)
 * @return {*}
 */
void OLED_ShowString(uint8_t x,uint8_t y,char*chr,uint8_t Char_Size, uint8_t Color_Turn)
{
	uint8_t  j=0;
	while (chr[j]!='\0')
	{		OLED_ShowChar(x,y,chr[j],Char_Size, Color_Turn);
			if (Char_Size == 12) //6X8�������м�6����ʾ��һ���ַ�
				x += 6;
			else  //8X16�������м�8����ʾ��һ���ַ�
				x += 8;

			if (x > 122 && Char_Size==12) //TextSize6x8���һ�в�����ʾ�ˣ�����һ�м�����ʾ
			{
				x = 0;
				y++;
			}
			if (x > 120 && Char_Size== 16) //TextSize8x16���һ�в�����ʾ�ˣ�����һ�м�����ʾ
			{
				x = 0;
				y++;
			}
			j++;
	}
}

/**
 * @function: void OLED_ShowNum(uint8_t x,uint8_t y,unsigned int num,uint8_t len,uint8_t size2, Color_Turn)
 * @description: ��ʾ����
 * @param {uint8_t} x����ʾ��������ʼ������,x:0~126
 * @param {uint8_t} y����ʾ��������ʼ������, y:0~7����ѡ�������СΪ16������������֮����Ҫ���2����ѡ�������СΪ12�����1
 * @param {unsigned int} num:���������
 * @param {uint8_t } len:���������λ��
 * @param {uint8_t} size2:��������ݴ�С��ѡ�� 16/12��16Ϊ8X16��12Ϊ6x8
 * @param {uint8_t} Color_Turn�Ƿ�����ʾ(1���ࡢ0������)
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
 * @description: ��ʾ����������
 * @param {uint8_t} x����ʾ��������ʼ������,x:0~126
 * @param {uint8_t} y����ʾ��������ʼ������, y:0~7����ѡ�������СΪ16������������֮����Ҫ���2����ѡ�������СΪ12�����1
 * @param {float} num:����ĸ���������
 * @param {uint8_t } z_ len:�������ֵ�λ��
 * @param {uint8_t } f_len: С�����ֵ�λ��
 * @param {uint8_t} size2:��������ݴ�С��ѡ�� 16/12��16Ϊ8X16��12Ϊ6x8
 * @param {uint8_t} Color_Turn�Ƿ�����ʾ(1���ࡢ0������)
 * @return {*}
 */
void OLED_Showdecimal(uint8_t x,uint8_t y,float num,uint8_t z_len,uint8_t f_len,uint8_t size2, uint8_t Color_Turn)
{
	uint8_t t,temp,i=0;//iΪ������־λ
	uint8_t enshow;
	int z_temp,f_temp;
	if(num<0)
	{
		z_len+=1;
		i=1;
		num=-num;
	}
	z_temp=(int)num;
	//��������
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
	//С����
	OLED_ShowChar(x+(size2/2)*(z_len),y,'.',size2, Color_Turn);

	f_temp=(int)((num-z_temp)*(oled_pow(10,f_len)));
  //С������
	for(t=0;t<f_len;t++)
	{
		temp=(f_temp/oled_pow(10,f_len-t-1))%10;
		OLED_ShowChar(x+(size2/2)*(t+z_len)+5,y,temp+'0',size2, Color_Turn);
	}
	if(i==1)//���Ϊ�����ͽ���ǰ��һλ��ֵ��-��
	{
		OLED_ShowChar(x,y,'-',size2, Color_Turn);
		i=0;
	}
}

/**
 * @function: void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no, uint8_t Color_Turn)
 * @description: ��OLED�ض�λ�ÿ�ʼ��ʾ16X16����
 * @param {uint8_t} x����ʾ�ĺ�����ʼ������x: 0~112�����к���֮����Ҫ���16
 * @param {uint8_t} y����ʾ�ĺ�����ʼ������ y: 0~6 , ���к���֮����Ҫ���2
 * @param {uint8_t} no����ʾ�ĺ��ֱ��
 * @param {uint8_t} Color_Turn�Ƿ�����ʾ(1���ࡢ0������)
 * @return {*}
 */
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no, uint8_t Color_Turn)
{
	uint8_t t=0;
	OLED_Set_Pos(x,y);
    for(t=0;t<16;t++)
		{
				if (Color_Turn)
					OLED_WR_DATA(~Hzk[2*no][t]); //��ʾ���ֵ��ϰ벿��
				else
					OLED_WR_DATA(Hzk[2*no][t]); //��ʾ���ֵ��ϰ벿��
        }

		OLED_Set_Pos(x,y+1);
    for(t=0;t<16;t++)
		{
				if (Color_Turn)
					OLED_WR_DATA(~Hzk[2*no+1][t]); //��ʾ���ֵ��ϰ벿��
				else
					OLED_WR_DATA(Hzk[2*no+1][t]);//��ʾ���ֵ��ϰ벿��

         }
}

/**
 * @function: void OLED_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *  BMP,uint8_t Color_Turn)
 * @description: ��OLED�ض�������ʾBMPͼƬ
 * @param {uint8_t} x0ͼ��ʼ��ʾ������  x0:0~127
 * @param {uint8_t} y0ͼ��ʼ��ʾ������  y0:0~7
 * @param {uint8_t} x1ͼ�������ʾ������  x1:1~128
 * @param {uint8_t} y1ͼ�������ʾ������  y1:1~8
 * @param {uint8_t} *BMP����ʾ��ͼ������
 * @param {uint8_t} Color_Turn�Ƿ�����ʾ(1���ࡢ0������)
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
				OLED_WR_DATA(~BMP[j++]);//��ʾ����ͼƬ
			else
				OLED_WR_DATA(BMP[j++]);//��ʾͼƬ

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




