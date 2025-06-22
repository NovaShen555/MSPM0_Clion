//
// Created by 34575 on 25-6-20.
//

#include <ti_msp_dl_config.h>
#include <Board_Config.h>
#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <OLED.h>
/* * 主线程函数
 * 该函数会每500毫秒切换一次LED的状态
 */
void Main_Thread(void *pvParameters){
    OLED_Init(); // 初始化OLED显示屏
    uint8_t a;
    for (;;) {
        a++;
        // OLED_Printf(0, 0, OLED_8X16, "Hello, FreeRTOS!");
        OLED_Printf(0, 16, OLED_8X16, "Now time is %d", a);
        OLED_Update(); // 更新OLED显示屏内容
        // LED_Toggle();
        vTaskDelay(pdMS_TO_TICKS(500)); // 每500毫秒切换一次LED状态
    }
}


int main() {
    SYSCFG_DL_init();
    // NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    uint8_t a;
    OLED_Init();
    for (;;) {
        a++;
        // OLED_Printf(0, 0, OLED_8X16, "Hello, FreeRTOS!");
        OLED_Printf(0, 16, OLED_8X16, "Now time is %d", a);
        OLED_Update(); // 更新OLED显示屏内容
        // LED_Toggle();
    }
    // xTaskCreate(Main_Thread, "Main_Thread", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    // vTaskStartScheduler(); // 启动调度器
    return 0;
}


/*调试收发*/
void UART_0_INST_IRQHandler(void) {
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
    case DL_UART_MAIN_IIDX_RX:

        break;
    default:
        break;
    }
}

/*定时控制*/
void TIMER_0_INST_IRQHandler(void) {
    switch (DL_TimerA_getPendingInterrupt(TIMER_0_INST)) {
    case DL_TIMERA_IIDX_ZERO:
        printf("This is MCU 1,Well you can see the output is different between these MCUs\n");
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
        LED_Toggle();
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