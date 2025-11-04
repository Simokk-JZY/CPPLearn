#include <iostream>
#include <windows.h>

// ADS headers for TwinCAT 3
#include "TcAdsDef.h"
#include "TcAdsAPI.h"

int main()
{
    long nErr, nPort;
    AmsAddr Addr;
    PAmsAddr pAddr = &Addr;
    DWORD dwData;

    // 在ADS路由器上打开通信端口
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    if (nErr) std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';

    // TwinCAT 3 PLC1 = 851
    pAddr->port = 851;

    // 从用户处读取需写入PLC的数值
    std::cout << "Value: ";
    std::cin >> dwData;

    // 将数值写入MD0寄存器
    nErr = AdsSyncWriteReq( pAddr, 0x4020, 0x0, 0x4, &dwData );
    if (nErr) std::cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';

    // 关闭通信端口
    nErr = AdsPortClose();
    if (nErr) std::cerr << "Error: AdsPortClose: " << nErr << '\n';

    return 0;
}