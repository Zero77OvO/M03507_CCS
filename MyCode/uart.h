#ifndef __UART_H_
#define __UART_H_

#include "my_headfile.h"

extern uint8_t gEchoData;

extern float theta; 
extern float high_rho;
extern float low_rho; 

void uart0_init(void);
void uart1_init(void);
void uart3_init(void);
#endif
