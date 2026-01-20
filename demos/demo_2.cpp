//
// Created by Jzy on 2026/1/20.
//

#include "stdafx.h"


int main() {

    Sctrl Axis1("轴1",&axisctrl[1],&axisstate[1]);//定义对象

    std::thread t1(&Sctrl::transmit,axisctrl,axisstate);//开启线程
    // t1.detach();
    Sleep(1000);
    std::cin.get();
    Axis1.Sconfirm();
    std::cin.get();

    system("pause");



    return 0;

}