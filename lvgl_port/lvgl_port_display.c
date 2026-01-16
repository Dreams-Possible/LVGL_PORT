#include"lvgl_port_display.h"
//#include"screen_driver.h"

//启用LVGL显示移植
#ifdef LVGL_PORT_DISPLAY_H

//参数定义
#define LVGL_PORT_DISPLAY_HOR 320
#define LVGL_PORT_DISPLAY_VER 480

//屏幕刷新
static void flash(lv_display_t*display,const lv_area_t*area,uint8_t*color);
//LVGL移植显示初始化
uint8_t lvgl_port_display_init();

//屏幕刷新
static void flash(lv_display_t*display,const lv_area_t*area,uint8_t*color)
{
    //屏幕刷新函数
    //screen_flash(area->x1,area->y1,area->x2,area->y2,(uint16_t*)color);
    //屏幕刷新完成
    lv_display_flush_ready(display);
    return;
}

//LVGL移植显示初始化
uint8_t lvgl_port_display_init()
{
    //创建显示器
    lv_display_t*display=lv_display_create(LVGL_PORT_DISPLAY_HOR,LVGL_PORT_DISPLAY_VER);
    //设置显示刷新回调函数
    lv_display_set_flush_cb(display,flash);
    //申请缓冲帧（这里使用双缓冲）
    uint8_t*buffer_1=malloc(LVGL_PORT_DISPLAY_HOR*LVGL_PORT_DISPLAY_VER/4*sizeof(uint16_t));
    uint8_t*buffer_2=malloc(LVGL_PORT_DISPLAY_HOR*LVGL_PORT_DISPLAY_VER/4*sizeof(uint16_t));
    //检查内存是否申请成功
    if(buffer_1&&buffer_2)
    {
        //设置缓冲帧
        lv_display_set_buffers(display,buffer_1,buffer_2,LVGL_PORT_DISPLAY_HOR*LVGL_PORT_DISPLAY_VER/4*sizeof(uint16_t),LV_DISPLAY_RENDER_MODE_PARTIAL);
        return 0;
    }
    else
    {
        if(buffer_1)
        {
            free(buffer_1);
        }
        if(buffer_2)
        {
            free(buffer_2);
        }
        return 1;
    }
}

#endif//#ifdef LVGL_PORT_DISPLAY_H
