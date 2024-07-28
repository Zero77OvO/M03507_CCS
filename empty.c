/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "ti_msp_dl_config.h"
#include "my_headfile.h"


uint8_t status;
float pitch=0,roll=0,yaw=0;

int main(void)
{
	board_init();
	SYSCFG_DL_init();
	MPU6050_Init();

	OLED_Init();
	OLED_CLS();

    Timer_A1_init();
    Timer_A2_init();

    uart0_init();
    
    EXTI_Init();
    uint8_t ret = 1;
          
   

    

    while(mpu_dmp_init())
    {
        printf("dmp error\r\n");
        Delay_ms(200);
    }
    printf("Initialization Data Succeed \r\n");

    while(1) 
    {   status = mpu_dmp_get_data(&pitch,&roll,&yaw);
        
        // if( status == 0 )
        // { 
        //     printf("pitch =%d\r\n", (int)pitch);
        //     printf("roll =%d\r\n", (int)roll);
        //     printf("yaw =%d\r\n\r\n", (int)yaw);
        // }
        // Delay_ms(20);

        OLED_ShowNum(0, 0, theta, 2,16, 0);OLED_ShowNum(50, 0, high_rho, 3,16, 0);                                                    
        OLED_ShowNum(0, 2, speed_out_LF, 6,16, 0);OLED_ShowNum(50, 2, low_rho, 3,16, 0);
        OLED_ShowNum(0, 4, encoder1_num, 6,16, 0);
        OLED_ShowNum(0, 6, encoder2_num, 6,16, 0);
        if(yaw>=0){OLED_ShowNum(80, 0, yaw, 6,16, 0);}
        else{OLED_ShowNum(80, 0, -yaw, 6,16, 0);}

        // motor_set_L(speed_out_LF);    
        // motor_set_R(speed_out_rt);
        // motor_set_L(2000);

        


        VOFATransmit();
    }
   
}

