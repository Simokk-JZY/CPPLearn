//
// Created by DELL on 2026/1/19.
//

#include "stdafx.h"

struct ads {
    unsigned short control1;
    unsigned char mode1;
    int32_t position1;
    unsigned int velocity1;
    unsigned int max_speed1;
    unsigned short control2;
    unsigned char mode2;
    int32_t position2;
    unsigned int velocity2;
    unsigned int max_speed2;
};

int main()
{
    ads axis1;
    axis1.control1 = 1;
    axis1.mode1 = 2;
    axis1.position1 = 3;
    axis1.velocity1 = 4;
    axis1.max_speed1 = 5;
    axis1.control2 = 1;
    axis1.mode2 = 2;
    axis1.position2 = 3;
    axis1.velocity2 = 4;
    axis1.max_speed2 = 5;

    std::cout << sizeof(axis1) << "\n";
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

    nErr = AdsSyncWriteReq(pAddr, 0xF030, 0x3E800, sizeof(axis1), &(axis1));
    if (nErr) printf("Error: Ads: Write struct: %d\n", nErr);

    std::cin.get();

    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';
    std::cout << "端口已关闭" << '\n';

}
