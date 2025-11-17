//
// Created by Jzy on 2025/11/15.
//

#include "stdafx.h"

void Sctrl::nportopen() {
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    std::cout << "AdsGetLocalAddress returned " << nErr << '\n';
    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;
    std::cout << "端口已连接" << '\n';
}

void Sctrl::nportclose() {
    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';
    std::cout << "端口已关闭" << '\n';
}

void Sctrl::Senable() {
    for (int i=1 ;i < 4; i++ )
    {
        // std::cin >> control1;
        // 将数值写入寄存器
        nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &(control1[i]) );
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
        Sleep(100);
        //从寄存器读取数值
        nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::cout << std::bitset<16>(stateW1) << '\n';
        Sleep(50);
    }
    std::cout << "已完成上使能" << '\n';
}
void Sctrl::Sdisable() {
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

void Sctrl::modeset() {
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E806,0x1, &mode1 );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(50);
    std::cout << "设置为pp模式" << '\n';
}
void Sctrl::pp_parameterS() {
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
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &control1[3] );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    Sleep(50);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << std::bitset<16>(stateW1) << '\n';
    Sleep(200);
}

void Sctrl::Sspin() {
    nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &ctrl2 );
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
    std::cout << "退出转动" << '\n';
}

// void st0p() {
//     while (kbinput) {
//         char c = getchar();
//         if (c == '\n') kbinput = 0;
//     }
//     kbinput = 1;
// }