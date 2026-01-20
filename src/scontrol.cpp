//
// Created by Jzy on 2025/11/15.
//

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

//构造函数定义，参数引用并绑定到对象中
Sctrl::Sctrl(const std::string& objname,doubleaxis_ctrl* ptr1,doubleaxis_state* ptr2):
name(objname),
ctrl_ptr(ptr1),
state_ptr(ptr2){
    std::cout<<"已创建"<<name<<std::endl;
}

Sctrl::~Sctrl() {
    std::cout<<"对象"<<name<<"已销毁"<<std::endl;
}

void Sctrl::ADS() {
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);//自动获取本地地址
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    std::cout << "AdsGetLocalAddress returned " << nErr << '\n';

    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;
    std::cout << "端口已连接" << '\n';
}

void Sctrl::ADSoff() {
    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';
    std::cout << "端口已关闭" << '\n';
}


void Sctrl::enable() {
    for (int i=1 ;i < 4; i++ )
    {
        //将数值写入寄存器
        ctrl = control[i];
        Sleep(10);

        //从寄存器读取数值
        std::cout << std::bitset<16>(stateW) << '\n';
        Sleep(50);
    }
    std::cout << "已完成上使能" << '\n';
}
void Sctrl::disable() {
    // do {
    //     Sleep(500);
    //     nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW );
    //     if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    //     condition = (stateW & 1024) == 0;
    // }while(condition);
    // std::cout << "转动完成" << '\n';

    // for (int i=2 ; i>-1 ; i-- )
    // {
    //     // std::cin >> control1;
    //     nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &(control1[i]) );
    //     if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    //     // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
    //     nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW);
    //     if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    //     std::cout << std::bitset<16>(stateW) << '\n';
    //     Sleep(50);
    // }
    // std::cout << "使能结束" << '\n';
}

void Sctrl::motion_pp(int target_pos) {
    pos = target_pos;

    std::cout << std::bitset<16>(stateW) << '\n';
    Sleep(50);
    std::cout << "设置为pp模式" << '\n';
     //设置点动位置
    std::cout << std::bitset<16>(stateW) << '\n';
    Sleep(200);

    //设置加速度
    std::cout << std::bitset<16>(stateW) << '\n';
    Sleep(200);

    //设置减速度
    std::cout << std::bitset<16>(stateW) << '\n';
    Sleep(200);

    //设置速度
    std::cout << std::bitset<16>(stateW) << '\n';
    Sleep(200);

    //设置最大速度

    std::cout << std::bitset<16>(stateW) << '\n';
    Sleep(200);

    std::cout << "已完成速度及位置设定" << '\n';
}

void Sctrl::Sconfirm() {
    mode =2;
    ctrl =control[4];
}

void Sctrl::Sspin() {
    ctrl = control[4];
    std::cout << std::bitset<16>(stateW) << '\n';
    std::cout << "开始转动" << '\n';
    Sleep(2000);

    ctrl = control[3];
    std::cout << std::bitset<16>(stateW) << '\n';
}

void Sctrl::transmit(doubleaxis_ctrl* data1, doubleaxis_state* data2) {
    while (true) {
        //写入参数
        nErr = AdsSyncWriteReq(pAddr, 0xF030, 0x3E800, sizeof(doubleaxis_ctrl), &(data1));
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        //读取状态
        nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,sizeof(doubleaxis_state), &(data2) );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        // std::cout << std::bitset<16>(data2.state) << '\n';
        // std::cout << std::bitset<16>(data2.state) << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}