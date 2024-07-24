/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMG8
#define PWM_0_INST_IRQHandler                                   TIMG8_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                    405063.2911392405
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                         DL_GPIO_PIN_10
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM27)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM27_PF_TIMG8_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOB
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_11
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM28)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM28_PF_TIMG8_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX

/* Defines for PWM_1 */
#define PWM_1_INST                                                         TIMG7
#define PWM_1_INST_IRQHandler                                   TIMG7_IRQHandler
#define PWM_1_INST_INT_IRQN                                     (TIMG7_INT_IRQn)
#define PWM_1_INST_CLK_FREQ                                    405063.2911392405
/* GPIO defines for channel 0 */
#define GPIO_PWM_1_C0_PORT                                                 GPIOA
#define GPIO_PWM_1_C0_PIN                                         DL_GPIO_PIN_17
#define GPIO_PWM_1_C0_IOMUX                                      (IOMUX_PINCM39)
#define GPIO_PWM_1_C0_IOMUX_FUNC                     IOMUX_PINCM39_PF_TIMG7_CCP0
#define GPIO_PWM_1_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_1_C1_PORT                                                 GPIOA
#define GPIO_PWM_1_C1_PIN                                          DL_GPIO_PIN_7
#define GPIO_PWM_1_C1_IOMUX                                      (IOMUX_PINCM14)
#define GPIO_PWM_1_C1_IOMUX_FUNC                     IOMUX_PINCM14_PF_TIMG7_CCP1
#define GPIO_PWM_1_C1_IDX                                    DL_TIMER_CC_1_INDEX

/* Defines for PWM_2 */
#define PWM_2_INST                                                         TIMG6
#define PWM_2_INST_IRQHandler                                   TIMG6_IRQHandler
#define PWM_2_INST_INT_IRQN                                     (TIMG6_INT_IRQn)
#define PWM_2_INST_CLK_FREQ                                    405063.2911392405
/* GPIO defines for channel 0 */
#define GPIO_PWM_2_C0_PORT                                                 GPIOB
#define GPIO_PWM_2_C0_PIN                                          DL_GPIO_PIN_6
#define GPIO_PWM_2_C0_IOMUX                                      (IOMUX_PINCM23)
#define GPIO_PWM_2_C0_IOMUX_FUNC                     IOMUX_PINCM23_PF_TIMG6_CCP0
#define GPIO_PWM_2_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_2_C1_PORT                                                 GPIOB
#define GPIO_PWM_2_C1_PIN                                          DL_GPIO_PIN_7
#define GPIO_PWM_2_C1_IOMUX                                      (IOMUX_PINCM24)
#define GPIO_PWM_2_C1_IOMUX_FUNC                     IOMUX_PINCM24_PF_TIMG6_CCP1
#define GPIO_PWM_2_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA1)
#define TIMER_0_INST_IRQHandler                                 TIMA1_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA1_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (6249U)
/* Defines for TIMER_1 */
#define TIMER_1_INST                                                     (TIMG0)
#define TIMER_1_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_1_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_1_INST_LOAD_VALUE                                          (3124U)
/* Defines for TIMER_2 */
#define TIMER_2_INST                                                     (TIMA0)
#define TIMER_2_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_2_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_2_INST_LOAD_VALUE                                           (312U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          100000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SDA_PIN                                   DL_GPIO_PIN_3
#define GPIO_I2C_MPU6050_IOMUX_SDA                               (IOMUX_PINCM16)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SCL_PIN                                   DL_GPIO_PIN_2
#define GPIO_I2C_MPU6050_IOMUX_SCL                               (IOMUX_PINCM15)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                IOMUX_PINCM15_PF_I2C1_SCL

/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C0
#define I2C_0_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C0_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                100000
#define GPIO_I2C_0_SDA_PORT                                                GPIOA
#define GPIO_I2C_0_SDA_PIN                                        DL_GPIO_PIN_10
#define GPIO_I2C_0_IOMUX_SDA                                     (IOMUX_PINCM21)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                      IOMUX_PINCM21_PF_I2C0_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOA
#define GPIO_I2C_0_SCL_PIN                                        DL_GPIO_PIN_11
#define GPIO_I2C_0_IOMUX_SCL                                     (IOMUX_PINCM22)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                      IOMUX_PINCM22_PF_I2C0_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_31
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_28
#define GPIO_UART_0_IOMUX_RX                                      (IOMUX_PINCM6)
#define GPIO_UART_0_IOMUX_TX                                      (IOMUX_PINCM3)
#define GPIO_UART_0_IOMUX_RX_FUNC                       IOMUX_PINCM6_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                       IOMUX_PINCM3_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_0_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOB
#define GPIO_UART_1_TX_PORT                                                GPIOB
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_5
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_4
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM18)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM17)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM18_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM17_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_1_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_2 */
#define UART_2_INST                                                        UART2
#define UART_2_INST_IRQHandler                                  UART2_IRQHandler
#define UART_2_INST_INT_IRQN                                      UART2_INT_IRQn
#define GPIO_UART_2_RX_PORT                                                GPIOB
#define GPIO_UART_2_TX_PORT                                                GPIOB
#define GPIO_UART_2_RX_PIN                                        DL_GPIO_PIN_16
#define GPIO_UART_2_TX_PIN                                        DL_GPIO_PIN_15
#define GPIO_UART_2_IOMUX_RX                                     (IOMUX_PINCM33)
#define GPIO_UART_2_IOMUX_TX                                     (IOMUX_PINCM32)
#define GPIO_UART_2_IOMUX_RX_FUNC                      IOMUX_PINCM33_PF_UART2_RX
#define GPIO_UART_2_IOMUX_TX_FUNC                      IOMUX_PINCM32_PF_UART2_TX
#define UART_2_BAUD_RATE                                                (115200)
#define UART_2_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_2_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_3 */
#define UART_3_INST                                                        UART3
#define UART_3_INST_IRQHandler                                  UART3_IRQHandler
#define UART_3_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_UART_3_RX_PORT                                                GPIOA
#define GPIO_UART_3_TX_PORT                                                GPIOA
#define GPIO_UART_3_RX_PIN                                        DL_GPIO_PIN_13
#define GPIO_UART_3_TX_PIN                                        DL_GPIO_PIN_14
#define GPIO_UART_3_IOMUX_RX                                     (IOMUX_PINCM35)
#define GPIO_UART_3_IOMUX_TX                                     (IOMUX_PINCM36)
#define GPIO_UART_3_IOMUX_RX_FUNC                      IOMUX_PINCM35_PF_UART3_RX
#define GPIO_UART_3_IOMUX_TX_FUNC                      IOMUX_PINCM36_PF_UART3_TX
#define UART_3_BAUD_RATE                                                (115200)
#define UART_3_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_3_FBRD_32_MHZ_115200_BAUD                                      (23)





/* Defines for ADC12_0 */
#define ADC12_0_INST                                                        ADC0
#define ADC12_0_INST_IRQHandler                                  ADC0_IRQHandler
#define ADC12_0_INST_INT_IRQN                                    (ADC0_INT_IRQn)
#define ADC12_0_ADCMEM_0                                      DL_ADC12_MEM_IDX_0
#define ADC12_0_ADCMEM_0_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_0_ADCMEM_0_REF_VOLTAGE_V                                       3.3
#define GPIO_ADC12_0_C0_PORT                                               GPIOA
#define GPIO_ADC12_0_C0_PIN                                       DL_GPIO_PIN_27

/* Defines for ADC12_1 */
#define ADC12_1_INST                                                        ADC1
#define ADC12_1_INST_IRQHandler                                  ADC1_IRQHandler
#define ADC12_1_INST_INT_IRQN                                    (ADC1_INT_IRQn)
#define ADC12_1_ADCMEM_0                                      DL_ADC12_MEM_IDX_0
#define ADC12_1_ADCMEM_0_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_1_ADCMEM_0_REF_VOLTAGE_V                                       3.3
#define GPIO_ADC12_1_C0_PORT                                               GPIOA
#define GPIO_ADC12_1_C0_PIN                                       DL_GPIO_PIN_15





/* Port definition for Pin Group TB6612A0 */
#define TB6612A0_PORT                                                    (GPIOB)

/* Defines for PIN_0: GPIOB.13 with pinCMx 30 on package pin 1 */
#define TB6612A0_PIN_0_PIN                                      (DL_GPIO_PIN_13)
#define TB6612A0_PIN_0_IOMUX                                     (IOMUX_PINCM30)
/* Port definition for Pin Group TB6612A1 */
#define TB6612A1_PORT                                                    (GPIOA)

/* Defines for PIN_2: GPIOA.16 with pinCMx 38 on package pin 9 */
#define TB6612A1_PIN_2_PIN                                      (DL_GPIO_PIN_16)
#define TB6612A1_PIN_2_IOMUX                                     (IOMUX_PINCM38)
/* Port definition for Pin Group TB6612B0 */
#define TB6612B0_PORT                                                    (GPIOA)

/* Defines for PIN_3: GPIOA.12 with pinCMx 34 on package pin 5 */
#define TB6612B0_PIN_3_PIN                                      (DL_GPIO_PIN_12)
#define TB6612B0_PIN_3_IOMUX                                     (IOMUX_PINCM34)
/* Port definition for Pin Group TB6612B1 */
#define TB6612B1_PORT                                                    (GPIOA)

/* Defines for PIN_4: GPIOA.24 with pinCMx 54 on package pin 25 */
#define TB6612B1_PIN_4_PIN                                      (DL_GPIO_PIN_24)
#define TB6612B1_PIN_4_IOMUX                                     (IOMUX_PINCM54)
/* Defines for LED_1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LEDS_LED_1_PORT                                             (GPIOB)
#define GPIO_LEDS_LED_1_PIN                                     (DL_GPIO_PIN_22)
#define GPIO_LEDS_LED_1_IOMUX                                    (IOMUX_PINCM50)
/* Defines for LED_2: GPIOA.26 with pinCMx 59 on package pin 30 */
#define GPIO_LEDS_LED_2_PORT                                             (GPIOA)
#define GPIO_LEDS_LED_2_PIN                                     (DL_GPIO_PIN_26)
#define GPIO_LEDS_LED_2_IOMUX                                    (IOMUX_PINCM59)
/* Defines for LED_3: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_LEDS_LED_3_PORT                                             (GPIOB)
#define GPIO_LEDS_LED_3_PIN                                     (DL_GPIO_PIN_27)
#define GPIO_LEDS_LED_3_IOMUX                                    (IOMUX_PINCM58)
/* Defines for PIN_1: GPIOA.18 with pinCMx 40 on package pin 11 */
#define GPIO_KEYS_PIN_1_PORT                                             (GPIOA)
#define GPIO_KEYS_PIN_1_PIN                                     (DL_GPIO_PIN_18)
#define GPIO_KEYS_PIN_1_IOMUX                                    (IOMUX_PINCM40)
/* Defines for PIN_5: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_KEYS_PIN_5_PORT                                             (GPIOB)
#define GPIO_KEYS_PIN_5_PIN                                     (DL_GPIO_PIN_21)
#define GPIO_KEYS_PIN_5_IOMUX                                    (IOMUX_PINCM49)
/* Port definition for Pin Group GPIO_Encoders */
#define GPIO_Encoders_PORT                                               (GPIOB)

/* Defines for M2_B0_TI1: GPIOB.0 with pinCMx 12 on package pin 47 */
// pins affected by this interrupt request:["M2_B0_TI1","M1_B18_TI1"]
#define GPIO_Encoders_INT_IRQN                                  (GPIOB_INT_IRQn)
#define GPIO_Encoders_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoders_M2_B0_TI1_IIDX                         (DL_GPIO_IIDX_DIO0)
#define GPIO_Encoders_M2_B0_TI1_PIN                              (DL_GPIO_PIN_0)
#define GPIO_Encoders_M2_B0_TI1_IOMUX                            (IOMUX_PINCM12)
/* Defines for M2_B1_TI2: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_Encoders_M2_B1_TI2_PIN                              (DL_GPIO_PIN_1)
#define GPIO_Encoders_M2_B1_TI2_IOMUX                            (IOMUX_PINCM13)
/* Defines for M1_B18_TI1: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_Encoders_M1_B18_TI1_IIDX                       (DL_GPIO_IIDX_DIO18)
#define GPIO_Encoders_M1_B18_TI1_PIN                            (DL_GPIO_PIN_18)
#define GPIO_Encoders_M1_B18_TI1_IOMUX                           (IOMUX_PINCM44)
/* Defines for M1_B17_TI2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_Encoders_M1_B17_TI2_PIN                            (DL_GPIO_PIN_17)
#define GPIO_Encoders_M1_B17_TI2_IOMUX                           (IOMUX_PINCM43)
/* Port definition for Pin Group MPU6050 */
#define MPU6050_PORT                                                     (GPIOA)

/* Defines for MPU6050_SDA: GPIOA.8 with pinCMx 19 on package pin 54 */
#define MPU6050_MPU6050_SDA_PIN                                  (DL_GPIO_PIN_8)
#define MPU6050_MPU6050_SDA_IOMUX                                (IOMUX_PINCM19)
/* Defines for MPU6050_SCL: GPIOA.9 with pinCMx 20 on package pin 55 */
#define MPU6050_MPU6050_SCL_PIN                                  (DL_GPIO_PIN_9)
#define MPU6050_MPU6050_SCL_IOMUX                                (IOMUX_PINCM20)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_PWM_1_init(void);
void SYSCFG_DL_PWM_2_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_1_init(void);
void SYSCFG_DL_TIMER_2_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_I2C_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART_2_init(void);
void SYSCFG_DL_UART_3_init(void);
void SYSCFG_DL_ADC12_0_init(void);
void SYSCFG_DL_ADC12_1_init(void);
void SYSCFG_DL_DMA_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
