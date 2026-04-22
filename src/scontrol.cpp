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
#include "axis_config.h"

//构造函数定义，参数引用并绑定到对象中
Sctrl::Sctrl(){
    ADS();
    std::cout<<"module builded"<<std::endl;
    std::thread t(&Sctrl::transmit,this);
    t.detach();
    std::cout<<"thread created"<<std::endl;
}

Sctrl::~Sctrl() {
    ADSoff();
    std::cout<<"target distroyed"<<std::endl;
}

void Sctrl::ADS() {
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);//自动获取本地地址
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    std::cout << "AdsGetLocalAddress returned " << nErr << '\n';

    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;
    std::cout << "port connected" << '\n';

}

void Sctrl::ADSoff() {
    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';
    std::cout << "port disconnected" << '\n';
}

void Sctrl::setsingleaxis(int axis, unsigned short Control, unsigned char Mode, int32_t Position, unsigned int Velocity, unsigned int Max_speed) {
    axis_command[axis].control = Control;
    axis_command[axis].mod = Mode;
    axis_command[axis].position = Position;
    axis_command[axis].velocity = Velocity;
    axis_command[axis].max_speed = Max_speed;
}

void Sctrl::enable(int AXIS) {
    for (int i=0 ;i < 3; i++ )
    {

        setsingleaxis(AXIS,controlWORDbit[i],PPmod,0,0,0);

        //从寄存器读取数值
        std::cout << std::bitset<16>(axis_state[AXIS].state) << '\n';
        Sleep(50);
    }
    std::cout << "Operation Enabled" << '\n';
}
void Sctrl::disable(int AXIS) {

    setsingleaxis(AXIS,DISABLED,PPmod,0,0,0);
    std::cout << "Operation disabled" << '\n';
}

void Sctrl::motion_pp(int AXIS,int target_pos,int profile_velocity) {
    setsingleaxis(AXIS,ENABLED,PPmod,target_pos,profile_velocity,Maxvelocity);
    Sleep(100);
    std::cout << "move starting" << '\n';
    setsingleaxis(AXIS,MOVESTART,PPmod,target_pos,profile_velocity,Maxvelocity);
    Sleep(100);
    setsingleaxis(AXIS,ENABLED,PPmod,target_pos,profile_velocity,Maxvelocity);
}


void Sctrl::transmit() {
    while (true) {
        //写入参数
        nErr = AdsSyncWriteReq(pAddr, indexgroup1, indexoffset1, sizeof(axis_command), &(axis_command));
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        //读取状态
        nErr = AdsSyncReadReq(pAddr,indexgroup2,indexoffset2,sizeof(axis_state), &(axis_state) );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        // std::cout << std::bitset<16>(data2.state) << '\n';
        // std::cout << std::bitset<16>(data2.state) << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}