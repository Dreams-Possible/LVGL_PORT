#include"lvgl_port_runtime.h"
#include"lvgl_port_display.h"
#include"lvgl_port_touch.h"
// #include"freertos/FreeRTOS.h"
// #include"freertos/task.h"
// #include<stdio.h>

//启用LVGL触摸移植
#ifdef LVGL_PORT_RUNTIME_H

//参数定义
#define LVGL_PORT_RUNTIME_TIMEGAP 5
#define LVGL_PORT_RUNTIME_LOG printf

//初始化LVGL移植运行时
uint8_t lvgl_port_runtime_init();
//LVGL运行时时基
static void lvgl_runtime_ticker(void*arg);
//LVGL运行时
static void lvgl_runtime(void*arg);

//LVGL移植运行时初始化
uint8_t lvgl_port_runtime_init()
{
    // //LVGL初始化（LVGL是非线程安全的，请在外部完成全部初始化以及界面创建，此处仅为示例，请勿取消注释）
    // lv_init();
    // //LVGL移植显示初始化
    // lvgl_port_display_init();
    // //LVGL移植触摸初始化
    // lvgl_port_touch_init();
    // //UI界面初始化
    // ui_init();

    //创建系统初始化任务
    // TaskHandle_t pxCreatedTask = NULL;
    // if(xTaskCreate(lvgl_runtime_ticker,"lvgl_runtime_ticker",1024*4,NULL,4,&pxCreatedTask)!=pdPASS)
    // {
    //     return 1;
    // }
    // if(xTaskCreate(lvgl_runtime,"lvgl_runtime",1024*16,NULL,6,NULL)!=pdPASS)
    // {
    //     vTaskDelete(pxCreatedTask);
    //     return 1;
    // }
    return 0;
}

//LVGL运行时时基（在高优先级任务中处理时基，以避免运行时未按预期运行的阻塞而导致时基失准）
static void lvgl_runtime_ticker(void*arg)
{
    // TickType_t pxPreviousWakeTime = xTaskGetTickCount();
    // const TickType_t xTimeIncrement = pdMS_TO_TICKS(LVGL_PORT_RUNTIME_TIMEGAP);
    while(1)
    {
        //提供时基
        lv_tick_inc(LVGL_PORT_RUNTIME_TIMEGAP);
        // //进入休眠
        // if(xTaskDelayUntil(&pxPreviousWakeTime, xTimeIncrement) != pdTRUE)
        // {
        //     LVGL_PORT_RUNTIME_LOG("lvgl runtime ticker can not meet target timegap");
        // }
    }
}

//LVGL运行时
static void lvgl_runtime(void*arg)
{
    TickType_t pxPreviousWakeTime = xTaskGetTickCount();
    const TickType_t xTimeIncrement = pdMS_TO_TICKS(LVGL_PORT_RUNTIME_TIMEGAP);
    while(1)
    {
        //LVGL运行
        lv_task_handler();
        // //进入休眠
        // if(xTaskDelayUntil(&pxPreviousWakeTime, xTimeIncrement) != pdTRUE)
        // {
        //     LVGL_PORT_RUNTIME_LOG("lvgl runtime can not meet target timegap");
        // }
    }
}

#endif//#ifdef LVGL_PORT_TOUCH_H
