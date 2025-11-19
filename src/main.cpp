#include "stdafx.h"

int main() {

    Sctrl Axis1;

    // Axis1.nportopen();//开启ADS通讯

    // Axis1.modeset();//设置运动模式
    Axis1.enable();//给电机上使能

    Axis1.motion_pp(200000);//设置pp模式的运动参数
    // Axis1.Senable();//给电机上使能
    Axis1.Sconfirm();//运行前确认状态
    Axis1.Sspin();//开始旋转

    Axis1.disable();//下使能

    // Axis1.nportclose();//关闭通讯

    // long  nErr, nPort;//定义端口变量
    // AmsAddr Addr;
    // PAmsAddr pAddr = &Addr;//指针
    // unsigned short stateW1;//状态字读取值
    // unsigned short control1[]={0,6,7,15}, ctrl2 = 31 ;//控制字输入值
    // unsigned char mode1 = 1;//pp模式输入值
    // int keyinput = 1, pos1 = 20000, pos2 = 0, pos3 = 30000;//闲值
    // UINT v1=200 , a1=10000 , a2 = 10000;//加速度，速度值
    //
    // // 在ADS路由器上打开通信端口
    // nPort = AdsPortOpen();
    // nErr = AdsGetLocalAddress(pAddr);
    // if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    // std::cout << "AdsGetLocalAddress returned " << nErr << '\n';
    // // TwinCAT 3 PLC1 = 851
    // pAddr->port = 851;
    //
    // //设置运动状态
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F2,0x1, &mode1 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(50);
    //
    // // 开启使能，达到Operation Enabled
    // for (int i=1 ;i < 4; i++ )
    //  {
    //     // std::cin >> control1;
    //     // 将数值写入寄存器
    //     nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F0,0x2, &(control1[i]) );
    //     if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    //     // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
    //     Sleep(100);
    //     //从寄存器读取数值
    //     nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    //     if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    //     std::cout << std::bitset<16>(stateW1) << '\n';
    //     Sleep(50);
    // }
    // std::cout << "已完成上使能" << '\n';
    //
    // //暂停程序执行
    // while (keyinput) {
    //     char c = getchar();
    //     if (c == '\n') keyinput = 0;
    // }
    // keyinput = 1;
    //
    //
    // //设置加速度
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7FC,0x4, &a1 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(200);
    //
    // //设置减速度
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E800,0x4, &a2 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(200);
    //
    // //设置速度
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F8,0x4, &v1 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(200);
    //
    // //设置点动位置
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F4,0x4, &pos1 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(200);
    //
    // std::cout << "已完成速度及位置设定" << '\n';
    //
    // //再次确认使能状态为0x000f
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F0,0x2, &control1[3] );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(200);
    //
    // //暂停程序执行
    // while (keyinput) {
    //     char c = getchar();
    //     if (c == '\n') keyinput = 0;
    // }
    // keyinput = 1;
    //
    //
    // //开始转动
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F0,0x2, &ctrl2 );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // Sleep(50);
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    // Sleep(200);
    // std::cout << "开始转动" << '\n';
    //
    // //暂停程序执行
    // while (keyinput) {
    //     char c = getchar();
    //     if (c == '\n') keyinput = 0;
    // }
    // keyinput = 1;
    //
    // //退出转动状态
    // nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F0,0x2, &(control1[3]) );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    // nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    // if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    // std::cout << std::bitset<16>(stateW1) << '\n';
    //
    // std::cout << "退出转动" << '\n';
    //
    // //暂停程序执行
    // while (keyinput) {
    //     char c = getchar();
    //     if (c == '\n') keyinput = 0;
    // }
    // keyinput = 1;
    //
    // // 关闭使能，退回Switch on disabled
    // for (int i=2 ; i>-1 ; i-- )
    // {
    //     // std::cin >> control1;
    //     nErr = AdsSyncWriteReq(pAddr,0xF030,0x5E7F0,0x2, &(control1[i]) );
    //     if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
    //     // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
    //     nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
    //     if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
    //     std::cout << std::bitset<16>(stateW1) << '\n';
    //     Sleep(50);
    // }
    // std::cout << "使能结束" << '\n';
    //
    //
    // // 关闭通信端口
    // nErr = AdsPortClose();
    // if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';

    return 0;

}