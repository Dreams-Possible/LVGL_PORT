#include"lvgl_port_touch.h"
//启用lvgl_port_touch
#ifdef LVGL_PORT_TOUCH_H

//读取触摸数据
static void read(lv_indev_t*indev_drv,lv_indev_data_t*data);
//LVGL移植触摸初始化
void lvgl_port_touch_init();

//读取触摸数据
static void read(lv_indev_t*indev_drv,lv_indev_data_t*data)
{
    // int16_t x=0;
    // int16_t y=0;
    // if(any_touch())
    // {
    //     touch_read(&x,&y);
    //     data->state=LV_INDEV_STATE_PRESSED;
    //     data->point.x=x;
    //     data->point.y=y;
    // }
    // else
    // {
    //     data->state=LV_INDEV_STATE_RELEASED;
    // }
    return;
}

//LVGL移植触摸初始化
void lvgl_port_touch_init()
{
    //创建输入设备
    lv_indev_t*indev_touchpad=lv_indev_create();
    //设置输入设备类型
    lv_indev_set_type(indev_touchpad,LV_INDEV_TYPE_POINTER);
    //设置读取输入设备回调函数
    lv_indev_set_read_cb(indev_touchpad,read);
    return;
}

#endif//#ifdef LVGL_PORT_TOUCH_H
