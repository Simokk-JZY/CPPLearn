//
// Created by DELL on 2026/1/19.
//

#include "stdafx.h"

struct Ads {
    unsigned short control;
    unsigned char mode;
    int32_t position;
    unsigned int velocity;
    unsigned int max_speed;
}axis1[2];

struct Ads2 {
    unsigned short stateW;
}axis2[2];

int main()
{
    // Ads axis1;
    axis1[0]={1,2,3,4,5};
    axis1[1]={8,4,7,8,9};

    // axis2[0]={13};


    std::cout << sizeof(axis1) << "\n";
    std::cout << sizeof(axis2) << "\n";
    std::cout << axis2[0].stateW <<'\n'<< axis2[1].stateW <<'\n';
    std::cin.get();

    long  nErr{}, nPort{};
    AmsAddr Addr{};
    PAmsAddr pAddr = &Addr;//指针
    //通过之前获取的句柄向PLC写入结构体
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);//自动获取本地地址
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    std::cout << "AdsGetLocalAddress returned " << nErr << '\n';

    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;
    std::cout << "端口已连接" << '\n';

    nErr = AdsSyncWriteReq(pAddr, 0xF030, 0x5F820, sizeof(axis1), &(axis1[0]));
    if (nErr) printf("Error: Ads: Write struct: %d\n", nErr);
    nErr = AdsSyncReadReq(pAddr,0xF020,0x5F840,sizeof(axis2), &(axis2[0]) );
    if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    std::cout << axis2[0].stateW << axis2[1].stateW <<'\n';
    std::cin.get();

    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';
    std::cout << "端口已关闭" << '\n';

}
