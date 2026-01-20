//
// Created by Jzy on 2025/11/15.
//

#ifndef CPPLEARN_SCONTROL_H
#define CPPLEARN_SCONTROL_H

#include <iostream> //标准的输入输出流头文件
#include <windows.h> //windowsAPI的函数声明和宏
#include <conio.h> //控制台输入输出头文件
#include <bitset> //std::bitset<size>(num)
// ADS headers for TwinCAT 3
#include "TcAdsDef.h" //结构体和常量的声明
#include "TcAdsAPI.h" // ADS函数的声明
#include <thread>//多线程声明
#include <cstdint>
#include <string>


struct doubleaxis_ctrl {
    unsigned short control;
    unsigned char mod=1;
    int32_t position;
    unsigned int velocity;
    unsigned int max_speed;
}axisctrl[2];

struct doubleaxis_state {
    unsigned short state;
}axisstate[2];


class Sctrl{
private:
    inline static long  nErr{}, nPort{};//定义端口变量
    inline static AmsAddr Addr{};
    inline static PAmsAddr pAddr = &Addr;//指针


    unsigned short control[5] = {0,6,7,15,31} ;//控制字输入值
    std::string name;
    unsigned short ctrl = 0 ;
    unsigned char mode = 1;//pp模式输入值
    int32_t pos = 0;//闲值
    unsigned int v=0 ; //速度
    unsigned int max_v = 0 ;//最大速度
    unsigned short stateW ;//状态字读取值
    unsigned int a1=0  ;//加速度
    unsigned int a2 = 0  ;//减速度
    bool condition;


public:


    static void ADS();
    static void ADSoff();
    static void transmit(doubleaxis_ctrl&,doubleaxis_state&);

    Sctrl(const std::string&,doubleaxis_ctrl&,doubleaxis_state&);
    ~Sctrl();

    void enable();
    void disable();
    void motion_pp(int);
    void Sspin();
    void Sconfirm();

};


#endif //CPPLEARN_SCONTROL_H