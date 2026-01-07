//
// Created by Jzy on 2025/11/15.
//

#include "stdafx.h"

Sctrl::Sctrl() {




    //电机上使能
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

    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E806,0x1, &mode1 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(50);
    // std::cout << "默认动作模式为pp模式" << '\n';
}

Sctrl::~Sctrl() {

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
    do {
        Sleep(500);
        nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        condition = (stateW1 & 1024) == 0;
    }while(condition);
    std::cout << "转动完成" << '\n';

    for (int i=2 ; i>-1 ; i-- )
    {
        // std::cin >> control1;
        nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &(control1[i]) );
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
        nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::cout << std::bitset<16>(stateW1) << '\n';
        Sleep(50);
    }
    std::cout << "使能结束" << '\n';
}

void Sctrl::motion_pp(int target_pos) {
    pos1 = target_pos;
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E806,0x1, &mode1 );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(50);
    std::cout << "设置为pp模式" << '\n';
     //设置点动位置
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E808,0x4, &pos1 );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);

    //设置加速度
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E82C,0x4, &a1 );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);

    //设置减速度
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E83C,0x4, &a2 );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);

    //设置速度
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E81C,0x4, &v1 );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);

    //设置最大速度
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E85C,0x4, &max_vm );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E84C,0x4, &max_vm );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);

    std::cout << "已完成速度及位置设定" << '\n';
}

void Sctrl::Sconfirm() {
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &control1[3] );//写入15
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);
}

void Sctrl::Sspin() {
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &ctrl2 );//写入31
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    std::cout << "开始转动" << '\n';
    Sleep(2000);

    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &(control1[3]) );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
}

void Sctrl::transmit() {
    while (true) {


        //写入参数
        nErr = AdsSyncWriteReq(pAddr,0xF030,c_offset,0x2, &ctrl );//写入控制字
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        nErr = AdsSyncWriteReq(pAddr,0xF030,m_offset,0x1, &mode );//写入运动模式
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        nErr = AdsSyncWriteReq(pAddr,0xF030,mv_offset,0x4, &max_v );//写入最大速度
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        nErr = AdsSyncWriteReq(pAddr,0xF030,v_offset,0x4, &v );//写入速度
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        nErr = AdsSyncWriteReq(pAddr,0xF030,p_offset,0x4, &pos );//写入目标位置
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));


        //读取状态
        nErr = AdsSyncReadReq(pAddr,0xF020,s_offset,0x2, &stateW );//读取状态字
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::cout << std::bitset<16>(stateW) << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}