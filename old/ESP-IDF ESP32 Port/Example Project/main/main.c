#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

#include"lvgl/lvgl.h"
#include"lvgl_port_display.h"
#include"lvgl_port_touch.h"

void app_main(void)
{
    //屏幕初始化
    //screen_init();

    //触摸设备初始化
    //touch_init();

    //LVGL初始化
    lv_init();

    //LVGL移植显示初始化
    lvgl_port_display_init();

    //LVGL移植触摸初始化
    lvgl_port_touch_init();

    //LVGL UI初始化
    //ui_init();

    //LVGL运行
    while(1)
    {
        //提供时基
        lv_tick_inc(10);
        //LVGL运行
        lv_task_handler();
        //让出资源
        vTaskDelay(pdMS_TO_TICKS(10));
    }

}
