#include <iostream> //标准的输入输出流头文件
#include <windows.h> //windowsAPI的函数声明和宏
#include <conio.h> //控制台输入输出头文件
#include <bitset> //std::bitset<size>(num)
// ADS headers for TwinCAT 3
#include "TcAdsDef.h" //结构体和常量的声明
#include "TcAdsAPI.h" // ADS函数的声明
#include <minwindef.h>//使用简化声明
#include "Scontrol.h"//伺服控制声明
#include <thread>//多线程声明
#include <cstdint>
#include <functional>

// void threadaxis() {
//     Sctrl Axis1("轴1",axisctrl[1],axisstate[1]);//定义对象
//
//
//     Axis1.motion_pp(200000);//设置pp模式的运动参数
//     Axis1.enable();//给电机上使能
//     Axis1.Sconfirm();//运行前确认状态
//     Axis1.Sspin();//开始旋转
//
//     Axis1.disable();//下使能
// }

int main() {
    // std::thread t1(threadaxis);
    // t1.detach();
    Sctrl Axis1("轴1",&axisctrl[1],&axisstate[1]);//定义对象

    std::thread t1(&Sctrl::transmit,axisctrl,axisstate);//开启线程
    t1.detach();




    return 0;

}