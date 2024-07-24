#include "encoder.h"


int encoder1_num = 10000;
int encoder2_num = 10000;
uint32_t M1_Enter_Is = 0;
uint32_t M2_Enter_Is = 0;
void GROUP1_IRQHandler(void)
{
	

			
        M1_Enter_Is = DL_GPIO_getEnabledInterruptStatus(GPIOB,M1_Encoder_Ti1);
        M2_Enter_Is = DL_GPIO_getEnabledInterruptStatus(GPIOB,M2_Encoder_Ti1);

        if (M1_Enter_Is & M1_Encoder_Ti1) 
    {
        if(DL_GPIO_readPins(GPIOB, M1_Encoder_Ti2))
            encoder1_num++ ;
        else 
            encoder1_num--;
        DL_GPIO_clearInterruptStatus(GPIOB, M1_Encoder_Ti1);
    }

        if (M2_Enter_Is & M2_Encoder_Ti1) 
        {
            if(DL_GPIO_readPins(GPIOB, M2_Encoder_Ti2))
                encoder2_num++;
            else
                encoder2_num--;
            DL_GPIO_clearInterruptStatus(GPIOB, M2_Encoder_Ti1);
        }
			
}
