/*
 * 立创开发板�?�?件资料与相关扩展板软�?件资料官网全部开�?
 * 开发板官网：www.lckfb.com
 * 技�?�?持常驻�?�坛，任何技�?�?题�?�迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养�?国工程师为己�?
 * Change Logs:
 * Date           Author       Notes
 * 2024-05-23     LCKFB     first version
 */
#include "board.h"
#include "stdio.h"
#include "string.h"

volatile unsigned int delay_times = 0;
volatile unsigned char uart_data = 0;

void board_init(void)
{
	

	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(I2C_MPU6050_INST_INT_IRQN);
}

void Delay_us(unsigned long us) 
{
    while(us--)
        delay_cycles(CPUCLK_FREQ/1000000);
}

void Delay_ms(unsigned long ms) 
{
    while(ms--)
	    delay_cycles(CPUCLK_FREQ/1000);
}

void delay_1us(unsigned long __us)
{ 
    Delay_us(__us); 
}

void delay_1ms(unsigned long ms)
{ 
    Delay_ms(ms); 
}

int fputc(int c, FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART_0_INST, c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_0_INST, s[i]);
    }
    return len;
}

int puts(const char *_ptr)
{
    int count = fputs(_ptr, stdout);
    count += fputs("\n", stdout);
    return count;
}

