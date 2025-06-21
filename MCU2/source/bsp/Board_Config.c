//
// Created by 34575 on 25-6-21.
//
#include <Board_Config.h>

/*******************串口重新向***********************/
int Uprintf(UART_Regs * uart,const char *fmt, ...) {
    int j;
    char buf[256];

    va_list arg;
    va_start(arg, fmt);
    j = vsprintf(buf, fmt, arg);
    va_end(arg);

    for (int i = 0; i < j; i++) {
        while (DL_UART_isBusy(uart)); // 等待发送缓冲区空闲
        uart->TXDATA = buf[i]; // 发送数据
    }
    return j;
}

int _write(int file, char *ptr, int len){
    for (int i = 0; i < len; i++) {
        while (DL_UART_isBusy(UART0)); // 等待发送缓冲区空闲
        UART0->TXDATA = ptr[i]; // 发送数据
    }
    return len;
}

/*******************LED控制函数********************/
void LED_ON() {
    DL_GPIO_setPins(LED_PORT, LED_PIN_14_PIN);
}

void LED_OFF() {
    DL_GPIO_readPins(LED_PORT, LED_PIN_14_PIN);
}

void LED_Toggle() {
    DL_GPIO_togglePins(LED_PORT, LED_PIN_14_PIN);
}

void LED_Set(bool state) {
    if (state) {
        LED_ON();
    } else {
        LED_OFF();
    }
}

/*******************Butter开关控制函数********************/

/* * 读取Butter开关状态
 * 返回值：1表示按下，0表示未按下
 */
uint8_t Butter_Read() {
    static uint8_t lock = 0;
    uint8_t state = DL_GPIO_readPins(Butter_PORT, Butter_S2_PIN) ? 0 : 1; // 返回开关状态
    if (!state) {
        if (lock == 1) {
            lock = 0; // 如果开关按下且已经锁定，解锁状态
            return 0; // 如果开关按下且已经松开返回1
        }
        lock = 0; // 如果开关未按下，解锁
        return 0;
    } else {
        if (!lock) {
            lock = 1; // 如果开关按下且未锁定，锁定状态
            return 1;
        }
        return 0; // 如果开关未按下且已经锁定，返回0
    }

}

/* * 读取Butter开关状态（一次性读取）
 * 返回值：1表示按下，0表示未按下
 */
uint8_t Butter_Read_Once() {
    return DL_GPIO_readPins(Butter_PORT, Butter_S2_PIN) ? 0 : 1; // 返回开关状态
}

/*******************定时器PWM控制函数********************/
inline void MSP_Motor_Set(GPTIMER_Regs *TIMERx,uint8_t Motor,uint32_t Load){
    DL_TimerA_setCaptureCompareValue(TIMERx, Load, Motor);
}

inline uint32_t MSP_Motor_Get(GPTIMER_Regs *TIMERx,uint8_t Motor) {
    return DL_TimerA_getCaptureCompareValue(TIMERx, Motor);
}

void Motor_Set(uint8_t Motor,uint32_t Load){
    MSP_Motor_Set(Motor_INST,Motor, Load);
}

uint32_t Motor_Get(uint8_t Motor) {
    return MSP_Motor_Get(Motor_INST, Motor);
}