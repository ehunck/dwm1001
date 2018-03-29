#include "dwm1001.h"

dwm1001::dwm1001(SoftwareSerial& port) : _port(port)
{
    _port.begin(115200);
}

dwm1001::~dwm1001()
{

}

bool dwm1001::DWMReset()
{
    uint8_t rx_type = 0;
    uint8_t rx_length = 0;
    uint8_t rx_payload[1] = {0};
    uint8_t tx_payload[1] = {0};

    _TLVTransaction(TYPE_CMD_RESET, 0, tx_payload, &rx_type, &rx_length, rx_payload);

    if((rx_type == TYPE_RET_VAL) && (rx_length == 1) && (rx_payload[0] == ERROR_OK))
    {
        return true;
    }
    return false;
}

void dwm1001::_TLVTransaction(uint8_t tx_type, uint8_t tx_length, uint8_t *tx_payload,
    uint8_t *rx_type, uint8_t *rx_length, uint8_t *rx_payload)
{
    _TLVRequest(tx_type, tx_length, tx_payload);
    _TLVResponse(rx_type, rx_length, rx_payload);
}

void dwm1001::_TLVRequest(uint8_t type, uint8_t length, uint8_t *payload)
{
    _port.write(type);
    _port.write(length);
    for(int i = 0; i < length; i ++)
    {
        _port.write(payload[i]);
    }
}

void dwm1001::_TLVResponse(uint8_t *rx_type, uint8_t *rx_length, uint8_t *rx_payload)
{
    while(!_port.available()); // TODO: get rid of these blocking waits
    *rx_type = _port.read();
    while(!_port.available()); // TODO: 
    *rx_length = _port.read();
    for(int i = 0; i < *rx_length; i++)
    {
        while(!_port.available()); // TODO:
        rx_payload[i] = _port.read();
    }
}
