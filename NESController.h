#ifndef NESController_H
#define NESController_H

#include "Arduino.h"

class NESController 
{
    uint8_t din;
    uint8_t clk;
    uint8_t latch;
    
    uint8_t data;
public:
    NESController(uint8_t, uint8_t, uint8_t);
    void update();
    uint8_t read();
};

#endif
