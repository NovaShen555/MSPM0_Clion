//
// Created by 34575 on 25-6-8.
//
#include <stdio.h>
#include <shell.h>
#include <Serial.h>
#include <string.h>
#include "control.h"


extern Cmd_PointerTypeDef Cmd;



void _ls(int argc, void *argv[]) {

}


void _pids(int argc, void *argv[]) {

}

void _pidu(int argc, void *argv[]) {

}

void _die(int argc, void *argv[]) {

}

void _test(int argc, void *argv[]) {

}

void _reset(int argc, void *argv[]) {
    NVIC_SystemReset(); // 重启系统
}


EnvVar MyEnvVar[20] = {

    {
        .name = NULL,
        .callback = NULL
    }
};



void Sys_Cmd_Init() {
    // 初始化系统命令
    Cmd.ls = _ls;
    Cmd.reset = _reset;
    Cmd.test = _test;
}
