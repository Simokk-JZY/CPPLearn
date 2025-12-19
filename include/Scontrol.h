//
// Created by Jzy on 2025/11/15.
//

#ifndef CPPLEARN_SCONTROL_H
#define CPPLEARN_SCONTROL_H

#include "stdafx.h"


class Sctrl{
private:
    long  nErr, nPort;//定义端口变量
    AmsAddr Addr;
    PAmsAddr pAddr = &Addr;//指针
    unsigned short stateW1;//状态字读取值
    unsigned char moo ;//运动模式状态
    unsigned short control1[4] = {0,6,7,15} , ctrl2 = 31 ;//控制字输入值
    unsigned char mode1 = 1;//pp模式输入值
    int pos1 = 0;//闲值
    UINT v1=10000 , a1=10000 , a2 = 10000 , max_vm = 50000 ;//加速度，速度值
    bool condition;


public:
    Sctrl();
    ~Sctrl();

    void enable();
    void disable();

    void motion_pp(int);
    void Sspin();
    void Sconfirm();
};


#endif //CPPLEARN_SCONTROL_H