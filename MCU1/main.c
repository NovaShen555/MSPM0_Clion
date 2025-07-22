//
// Created by 34575 on 25-6-20.
//

#include <ti_msp_dl_config.h>
#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* * 主线程函数
 */
void Main_Thread(void *pvParameters){
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
void DL_delay(uint32_t ms) {
    while(ms--) {
        delay_cycles(CPUCLK_FREQ/1000);
    }
}


char screen_rx_buffer[50]={0};
uint16_t screen_rx_index = 0;
char k230_rx_buffer[50]={0};
uint16_t k230_rx_index = 0;

uint8_t motor_cmd[13] = {0x01,0xfd,0x00,0x01,0xf4,0xa0,0x00,0x00,0xc8,0x00,0x01,0x00,0x6b};

float angle_x = 0.0f;
float angle_y = 0.0f;

float projection_x = 0.205f;
float projection_y = -0.472f;

int obj_pos[12][2]={0};
int selected_obj = -1; // 选中的目标ID


void GenerateCmd(uint8_t motor_id, float angle) {
    uint32_t pulse = (fabsf(angle) * 51200. / 360.);
    if (angle > 0) {
        // motor_cmd[2] = 0x01;
        motor_cmd[2] = (motor_id == 2)?0x00:0x01;
    } else {
        // motor_cmd[2] = 0x00;
        motor_cmd[2] = (motor_id == 2)?0x01:0x00;
    }
    motor_cmd[6] = (pulse >> 24) & 0xff; // 高字节
    motor_cmd[7] = (pulse >> 16) & 0xff; // 次高字节
    motor_cmd[8] = (pulse >> 8) & 0xff;  // 次低字节
    motor_cmd[9] = pulse & 0xff;         // 低字节
    motor_cmd[0] = motor_id;
}

void MotorControl() {
    GenerateCmd(1, angle_x);
    for (int i=0; i<13; i++) {
        DL_UART_Main_transmitDataBlocking(MOTOR_INST, motor_cmd[i]); // 发送电机控制命令
        int t = 5;
        while(t--); // 简单延时
    }
    DL_delay(5);
    GenerateCmd(2, angle_y);
    for (int i=0; i<13; i++) {
        DL_UART_Main_transmitDataBlocking(MOTOR_INST, motor_cmd[i]); // 发送电机控制命令
        int t = 5;
        while(t--); // 简单延时
    }
}

void projection2angle(float target_x, float target_y) {
    angle_x = atan(target_x - projection_x) * 180.0f / M_PI;
    angle_y = atan(target_y - projection_y) * 180.0f / M_PI;
    if (angle_x > 180.0f) {
        angle_x -= 360.0f;
    } else if (angle_x < -180.0f) {
        angle_x += 360.0f;
    }
    if (angle_y > 180.0f) {
        angle_y -= 360.0f;
    } else if (angle_y < -180.0f) {
        angle_y += 360.0f;
    }
    MotorControl();
}

void track_id() {
    if (selected_obj < 0 || selected_obj >= 12) {
        return; // 无效ID
    }
    if (obj_pos[selected_obj][0] == 0 || obj_pos[selected_obj][1] == 0) {
        return; // 目标未更新
    }
    float target_x = obj_pos[selected_obj][0] / 10000.0f;
    float target_y = obj_pos[selected_obj][1] / 10000.0f;
    // if (target_x < 0 || target_x > 1 || target_y < 0 || target_y > 1) {
    //     return; // 无效坐标
    // }
    projection2angle(target_x, target_y);
    MotorControl();
}

int main() {
    SYSCFG_DL_init();
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(SCREEN_INST_INT_IRQN);
    NVIC_EnableIRQ(K230_INST_INT_IRQN);
    xTaskCreate(Main_Thread, "Main_Thread", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    vTaskStartScheduler(); // 启动调度器
    MotorControl();
    // while(1){
    // }
    return 0;
}

void WriteSCREEN(char* msg) {
    for (int i=0; i<strlen(msg); i++) {
        DL_UART_Main_transmitDataBlocking(SCREEN_INST, msg[i]); // 发送电机控制命令
        int t = 5;
        while(t--); // 简单延时
    }
    const char end[3] = {0xff, 0xff, 0xff};
    for (int i=0; i<3; i++) {
        DL_UART_Main_transmitDataBlocking(SCREEN_INST, end[i]); // 发送结束符
        int t = 5;
        while(t--); // 简单延时
    }
}

void SCREEN_Handler() {
    char *token[4];
    int   argc = 0;

    /* 用空格分隔 */
    char *pch = strtok(screen_rx_buffer, " ");
    while (pch && argc < 4) {
        token[argc++] = pch;
        pch = strtok(NULL, " ");
    }

    if (argc == 0)            /* 空行，继续读 */
        return;

    const char *cmd = token[0];       /* 第 0 个就是命令 */
    if (strcmp(cmd, "move") == 0) {
        int direction = atoi(token[1]);
        float speed = atoi(token[2])/2.;
        if (direction == -1 && speed) {
            angle_x = 0.0f;
            angle_y = 0.0f;
        }
        if (direction == 0) {
            angle_y += speed;
        }
        else if (direction == 1) {
            angle_x += speed;
        }
        else if (direction == 2) {
            angle_y -= speed;
        }
        else if (direction == 3) {
            angle_x -= speed;
        }
        else if (direction == 4) {
            angle_x = 0.0f;
            angle_y = 0.0f;
        }
        MotorControl();
    }
    else if (strcmp(cmd, "cali") == 0) {
        int point = atoi(token[1]);
        if (point == 0) {
            projection_y = tanf((-angle_y) * M_PI / 180.0f);
            // projection_x = tanf((-angle_x) * M_PI / 180.0f) / cosf(angle_y * M_PI / 180.0f);
            projection_x = tanf((-angle_x) * M_PI / 180.0f);
        }
        else if (point == 1) {
            projection_y = tanf(-angle_y * M_PI / 180.0f);
            // projection_x = 0.5f - tanf(angle_x * M_PI / 180.0f) / cosf(angle_y * M_PI / 180.0f);
            projection_x = 0.5f - tanf(angle_x * M_PI / 180.0f);
        }
        else if (point == 2) {
            projection_y = tanf(-angle_y * M_PI / 180.0f);
            // projection_x = tanf((-angle_x) * M_PI / 180.0f) / cosf(angle_y * M_PI / 180.0f) - 0.5f;
            projection_x = tanf((-angle_x) * M_PI / 180.0f) - 0.5f;
        }
        else if (point == 3) {
            projection_x = tanf((-angle_x) * M_PI / 180.0f);
            // projection_y = 0.5f - tanf(angle_y * M_PI / 180.0f) / cosf(angle_x * M_PI / 180.0f);
            projection_y = 0.5f - tanf(angle_y * M_PI / 180.0f);
        }
        else if (point == 4) {
            projection_x = tanf((-angle_x) * M_PI / 180.0f);
            projection_y = tanf((-angle_y) * M_PI / 180.0f) - 0.5f;
        }
        char msg[50];
        sprintf(msg, "x0.val=%d", (int)(projection_x * 10000));
        WriteSCREEN(msg);
        sprintf(msg, "y0.val=%d", (int)(projection_y * 10000));
        WriteSCREEN(msg);
    }
    else if (strcmp(cmd, "aim") == 0) {
        float aim_x = atoi(token[1])/240.;
        float aim_y = atoi(token[2])/240.;
        projection2angle(aim_x, aim_y);
    }
    else if (strcmp(cmd, "check") == 0) {
        int direction = atoi(token[1]);
        int id = atoi(token[2]);
        if (direction == 1) {
            id ++;
            if (id >= 12) {
                id = 0; // 循环选择
            }
        }
        else if (direction == 0) {
            id --;
            if (id < 0) {
                id = 11; // 循环选择
            }
        }
        char msg[20];
        sprintf(msg, "id.txt=\"%d\"", id);
        WriteSCREEN(msg);
        sprintf(msg, "x.val=%d", obj_pos[id][0]);
        WriteSCREEN(msg);
        sprintf(msg, "y.val=%d", obj_pos[id][1]);
        WriteSCREEN(msg);
    }
    else if (strcmp(cmd, "track") == 0) {
        int id = atoi(token[1]);
        if (id < 0 || id >= 12) {
            return; // 无效ID
        }
        selected_obj = id; // 更新选中的目标ID
        track_id(); // 跟踪选中的目标
    }
    else if (strcmp(cmd, "refresh") == 0) {
        int id = atoi(token[1]);
        if (id < 0 || id >= 12) {
            return; // 无效ID
        }
        char msg[20];
        sprintf(msg, "id.txt=\"%d\"", id);
        WriteSCREEN(msg);
        sprintf(msg, "x.val=%d", obj_pos[id][0]);
        WriteSCREEN(msg);
        sprintf(msg, "y.val=%d", obj_pos[id][1]);
        WriteSCREEN(msg);
    }
}

/*调试收发*/
void SCREEN_INST_IRQHandler(void) {
    switch (DL_UART_Main_getPendingInterrupt(SCREEN_INST)) {
        case DL_UART_MAIN_IIDX_RX:
        {
            uint8_t data = DL_UART_Main_receiveData(SCREEN_INST);
            screen_rx_buffer[screen_rx_index++] = data;
            //DL_UART_Main_transmitData(UART_0_INST, data); // 回显接收到的数据
            if (screen_rx_buffer[screen_rx_index-1] == '\n') {
                screen_rx_buffer[screen_rx_index] = '\0'; // 结束字符串
                SCREEN_Handler();
                memset(screen_rx_buffer, 0, sizeof(screen_rx_buffer));
                screen_rx_index = 0; // 重置索引
            }
            break;
        }
        default:
        {
            break;
        }
    }
}


void K230_Handler() {
    char *token[4];
    int   argc = 0;

    /* 用空格分隔 */
    char *pch = strtok(k230_rx_buffer, " ");
    while (pch && argc < 4) {
        token[argc++] = pch;
        pch = strtok(NULL, " ");
    }

    if (argc == 0)            /* 空行，继续读 */
        return;

    if (strcmp(token[0], "track") == 0) {
        float target_x = atoi(token[1])/10000.;
        float target_y = atoi(token[2])/10000.;
        projection2angle(target_x, target_y);
    }
    else if (strcmp(token[0], "update") == 0) {
        int id = atoi(token[1]);
        int x = atoi(token[2]);
        int y = atoi(token[3]);
        if (id < 0 || id >= 12) {
            return; // 无效ID
        }
        obj_pos[id][0] = x; // 更新x坐标
        obj_pos[id][1] = y; // 更新y坐标
        if (selected_obj == id) {
            // 如果当前选中目标是更新的目标，立即跟踪
            track_id();
        }
    }
}

void K230_INST_IRQHandler(void) {
    switch (DL_UART_Main_getPendingInterrupt(K230_INST)) {
        case DL_UART_MAIN_IIDX_RX:
        {
            k230_rx_buffer[k230_rx_index++] = DL_UART_Main_receiveData(K230_INST);
            //DL_UART_Main_transmitData(UART_0_INST, data); // 回显接收到的数据
            if (k230_rx_buffer[k230_rx_index-1] == '\n') {
                k230_rx_buffer[k230_rx_index] = '\0'; // 结束字符串
                K230_Handler();
                memset(k230_rx_buffer, 0, sizeof(k230_rx_buffer));
                k230_rx_index = 0; // 重置索引
            }
            break;
        }
        default:
        {
            break;
        }
    }
}


/*定时控制*/
void TIMER_0_INST_IRQHandler(void) {
    switch (DL_TimerA_getPendingInterrupt(TIMER_0_INST)) {
    case DL_TIMERA_IIDX_ZERO:

        break;
    default:
        break;
    }
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    /* 栈溢出时的处理代码 */
    /* 例如，打印错误信息并重置系统 */

    /* 参数:
     * xTask - 发生栈溢出的任务句柄
     * pcTaskName - 发生栈溢出的任务名称
     */

    /* 通常在这里添加一些错误处理和系统恢复的代码 */
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(500)); // 每500毫秒切换一次LED状态
        /* 可以在此处添加错误处理代码，如闪烁LED或输出调试信息 */
    }
}

/* 在全局范围内定义存储空间 */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

/* 实现所需的函数 */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                  StackType_t **ppxIdleTaskStackBuffer,
                                  uint32_t *pulIdleTaskStackSize)
{
    /* 传递静态分配的空闲任务数据结构的地址 */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* 传递静态分配的空闲任务堆栈的地址 */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* 传递堆栈大小 */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}


/* 为定时器任务定义静态内存 */
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                   StackType_t **ppxTimerTaskStackBuffer,
                                   uint32_t *pulTimerTaskStackSize)
{
    /* 传递静态分配的定时器任务数据结构的地址 */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* 传递静态分配的定时器任务堆栈的地址 */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* 传递堆栈大小 */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}