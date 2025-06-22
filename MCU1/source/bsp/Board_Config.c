//
// Created by 34575 on 25-6-21.
//
#include <Board_Config.h>
#include <stdint.h>


void MSP_Delay_us(uint32_t nus) {
    delay_cycles(nus * (CPUCLK_FREQ / 1000000));
}

void MSP_Delay_ms(uint32_t nms) {
    for(uint32_t i = 0; i < nms; i++) {
        MSP_Delay_us(1000); // 每毫秒延时1000微秒
    }
}

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

/*********************************硬件IIC控制函数 ********************************/

//发送一个字节
//mode:数据/命令标志 0,表示命令;1,表示数据;
void I2C_WR_Byte(uint16_t Addre,uint8_t *data,uint8_t len)
{

    DL_I2C_fillControllerTXFIFO(I2C_OLED_INST, data, len);
    DL_I2C_clearInterruptStatus(I2C_OLED_INST, DL_I2C_INTERRUPT_CONTROLLER_TX_DONE);
    while (!(DL_I2C_getControllerStatus(I2C_OLED_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_startControllerTransfer(I2C_OLED_INST, Addre, DL_I2C_CONTROLLER_DIRECTION_TX, 2);

    while (!DL_I2C_getRawInterruptStatus(I2C_OLED_INST, DL_I2C_INTERRUPT_CONTROLLER_TX_DONE));
}

/**************************************硬件SPI控制函数******************************** */

// void SPI_WR_Byte(uint8_t dat,uint8_t cmd)
// {
//     while (DL_SPI_isBusy(SPI_OLED_INST));

//     if(cmd)
//         DL_SPI_setControllerCommandDataModeConfig(SPI_OLED_INST, DL_SPI_CD_MODE_DATA);
//     else
//         DL_SPI_setControllerCommandDataModeConfig(SPI_OLED_INST, DL_SPI_CD_MODE_COMMAND);

//     DL_SPI_transmitData8(SPI_OLED_INST, dat);
// } 

/********************************软件SPI接口函数******************************* */
SSAS spi_Dev;  // 定义SPI设备指针

void MSP_SPI_GPIO_Port_Init(void) {
    
}

void MSP_SPI_SCK(uint8_t state){
    if (state) {
        DL_GPIO_setPins(SOFT_SPI_SCK_PORT, SOFT_SPI_SCK_PIN);
    } else {
        DL_GPIO_clearPins(SOFT_SPI_SCK_PORT, SOFT_SPI_SCK_PIN);
    }
}

void MSP_SPI_MOSI(uint8_t state){
    if (state) {
        DL_GPIO_setPins(SOFT_SPI_MOSI_PORT, SOFT_SPI_MOSI_PIN);
    } else {
        DL_GPIO_clearPins(SOFT_SPI_MOSI_PORT, SOFT_SPI_MOSI_PIN);
    }
}

uint8_t MSP_SPI_MISO(void) {
    return DL_GPIO_readPins(SOFT_SPI_MISO_PORT, SOFT_SPI_MISO_PIN);
}

void MSP_SPI_CS(uint8_t state){
    if (state) {
        DL_GPIO_setPins(SOFT_SPI_CS_PORT, SOFT_SPI_CS_PIN);
    } else {
        DL_GPIO_clearPins(SOFT_SPI_CS_PORT, SOFT_SPI_CS_PIN);
    }
}

void MSP_SPI_CS2(uint8_t state){
    if (state) {
        DL_GPIO_setPins(SOFT_SPI_CS2_PORT, SOFT_SPI_CS2_PIN);
    } else {
        DL_GPIO_clearPins(SOFT_SPI_CS2_PORT, SOFT_SPI_CS2_PIN);
    }
}

void MSP_SPI_CS3(uint8_t state){
    if (state) {
        DL_GPIO_setPins(SOFT_SPI_CS3_PORT, SOFT_SPI_CS3_PIN);
    } else {
        DL_GPIO_clearPins(SOFT_SPI_CS3_PORT, SOFT_SPI_CS3_PIN);
    }
}

