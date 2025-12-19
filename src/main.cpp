#include "stdafx.h"

void threadaxis() {
    Sctrl Axis1;//定义对象


    Axis1.motion_pp(200000);//设置pp模式的运动参数
    Axis1.enable();//给电机上使能
    Axis1.Sconfirm();//运行前确认状态
    Axis1.Sspin();//开始旋转

    Axis1.disable();//下使能
}

int main() {

    std::thread t1(&threadaxis);



    return 0;

}