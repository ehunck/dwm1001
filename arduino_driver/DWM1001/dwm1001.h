#ifndef _DWM1001_H_
#define _DWM1001_H_

#include "Arduino.h"
#include <stdlib.h>
#include <SoftwareSerial.h>
#include "TLV.h"


class dwm1001
{
public:
    dwm1001(SoftwareSerial& port);
    ~dwm1001();

    bool DWMReset();

private:
    SoftwareSerial& _port;

    void _TLVRequest(uint8_t type, uint8_t length, uint8_t *payload);
    void _TLVResponse(uint8_t *rx_type, uint8_t *rx_length, uint8_t *rx_payload);
    void _TLVTransaction(uint8_t tx_type, uint8_t tx_length, uint8_t *tx_payload,
    uint8_t *rx_type, uint8_t *rx_length, uint8_t *rx_payload);
};


#endif
