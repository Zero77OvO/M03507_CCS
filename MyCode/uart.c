#include "uart.h"
#include "ti_msp_dl_config.h"
#include "my_headfile.h"
#include  <string.h>
uint8_t gEchoData = 0;

//usart1 cam
#define USART1_REC_LEN_1  200
uint8_t USART1_RX_BUF_1[USART1_REC_LEN_1];
uint16_t USART1_RX_STA_1=0;
uint8_t USART1_NewData_1;
uint8_t RxState1_1 = 0;

float theta=0; 
float high_rho=0;
float low_rho=0; 




 
float horizon_pid=0;
float vertical_pid=0;





#define USART1_REC_LEN_2  200
uint8_t USART1_RX_BUF_2[USART1_REC_LEN_2];
uint16_t USART1_RX_STA_2=0;
uint8_t USART1_NewData_2;
uint8_t RxState1_2 = 0; 

float x_red=1;
float y_red=1;


#define USART1_REC_LEN_3  200
uint8_t  USART1_RX_BUF_3[USART1_REC_LEN_3];
uint16_t USART1_RX_STA_3;
uint8_t USART1_NewData_3;
uint8_t RxState1_3 = 0; 

float x_green=0;
float y_green=0;

//usart2

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

void uart1_init(void)
{
	NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
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
					USART1_NewData_1= DL_UART_Main_receiveData(UART_0_INST);
					USART1_NewData_2=USART1_NewData_3=USART1_NewData_1;
					//black
					if(RxState1_1 ==0&&USART1_NewData_1==0x1A){
                        USART1_RX_BUF_1[USART1_RX_STA_1]=USART1_NewData_1;
                        RxState1_1 = 1;
                                        }

				else if(RxState1_1 ==1&&USART1_NewData_1==0x2B){
                        USART1_RX_BUF_1[USART1_RX_STA_1++]=USART1_NewData_1;
                        RxState1_1 = 2;
                        }

				else if(RxState1_1 ==2){
				    USART1_RX_BUF_1[USART1_RX_STA_1++]=USART1_NewData_1;
				if(USART1_RX_BUF_1[USART1_RX_STA_1-1]== 0x3C){
					

						theta =  USART1_RX_BUF_1[USART1_RX_STA_1-4];
						high_rho =  USART1_RX_BUF_1[USART1_RX_STA_1-3];
						low_rho =  USART1_RX_BUF_1[USART1_RX_STA_1-2];


						RxState1_1=3; }
				}
				else if(RxState1_1==3){
								USART1_RX_STA_1=0;
								memset(USART1_RX_BUF_1,0,sizeof(USART1_RX_BUF_1));
								RxState1_1=0;
				}
				if(USART1_RX_STA_1>(USART1_REC_LEN_1-1)){
							USART1_RX_STA_1=0;
								memset(USART1_RX_BUF_1,0,sizeof(USART1_RX_BUF_1));
									RxState1_1=0;
					}
			
				}

            
				
            break;
        default:
            break;
    }
}



// void UART_0_INST_IRQHandler(void)
// {
//     switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
//         //关注RX接收数据事件
//         case DL_UART_MAIN_IIDX_RX:
// 				{
// 					gEchoData = DL_UART_Main_receiveData(UART_0_INST);
//           DL_UART_Main_transmitData(UART_0_INST, gEchoData);
// 				}
// //            DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN | GPIO_LEDS_USER_TEST_PIN);
            
				
//             break;
//         default:
//             break;
//     }
// }



// void UART_1_INST_IRQHandler(void)
// {
//     switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) {
//         //关注RX接收数据事件
//         case DL_UART_MAIN_IIDX_RX:
// 				{
// 					USART1_NewData_1= DL_UART_Main_receiveData(UART_1_INST);
// 					USART1_NewData_2=USART1_NewData_3=USART1_NewData_1;
// 					//black
// 					if(RxState1_1 ==0&&USART1_NewData_1==0x1A){
//                         USART1_RX_BUF_1[USART1_RX_STA_1]=USART1_NewData_1;
//                         RxState1_1 = 1;
//                                         }

// 				else if(RxState1_1 ==1&&USART1_NewData_1==0x2B){
//                         USART1_RX_BUF_1[USART1_RX_STA_1++]=USART1_NewData_1;
//                         RxState1_1 = 2;
//                         }

// 				else if(RxState1_1 ==2){
// 				    USART1_RX_BUF_1[USART1_RX_STA_1++]=USART1_NewData_1;
// 				if(USART1_RX_BUF_1[USART1_RX_STA_1-1]== 0x3C){
					

// 						theta =  USART1_RX_BUF_1[USART1_RX_STA_1-4];
// 						high_rho =  USART1_RX_BUF_1[USART1_RX_STA_1-3];
// 						low_rho =  USART1_RX_BUF_1[USART1_RX_STA_1-2];


// 						RxState1_1=3; }
// 				}
// 				else if(RxState1_1==3){
// 								USART1_RX_STA_1=0;
// 								memset(USART1_RX_BUF_1,0,sizeof(USART1_RX_BUF_1));
// 								RxState1_1=0;
// 				}
// 				if(USART1_RX_STA_1>(USART1_REC_LEN_1-1)){
// 							USART1_RX_STA_1=0;
// 								memset(USART1_RX_BUF_1,0,sizeof(USART1_RX_BUF_1));
// 									RxState1_1=0;
// 					}
// 			}
			
	// 	//red
    //             if(RxState1_2 ==0&&USART1_NewData_2==0x2B){
    //                 USART1_RX_BUF_2[USART1_RX_STA_2]=USART1_NewData_2;
    //                 RxState1_2 = 1;
    //                             }

    //             else if(RxState1_2 ==1&&USART1_NewData_2==0x2C){
    //             USART1_RX_BUF_2[USART1_RX_STA_2++]=USART1_NewData_2;
    //             RxState1_2 = 2;
    //             }

    //             else if(RxState1_2==2){
    //             USART1_RX_BUF_2[USART1_RX_STA_2++]=USART1_NewData_2;
    //             if(USART1_RX_BUF_2[USART1_RX_STA_2-1]== 0x25){

    //                     x_red = (float) USART1_RX_BUF_2[USART1_RX_STA_2-3]*2;
    //                     y_red = (float) USART1_RX_BUF_2[USART1_RX_STA_2-2]*2;
    //                             RxState1_2=3; }
    //             }
    //             else if(RxState1_2==3){
    //                             USART1_RX_STA_2=0;
    //                             memset(USART1_RX_BUF_2,0,sizeof(USART1_RX_BUF_2));
    //                             RxState1_2=0;
    //             }
    //             if(USART1_RX_STA_2>(USART1_REC_LEN_2-1)){
    //                         USART1_RX_STA_2=0;
    //                             memset(USART1_RX_BUF_2,0,sizeof(USART1_RX_BUF_2));
    //                                 RxState1_2=0;
    //                 }		



	// //green
			
    //             if(RxState1_3==0&&USART1_NewData_3==0x3A){
    //             USART1_RX_BUF_3[USART1_RX_STA_3]=USART1_NewData_3;
    //             RxState1_3= 1;
    //                             }

    //             else if(RxState1_3==1&&USART1_NewData_3==0x4C){
    //             USART1_RX_BUF_3[USART1_RX_STA_3++]=USART1_NewData_3;
    //             RxState1_3= 2;
    //             }

    //             else if(RxState1_3==2){
    //             USART1_RX_BUF_3[USART1_RX_STA_3++]=USART1_NewData_3;
    //             if(USART1_RX_BUF_3[USART1_RX_STA_3-1]== 0x5D){



    //                     x_green = (float) USART1_RX_BUF_3[USART1_RX_STA_3-3]*2;
    //                     y_green = (float) USART1_RX_BUF_3[USART1_RX_STA_3-2]*2;
    //                             RxState1_3=3; }
    //             }
    //             else if(RxState1_3==3){
    //                             USART1_RX_STA_3=0;
    //                             memset(USART1_RX_BUF_3,0,sizeof(USART1_RX_BUF_3));
    //                             RxState1_3=0;
    //             }
    //             if(USART1_RX_STA_3>(USART1_REC_LEN_3-1)){
    //                         USART1_RX_STA_3=0;
    //                             memset(USART1_RX_BUF_3,0,sizeof(USART1_RX_BUF_3));
    //                                 RxState1_3=0;
    //                 }

						
    	
				

            
				
//             break;
//         default:
//             break;
//     }
// }











