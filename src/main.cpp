#include "stdafx.h"
#include "minwindef.h"

int main()
{
    long  nErr, nPort;//定义端口变量
    AmsAddr Addr;
    PAmsAddr pAddr = &Addr;
    UINT control1, tesx;

    // 在ADS路由器上打开通信端口
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
    std::cout << "AdsGetLocalAddress returned " << nErr << '\n';
    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;

    // 从用户处读取需写入PLC的数值
    do {
        std::cin >> tesx;
        nErr = AdsSyncWriteReq(pAddr,0xF030,0x3E800,0x2, &tesx );
        if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
        nErr = AdsSyncReadReq(pAddr,0xF030,0x3E800,0x2, &control1 );
        if (nErr) std::cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
        std::cout << control1 << '\n';
    }while (getchar() =='\n');

    // 将数值写入MD0寄存器
    // nErr = AdsSyncWriteReq( pAddr, 0x4020, 0x0, 0x4, & );
    // if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';

    // 关闭通信端口
    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';

    return 0;




}