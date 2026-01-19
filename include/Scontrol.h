//
// Created by Jzy on 2025/11/15.
//

#ifndef CPPLEARN_SCONTROL_H
#define CPPLEARN_SCONTROL_H

#include "stdafx.h"

struct offsets {
    unsigned int c ;
    unsigned int m ;
    unsigned int mv ;
    unsigned int v ;
    unsigned int p ;
    unsigned int s ;
};

class Sctrl{
private:
    inline static long  nErr{}, nPort{};//定义端口变量
    inline static AmsAddr Addr{};
    inline static PAmsAddr pAddr = &Addr;//指针



    unsigned int c_offset ;
    unsigned int m_offset ;
    unsigned int mv_offset ;
    unsigned int v_offset ;
    unsigned int p_offset ;
    unsigned int s_offset ;



    unsigned short stateW ;//状态字读取值
    // unsigned char moo ;//运动模式状态
    unsigned short control[5] = {0,6,7,15,31} ;//控制字输入值
    unsigned short ctrl = 0 ;
    unsigned char mode = 1;//pp模式输入值
    int pos = 0;//闲值
    UINT v=0 , a1=0 , a2 = 0 , max_v = 0 ;//加速度，速度值
    bool condition;


public:


    static void ADS();
    static void ADSoff();

    Sctrl(const );
    Sctrl();

    ~Sctrl();

    void enable();
    void disable();

    void motion_pp(int);
    void Sspin();
    void Sconfirm();
    void transmit();
};


#endif //CPPLEARN_SCONTROL_H