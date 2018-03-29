#ifndef _TLV_H_
#define _TLV_H_

/* TYPE list */

enum TLVType
{
    TYPE_CMD_POS_SET            =   1,      //  Request: set position coordinates XYZ
    TYPE_CMD_POS_GET            =   2,      //  Request: get position coordinates XYZ
    TYPE_CMD_UR_SET             =   3,      //  Request: set position update rate
    TYPE_CMD_UR_GET             =   4,      //  Request: get position update rate
    TYPE_CMD_CFG_TN_SET         =   5,      //  Request: set configuration for the tag
    TYPE_CMD_CFG_AN_SET         =   7,      //  Request: set configuration for the anchor
    TYPE_CMD_CFG_GET            =   8,      //  Request: get configuration data
    TYPE_CMD_CFG_SAVE           =   9,      //  Request: save configuration data
    TYPE_CMD_SLEEP              =   10,     //  Request: sleep
    TYPE_CMD_LOC_GET            =   12,     //  Request: location get
    TYPE_CMD_BLE_ADDR_SET       =   15,     //  Request: BLE address set
    TYPE_CMD_BLE_ADDR_GET       =   16,     //  Request: BLE address get
    TYPE_CMD_RESET              =   20,     //  Request: reset
    TYPE_CMD_VER_GET            =   21,     //  Request: get FW version
    TYPE_CMD_GPIO_CFG_OUTPUT    =   40,     //  Request: configure output pin and set
    TYPE_CMD_GPIO_CFG_INPUT     =   41,     //  Request: configure input pin
    TYPE_CMD_GPIO_VAL_SET       =   42,     //  Request: set pin value
    TYPE_CMD_GPIO_VAL_GET       =   43,     //  Request: get pin value
    TYPE_CMD_GPIO_VAL_TOGGLE    =   44,     //  Request: toggle pin value
    TYPE_CMD_STATUS_GET         =   50,     //  Request: get status
    TYPE_CMD_INT_CFG            =   52,     //  Request: configure interrupts
    TYPE_RET_VAL                =   64,     //  Response: the previous request is ok or error
    TYPE_POS_XYZ                =   65,     //  Response: position coordinates x,y,z
    TYPE_POS_X                  =   66,     //  Response: position coordinate x
    TYPE_POS_Y                  =   67,     //  Response: position coordinate y
    TYPE_POS_Z                  =   68,     //  Response: position coordinate z
    TYPE_UR                     =   69,     //  Response: update rate
    TYPE_CFG                    =   70,     //  Response: configuration data
    TYPE_DIST                   =   72,     //  Response: distances
    TYPE_RNG_AN_POS_DIST        =   73,     //  Response: ranging anchor distances and positions
    TYPE_FW_VER                 =   80,     //  Response: firmware version
    TYPE_CFG_VER                =   81,     //  Response: configuration version
    TYPE_HW_VER                 =   82,     //  Response: hardware version
    TYPE_PIN_VAL                =   85,     //  Response: pin value
    TYPE_STATUS                 =   90,     //  Response: status
    TYPE_CMD_N_POS_SET          =   128,    //  Request: nested command set position
    TYPE_CMD_N_LOC_GET          =   130,    //  Request: nested command location get
    TYPE_DUMMY                  =   0,      //  Reserved for SPI dummy byte
};

enum TLVError 
{
    ERROR_OK                =   0,
    ERROR_UNKNOWN_COMMAND   =   1,
    ERROR_INTERNAL_ERROR    =   2,
    ERROR_INVALID_PARAMETER =   3,
    ERROR_BUSY              =   4,
};


#endif
