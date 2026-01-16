#include"lvgl_port_runtime.h"
#include"lvgl_port_display.h"
#include"lvgl_port_touch.h"
// #include"freertos/FreeRTOS.h"
// #include"freertos/task.h"
// #include"sys_log.h"

//启用LVGL触摸移植
#ifdef LVGL_PORT_RUNTIME_H

//参数定义
#define LVGL_PORT_RUNTIME_TIMEGAP 10
#define LVGL_PORT_RUNTIME_LOG SYS_LOG

//LVGL移植运行时初始化
void lvgl_port_runtime_init();
//LVGL运行时
static void lvgl_runtime(void*arg);

//初始化LVGL移植运行时
void lvgl_port_runtime_init()
{
    //LVGL初始化
    lv_init();
    //LVGL移植显示初始化
    lvgl_port_display_init();
    //LVGL移植触摸初始化
    lvgl_port_touch_init();
    //创建系统初始化任务
    // xTaskCreate(lvgl_runtime,"lvgl_runtime",1024*4,NULL,8,NULL);
}

//LVGL运行时
static void lvgl_runtime(void*arg)
{
    // TickType_t pxPreviousWakeTime = xTaskGetTickCount();
    // const TickType_t xTimeIncrement = pdMS_TO_TICKS(LVGL_PORT_RUNTIME_TIMEGAP);
    while(1)
    {
        //LVGL运行
        lv_task_handler();
        //提供时基
        lv_tick_inc(LVGL_PORT_RUNTIME_TIMEGAP);
        //进入休眠
        // if(xTaskDelayUntil(&pxPreviousWakeTime, xTimeIncrement) != pdTRUE)
        // {
        //     LVGL_PORT_RUNTIME_LOG("lvgl runtime can not meet target timegap");
        // }
    }
}

#endif//#ifdef LVGL_PORT_TOUCH_H
