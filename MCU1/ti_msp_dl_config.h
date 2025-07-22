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



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1562U)



/* Defines for SCREEN */
#define SCREEN_INST                                                        UART0
#define SCREEN_INST_FREQUENCY                                           32000000
#define SCREEN_INST_IRQHandler                                  UART0_IRQHandler
#define SCREEN_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_SCREEN_RX_PORT                                                GPIOA
#define GPIO_SCREEN_TX_PORT                                                GPIOA
#define GPIO_SCREEN_RX_PIN                                         DL_GPIO_PIN_1
#define GPIO_SCREEN_TX_PIN                                         DL_GPIO_PIN_0
#define GPIO_SCREEN_IOMUX_RX                                      (IOMUX_PINCM2)
#define GPIO_SCREEN_IOMUX_TX                                      (IOMUX_PINCM1)
#define GPIO_SCREEN_IOMUX_RX_FUNC                       IOMUX_PINCM2_PF_UART0_RX
#define GPIO_SCREEN_IOMUX_TX_FUNC                       IOMUX_PINCM1_PF_UART0_TX
#define SCREEN_BAUD_RATE                                                  (9600)
#define SCREEN_IBRD_32_MHZ_9600_BAUD                                       (208)
#define SCREEN_FBRD_32_MHZ_9600_BAUD                                        (21)
/* Defines for MOTOR */
#define MOTOR_INST                                                         UART1
#define MOTOR_INST_FREQUENCY                                            32000000
#define MOTOR_INST_IRQHandler                                   UART1_IRQHandler
#define MOTOR_INST_INT_IRQN                                       UART1_INT_IRQn
#define GPIO_MOTOR_RX_PORT                                                 GPIOB
#define GPIO_MOTOR_TX_PORT                                                 GPIOB
#define GPIO_MOTOR_RX_PIN                                          DL_GPIO_PIN_5
#define GPIO_MOTOR_TX_PIN                                          DL_GPIO_PIN_6
#define GPIO_MOTOR_IOMUX_RX                                      (IOMUX_PINCM18)
#define GPIO_MOTOR_IOMUX_TX                                      (IOMUX_PINCM23)
#define GPIO_MOTOR_IOMUX_RX_FUNC                       IOMUX_PINCM18_PF_UART1_RX
#define GPIO_MOTOR_IOMUX_TX_FUNC                       IOMUX_PINCM23_PF_UART1_TX
#define MOTOR_BAUD_RATE                                                 (115200)
#define MOTOR_IBRD_32_MHZ_115200_BAUD                                       (17)
#define MOTOR_FBRD_32_MHZ_115200_BAUD                                       (23)
/* Defines for K230 */
#define K230_INST                                                          UART2
#define K230_INST_FREQUENCY                                             32000000
#define K230_INST_IRQHandler                                    UART2_IRQHandler
#define K230_INST_INT_IRQN                                        UART2_INT_IRQn
#define GPIO_K230_RX_PORT                                                  GPIOA
#define GPIO_K230_TX_PORT                                                  GPIOA
#define GPIO_K230_RX_PIN                                          DL_GPIO_PIN_24
#define GPIO_K230_TX_PIN                                          DL_GPIO_PIN_21
#define GPIO_K230_IOMUX_RX                                       (IOMUX_PINCM54)
#define GPIO_K230_IOMUX_TX                                       (IOMUX_PINCM46)
#define GPIO_K230_IOMUX_RX_FUNC                        IOMUX_PINCM54_PF_UART2_RX
#define GPIO_K230_IOMUX_TX_FUNC                        IOMUX_PINCM46_PF_UART2_TX
#define K230_BAUD_RATE                                                  (115200)
#define K230_IBRD_32_MHZ_115200_BAUD                                        (17)
#define K230_FBRD_32_MHZ_115200_BAUD                                        (23)






/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_SCREEN_init(void);
void SYSCFG_DL_MOTOR_init(void);
void SYSCFG_DL_K230_init(void);
void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
