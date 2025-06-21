//
// Created by 34575 on 25-6-6.
//

#include "control.h"
#include "tb6612.h"
using namespace Control;





/**
 * @brief 小车速度环控制函数
 * @param target 速度环目标值
 */
void Speed_Control::control(float target) {

}

void Turn_Control::control(float target,float current) {

}
/**
 * @brief 小车直立环控制函数
 * @param target 目标角度,传入速度环输入
 * @param current 角度当前值
 */
void Upright_Control::control(float target,float current) {


}
