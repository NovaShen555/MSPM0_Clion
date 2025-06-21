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
#define CONFIG_MSPM0G3507

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



/* Defines for Motor */
#define Motor_INST                                                         TIMA1
#define Motor_INST_IRQHandler                                   TIMA1_IRQHandler
#define Motor_INST_INT_IRQN                                     (TIMA1_INT_IRQn)
#define Motor_INST_CLK_FREQ                                             32000000
/* GPIO defines for channel 0 */
#define GPIO_Motor_C0_PORT                                                 GPIOA
#define GPIO_Motor_C0_PIN                                         DL_GPIO_PIN_28
#define GPIO_Motor_C0_IOMUX                                       (IOMUX_PINCM3)
#define GPIO_Motor_C0_IOMUX_FUNC                      IOMUX_PINCM3_PF_TIMA1_CCP0
#define GPIO_Motor_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_Motor_C1_PORT                                                 GPIOA
#define GPIO_Motor_C1_PIN                                         DL_GPIO_PIN_24
#define GPIO_Motor_C1_IOMUX                                      (IOMUX_PINCM54)
#define GPIO_Motor_C1_IOMUX_FUNC                     IOMUX_PINCM54_PF_TIMA1_CCP1
#define GPIO_Motor_C1_IDX                                    DL_TIMER_CC_1_INDEX




/* Defines for QEI_0 */
#define QEI_0_INST                                                         TIMG8
#define QEI_0_INST_IRQHandler                                   TIMG8_IRQHandler
#define QEI_0_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
/* Pin configuration defines for QEI_0 PHA Pin */
#define GPIO_QEI_0_PHA_PORT                                                GPIOA
#define GPIO_QEI_0_PHA_PIN                                        DL_GPIO_PIN_29
#define GPIO_QEI_0_PHA_IOMUX                                      (IOMUX_PINCM4)
#define GPIO_QEI_0_PHA_IOMUX_FUNC                     IOMUX_PINCM4_PF_TIMG8_CCP0
/* Pin configuration defines for QEI_0 PHB Pin */
#define GPIO_QEI_0_PHB_PORT                                                GPIOA
#define GPIO_QEI_0_PHB_PIN                                        DL_GPIO_PIN_27
#define GPIO_QEI_0_PHB_IOMUX                                     (IOMUX_PINCM60)
#define GPIO_QEI_0_PHB_IOMUX_FUNC                    IOMUX_PINCM60_PF_TIMG8_CCP1
/* Pin configuration defines for QEI_0 IDX Pin */
#define GPIO_QEI_0_IDX_PORT                                                GPIOA
#define GPIO_QEI_0_IDX_PIN                                        DL_GPIO_PIN_15
#define GPIO_QEI_0_IDX_IOMUX                                     (IOMUX_PINCM37)
#define GPIO_QEI_0_IDX_IOMUX_FUNC                     IOMUX_PINCM37_PF_TIMG8_IDX


/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (39999U)




/* Defines for I2C_OLED */
#define I2C_OLED_INST                                                       I2C0
#define I2C_OLED_INST_IRQHandler                                 I2C0_IRQHandler
#define I2C_OLED_INST_INT_IRQN                                     I2C0_INT_IRQn
#define I2C_OLED_BUS_SPEED_HZ                                             400000
#define GPIO_I2C_OLED_SDA_PORT                                             GPIOA
#define GPIO_I2C_OLED_SDA_PIN                                      DL_GPIO_PIN_0
#define GPIO_I2C_OLED_IOMUX_SDA                                   (IOMUX_PINCM1)
#define GPIO_I2C_OLED_IOMUX_SDA_FUNC                    IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_OLED_SCL_PORT                                             GPIOA
#define GPIO_I2C_OLED_SCL_PIN                                      DL_GPIO_PIN_1
#define GPIO_I2C_OLED_IOMUX_SCL                                   (IOMUX_PINCM2)
#define GPIO_I2C_OLED_IOMUX_SCL_FUNC                    IOMUX_PINCM2_PF_I2C0_SCL


/* Defines for UART_1 */
#define UART_1_INST                                                        UART3
#define UART_1_INST_FREQUENCY                                           32000000
#define UART_1_INST_IRQHandler                                  UART3_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                        DL_GPIO_PIN_13
#define GPIO_UART_1_TX_PIN                                        DL_GPIO_PIN_14
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM35)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM36)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM35_PF_UART3_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM36_PF_UART3_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_1_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_0 */
#define UART_0_INST                                                        UART2
#define UART_0_INST_FREQUENCY                                           32000000
#define UART_0_INST_IRQHandler                                  UART2_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART2_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_22
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_21
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM47)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM46)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM47_PF_UART2_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM46_PF_UART2_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_0_FBRD_32_MHZ_9600_BAUD                                        (21)
/* Defines for UART_2 */
#define UART_2_INST                                                        UART1
#define UART_2_INST_FREQUENCY                                           32000000
#define UART_2_INST_IRQHandler                                  UART1_IRQHandler
#define UART_2_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_2_RX_PORT                                                GPIOA
#define GPIO_UART_2_TX_PORT                                                GPIOA
#define GPIO_UART_2_RX_PIN                                        DL_GPIO_PIN_18
#define GPIO_UART_2_TX_PIN                                        DL_GPIO_PIN_17
#define GPIO_UART_2_IOMUX_RX                                     (IOMUX_PINCM40)
#define GPIO_UART_2_IOMUX_TX                                     (IOMUX_PINCM39)
#define GPIO_UART_2_IOMUX_RX_FUNC                      IOMUX_PINCM40_PF_UART1_RX
#define GPIO_UART_2_IOMUX_TX_FUNC                      IOMUX_PINCM39_PF_UART1_TX
#define UART_2_BAUD_RATE                                                  (9600)
#define UART_2_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_2_FBRD_32_MHZ_9600_BAUD                                        (21)
/* Defines for UART_3 */
#define UART_3_INST                                                        UART0
#define UART_3_INST_FREQUENCY                                           32000000
#define UART_3_INST_IRQHandler                                  UART0_IRQHandler
#define UART_3_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_3_RX_PORT                                                GPIOA
#define GPIO_UART_3_TX_PORT                                                GPIOA
#define GPIO_UART_3_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_3_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_3_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_3_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_3_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_3_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_3_BAUD_RATE                                                (115200)
#define UART_3_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_3_FBRD_32_MHZ_115200_BAUD                                      (23)




/* Defines for SPI_MCU */
#define SPI_MCU_INST                                                       SPI1
#define SPI_MCU_INST_IRQHandler                                 SPI1_IRQHandler
#define SPI_MCU_INST_INT_IRQN                                     SPI1_INT_IRQn
#define GPIO_SPI_MCU_PICO_PORT                                            GPIOB
#define GPIO_SPI_MCU_PICO_PIN                                    DL_GPIO_PIN_22
#define GPIO_SPI_MCU_IOMUX_PICO                                 (IOMUX_PINCM50)
#define GPIO_SPI_MCU_IOMUX_PICO_FUNC                 IOMUX_PINCM50_PF_SPI1_PICO
#define GPIO_SPI_MCU_POCI_PORT                                            GPIOA
#define GPIO_SPI_MCU_POCI_PIN                                    DL_GPIO_PIN_16
#define GPIO_SPI_MCU_IOMUX_POCI                                 (IOMUX_PINCM38)
#define GPIO_SPI_MCU_IOMUX_POCI_FUNC                 IOMUX_PINCM38_PF_SPI1_POCI
/* GPIO configuration for SPI_MCU */
#define GPIO_SPI_MCU_SCLK_PORT                                            GPIOB
#define GPIO_SPI_MCU_SCLK_PIN                                    DL_GPIO_PIN_23
#define GPIO_SPI_MCU_IOMUX_SCLK                                 (IOMUX_PINCM51)
#define GPIO_SPI_MCU_IOMUX_SCLK_FUNC                 IOMUX_PINCM51_PF_SPI1_SCLK
#define GPIO_SPI_MCU_CS0_PORT                                             GPIOA
#define GPIO_SPI_MCU_CS0_PIN                                     DL_GPIO_PIN_26
#define GPIO_SPI_MCU_IOMUX_CS0                                  (IOMUX_PINCM59)
#define GPIO_SPI_MCU_IOMUX_CS0_FUNC                   IOMUX_PINCM59_PF_SPI1_CS0
/* Defines for SPI_OLED */
#define SPI_OLED_INST                                                      SPI0
#define SPI_OLED_INST_IRQHandler                                SPI0_IRQHandler
#define SPI_OLED_INST_INT_IRQN                                    SPI0_INT_IRQn
#define GPIO_SPI_OLED_PICO_PORT                                           GPIOA
#define GPIO_SPI_OLED_PICO_PIN                                    DL_GPIO_PIN_5
#define GPIO_SPI_OLED_IOMUX_PICO                                (IOMUX_PINCM10)
#define GPIO_SPI_OLED_IOMUX_PICO_FUNC                IOMUX_PINCM10_PF_SPI0_PICO
/* GPIO configuration for SPI_OLED */
#define GPIO_SPI_OLED_SCLK_PORT                                           GPIOA
#define GPIO_SPI_OLED_SCLK_PIN                                   DL_GPIO_PIN_12
#define GPIO_SPI_OLED_IOMUX_SCLK                                (IOMUX_PINCM34)
#define GPIO_SPI_OLED_IOMUX_SCLK_FUNC                IOMUX_PINCM34_PF_SPI0_SCLK
#define GPIO_SPI_OLED_CS0_PORT                                            GPIOA
#define GPIO_SPI_OLED_CS0_PIN                                     DL_GPIO_PIN_2
#define GPIO_SPI_OLED_IOMUX_CS0                                  (IOMUX_PINCM7)
#define GPIO_SPI_OLED_IOMUX_CS0_FUNC                   IOMUX_PINCM7_PF_SPI0_CS0
#define GPIO_SPI_OLED_CD_PORT                                             GPIOA
#define GPIO_SPI_OLED_CD_PIN                                     DL_GPIO_PIN_23
#define GPIO_SPI_OLED_IOMUX_CD                                  (IOMUX_PINCM53)
#define GPIO_SPI_OLED_IOMUX_CD_FUNC          IOMUX_PINCM53_PF_SPI0_CS3_CD_POCI3



/* Defines for DMA_SPI */
#define DMA_SPI_CHAN_ID                                                      (1)
#define SPI_MCU_INST_DMA_TRIGGER                              (DMA_SPI1_RX_TRIG)


/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOB)

/* Defines for PIN_14: GPIOB.14 with pinCMx 31 on package pin 2 */
#define LED_PIN_14_PIN                                          (DL_GPIO_PIN_14)
#define LED_PIN_14_IOMUX                                         (IOMUX_PINCM31)
/* Port definition for Pin Group Butter */
#define Butter_PORT                                                      (GPIOB)

/* Defines for S2: GPIOB.21 with pinCMx 49 on package pin 20 */
#define Butter_S2_PIN                                           (DL_GPIO_PIN_21)
#define Butter_S2_IOMUX                                          (IOMUX_PINCM49)
/* Port definition for Pin Group TB6612 */
#define TB6612_PORT                                                      (GPIOB)

/* Defines for AIN1: GPIOB.13 with pinCMx 30 on package pin 1 */
#define TB6612_AIN1_PIN                                         (DL_GPIO_PIN_13)
#define TB6612_AIN1_IOMUX                                        (IOMUX_PINCM30)
/* Defines for AIN2: GPIOB.15 with pinCMx 32 on package pin 3 */
#define TB6612_AIN2_PIN                                         (DL_GPIO_PIN_15)
#define TB6612_AIN2_IOMUX                                        (IOMUX_PINCM32)
/* Defines for BIN1: GPIOB.16 with pinCMx 33 on package pin 4 */
#define TB6612_BIN1_PIN                                         (DL_GPIO_PIN_16)
#define TB6612_BIN1_IOMUX                                        (IOMUX_PINCM33)
/* Defines for BIN2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define TB6612_BIN2_PIN                                         (DL_GPIO_PIN_17)
#define TB6612_BIN2_IOMUX                                        (IOMUX_PINCM43)
/* Port definition for Pin Group OLED_SPI */
#define OLED_SPI_PORT                                                    (GPIOB)

/* Defines for RES: GPIOB.18 with pinCMx 44 on package pin 15 */
#define OLED_SPI_RES_PIN                                        (DL_GPIO_PIN_18)
#define OLED_SPI_RES_IOMUX                                       (IOMUX_PINCM44)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_Motor_init(void);
void SYSCFG_DL_QEI_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_OLED_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_2_init(void);
void SYSCFG_DL_UART_3_init(void);
void SYSCFG_DL_SPI_MCU_init(void);
void SYSCFG_DL_SPI_OLED_init(void);
void SYSCFG_DL_DMA_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
