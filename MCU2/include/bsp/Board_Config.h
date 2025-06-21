//
// Created by 34575 on 25-6-21.
//

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <../../ti_msp_dl_config.h>
#include <stdio.h>
#include <stdarg.h>
int Uprintf(UART_Regs * uart,const char *fmt, ...);

void LED_ON(void);
void LED_OFF(void);
void LED_Toggle(void);
void LED_Set(bool state);
uint8_t Butter_Read(void);
uint8_t Butter_Read_Once();

#endif //BOARD_CONFIG_H
