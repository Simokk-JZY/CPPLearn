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
    unsigned short control1[4] = {0,6,7,15} , ctrl2 = 31 ;//控制字输入值
    unsigned char mode1 = 1;//pp模式输入值
    int pos1 = 20000, pos2 = 0, pos3 = 30000;//闲值
    UINT v1=200 , a1=10000 , a2 = 10000;//加速度，速度值

public:
    void nportopen();
    void nportclose();
    void Senable();
    void Sdisable();
    void modeset();
    void pp_parameterS();
    void Sspin();
    void Sconfirm();
};

// inline int kbinput = 1;
// void st0p();

#endif //CPPLEARN_SCONTROL_H