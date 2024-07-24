#include "uart.h"
#include "ti_msp_dl_config.h"
#include "my_headfile.h"
#include  <string.h>
uint8_t gEchoData = 0;

#define USART1_REC_LEN  200
uint8_t  USART1_RX_BUF[USART1_REC_LEN];
uint16_t USART1_RX_STA;
uint8_t USART1_NewData;
uint8_t RxState1;

#define USART2_REC_LEN  200
uint8_t  USART2_RX_BUF[USART2_REC_LEN];
uint16_t USART2_RX_STA;
uint8_t USART2_NewData;
uint8_t RxState2;

#define USART3_REC_LEN  200
uint8_t  USART3_RX_BUF[USART3_REC_LEN];
uint16_t USART3_RX_STA;
uint8_t USART3_NewData;
uint8_t RxState3;



void uart0_init(void)
{
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
}
void uart3_init(void)
{
	NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_3_INST_INT_IRQN);
}


void UART_0_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
        //关注RX接收数据事件
        case DL_UART_MAIN_IIDX_RX:
				{
					gEchoData = DL_UART_Main_receiveData(UART_0_INST);
          DL_UART_Main_transmitData(UART_0_INST, gEchoData);
				}
//            DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN | GPIO_LEDS_USER_TEST_PIN);
            
				
            break;
        default:
            break;
    }
}


void uart1_init(void)
{
	NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
}




void UART_1_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) {
        //关注RX接收数据事件
        case DL_UART_MAIN_IIDX_RX:
				{
					USART1_NewData= DL_UART_Main_receiveData(UART_1_INST);
					USART3_NewData= USART1_NewData;
					//black
						if(RxState1 ==0&&USART1_NewData==0x1A){
								 USART1_RX_BUF[USART1_RX_STA]=USART1_NewData;
								 RxState1 = 1;
												}

								 else if(RxState1 ==1&&USART1_NewData==0x2B){
								 USART1_RX_BUF[USART1_RX_STA++]=USART1_NewData;
								 RxState1 = 2;
								 }

								 else if(RxState1 ==2){
								 USART1_RX_BUF[USART1_RX_STA++]=USART1_NewData;
								 if(USART1_RX_BUF[USART1_RX_STA-1]== 0x3C){
									 
										// x1 = USART1_RX_BUF[USART1_RX_STA-9];
										// y1 = USART1_RX_BUF[USART1_RX_STA-8];
										// x2 = USART1_RX_BUF[USART1_RX_STA-7];
										// y2 = USART1_RX_BUF[USART1_RX_STA-6];
										// x3 = USART1_RX_BUF[USART1_RX_STA-5];
										// y3 = USART1_RX_BUF[USART1_RX_STA-4];
										// x4 = USART1_RX_BUF[USART1_RX_STA-3];
										// y4 = USART1_RX_BUF[USART1_RX_STA-2];
												RxState1=3; }
								 }
								 else if(RxState1==3){
												USART1_RX_STA=0;
												memset(USART1_RX_BUF,0,sizeof(USART1_RX_BUF));
												RxState1=0;
								 }
								 if(USART1_RX_STA>(USART1_REC_LEN-1)){
											 USART1_RX_STA=0;
												 memset(USART1_RX_BUF,0,sizeof(USART1_RX_BUF));
													RxState1=0;
									}
								
									
								//red
								if(RxState2 ==0&&USART2_NewData==0x2B){
								 USART2_RX_BUF[USART2_RX_STA]=USART2_NewData;
								 RxState2 = 1;
												}

								 else if(RxState2 ==1&&USART2_NewData==0x2C){
								 USART2_RX_BUF[USART2_RX_STA++]=USART2_NewData;
								RxState2 = 2;
								 }

								 else if(RxState2==2){
								 USART2_RX_BUF[USART2_RX_STA++]=USART2_NewData;
								 if(USART2_RX_BUF[USART2_RX_STA-1]== 0x25){



										x_red = USART2_RX_BUF[USART2_RX_STA-3]*2;
										y_red = USART2_RX_BUF[USART2_RX_STA-2]*2;
												RxState2=3; }
								 }
								 else if(RxState2==3){
												USART2_RX_STA=0;
												memset(USART2_RX_BUF,0,sizeof(USART2_RX_BUF));
												RxState2=0;
								 }
								 if(USART2_RX_STA>(USART2_REC_LEN-1)){
											 USART2_RX_STA=0;
												 memset(USART2_RX_BUF,0,sizeof(USART2_RX_BUF));
													RxState2=0;
									}		



									//green
									
								if(RxState3 ==0&&USART3_NewData==0x3A){
								 USART3_RX_BUF[USART3_RX_STA]=USART3_NewData;
								 RxState3= 1;
												}

								 else if(RxState3==1&&USART3_NewData==0x4C){
								 USART3_RX_BUF[USART3_RX_STA++]=USART3_NewData;
								 RxState3 = 2;
								 }

								 else if(RxState3 ==2){
								 USART3_RX_BUF[USART3_RX_STA++]=USART3_NewData;
								 if(USART3_RX_BUF[USART3_RX_STA-1]== 0x5D){



										x_green = USART3_RX_BUF[USART3_RX_STA-3]*2;
										y_green = USART3_RX_BUF[USART3_RX_STA-2]*2;
												RxState3=3; }
								 }
								 else if(RxState3==3){
												USART3_RX_STA=0;
												memset(USART3_RX_BUF,0,sizeof(USART3_RX_BUF));
												RxState3=0;
								 }
								 if(USART3_RX_STA>(USART3_REC_LEN-1)){
											 USART3_RX_STA=0;
												 memset(USART3_RX_BUF,0,sizeof(USART3_RX_BUF));
													RxState3=0;
									}		
						
					
				}

            
				
            break;
        default:
            break;
    }
}











