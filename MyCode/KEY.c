#include "KEY.h"
#include "ti/driverlib/dl_gpio.h"
//#include "ti/driverlib/dl_interrupt.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       �������Ƶ�����  ��ע��DL_GPIO_readPins()�ķ���ֵ��
// @param       void
// @return      void
//-------------------------------------------------------------------------------------------------------------------
void Key_work(void)
{
//	if(DL_GPIO_readPins(GPIOA, DL_GPIO_PIN_18) > 0)
	if(DL_GPIO_readPins(GPIOA, DL_GPIO_PIN_18) == DL_GPIO_PIN_18)
	{
		LED0_ON();
        
	}
	
	if(DL_GPIO_readPins(GPIOB, DL_GPIO_PIN_21) == 0)
	{
		LED0_OFF();
	}
	
}

void EXTI_Init(void)
{
	NVIC_EnableIRQ(GPIOB_INT_IRQn);
}



