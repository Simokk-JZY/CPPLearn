#include "stdafx.h"

int main() {
    long  nErr, nPort;//定义端口变量
    AmsAddr Addr;
    PAmsAddr pAddr = &Addr;
    unsigned short stateW1;
    unsigned short control1[]={0,6,7,15};
    int keyinput = 1;

    // 在ADS路由器上打开通信端口
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    std::cout << "AdsGetLocalAddress returned " << nErr << '\n';
    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;

    // 从用户处读取需写入PLC的数值
    for (int i=1 ;i < 4; i++ )
     {
        // std::cin >> control1;
        // 将数值写入寄存器
        nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &(control1[i]) );
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
        //从寄存器读取数值
        nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::cout << stateW1 << '\n';
        Sleep(50);
    }

    //暂停程序执行
    while (keyinput) {
        char c=getchar();
        if (c == '\n') keyinput = 0;
    }
    keyinput = 1;

    for (int i=2 ; i>-1 ; i-- )
    {
        // std::cin >> control1;
        nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &(control1[i]) );
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        // std::cout << "Error: AdsSyncWriteReq: " << nErr << '\n'；
        nErr = AdsSyncReadReq(pAddr,0xF020,0x1F400,0x2, &stateW1 );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::cout << stateW1 << '\n';
        Sleep(50);
    }



    // 关闭通信端口
    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';

    return 0;

}