#include "Delay.h"


void delay_ms(uint32_t ms)
{
	while(ms --)
		DL_Common_delayCycles(32000);
}

void delay_us(uint32_t us)
{
	while(us --)
		DL_Common_delayCycles(32);
}
