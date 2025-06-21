//
// Created by 34575 on 25-6-8.
//

#ifndef TB6612_H
#define TB6612_H
#include <ti_msp_dl_config.h>


//PWM接口
//#define PWMA 22
//#define PWMB 20

//方向使能接口 use the GPIOA
#define TB6612_Port TB6612_PORT
#define AIN_2 TB6612_AIN1_PIN
#define AIN_1 TB6612_AIN2_PIN
#define BIN_1 TB6612_BIN1_PIN
#define BIN_2 TB6612_BIN2_PIN

//PWM二次接口
//#define MotorLeft PWMA
//#define MotorRight PWMB

//方向控制
#define RightForward    do{DL_GPIO_setPins(TB6612_Port,AIN_1); DL_GPIO_clearPins(TB6612_Port,AIN_2);}while(0)
#define RightBackward   do{DL_GPIO_clearPins(TB6612_Port,AIN_1); DL_GPIO_setPins(TB6612_Port,AIN_2);}while(0)
#define LeftForward     do{DL_GPIO_clearPins(TB6612_Port,BIN_1); DL_GPIO_setPins(TB6612_Port,BIN_2);}while(0)
#define LeftBackward    do{DL_GPIO_setPins(TB6612_Port,BIN_1); DL_GPIO_clearPins(TB6612_Port,BIN_2);}while(0)
#define AllForward      do{LeftForward;RightForward;}while(0)
#define AllBackward     do{LeftBackward;RightBackward;}while(0)
#define AllStop         do{DL_GPIO_clearPins(TB6612_Port,AIN_1); DL_GPIO_clearPins(TB6612_Port,AIN_2);DL_GPIO_clearPins(TB6612_Port,BIN_1);DL_GPIO_clearPins(TB6612_Port,BIN_2);}while(0)

#endif //TB6612_H
