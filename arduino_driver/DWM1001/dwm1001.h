#ifndef _DWM1001_H_
#define _DWM1001_H_

#include "Arduino.h"
#include "TLV.h"

class dwm1001
{
public:
    dwm1001();
    ~dwm1001();

    bool DWMReset();

private:
    Serial& _port;

    void _TLVRequest(uint8_t type, uint8_t length, uint8_t value);
    void _TLVResponse();
    void _TLVTransaction();
};


#endif