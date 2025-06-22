//
// Created by 34575 on 25-6-21.
//

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <../../ti_msp_dl_config.h>
#include <stdio.h>
#include <stdarg.h>
#include <bsp_spi.h>

void MSP_Delay_us(uint32_t nus);
void MSP_Delay_ms(uint32_t nms);

int Uprintf(UART_Regs * uart,const char *fmt, ...);

void LED_ON(void);
void LED_OFF(void);
void LED_Toggle(void);
void LED_Set(bool state);
uint8_t Butter_Read(void);
uint8_t Butter_Read_Once();

void MSP_SPI_GPIO_Port_Init(void);
void MSP_SPI_SCK(uint8_t state);
void MSP_SPI_MOSI(uint8_t state);
uint8_t MSP_SPI_MISO(void);
void MSP_SPI_CS(uint8_t state);
void MSP_SPI_CS2(uint8_t state);
void MSP_SPI_CS3(uint8_t state);

#endif //BOARD_CONFIG_H
