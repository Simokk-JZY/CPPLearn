//
// Created by Simokk on 2026/4/21.
//

#ifndef CPPLEARN_AXIS_CONFIG_H
#define CPPLEARN_AXIS_CONFIG_H

const unsigned short controlWORDbit[]={6,7,15};
const unsigned short SWITCHOFF = 0x00;
const unsigned short DISABLED  = 0x06;
const unsigned short SWITCHON  = 0x07;
const unsigned short ENABLED   = 0x0F;
const unsigned short MOVESTART = 0x1F;

const unsigned char PPmod = 1;
const int32_t zero[]={
    0,
    0
};
const unsigned int Maxvelocity = 0x00ffffff;




//ads indexgroup & indexoffset
const long indexgroup1 = 0xF030;
const long indexgroup2 = 0xF020;

const long indexoffset1 = 0x3E800;
const long indexoffset2 = 0x1F400;


#endif //CPPLEARN_AXIS_CONFIG_H