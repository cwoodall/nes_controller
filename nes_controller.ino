/** Arduino-NES Controller USB Gamepad
 * Author: Christopher Woodall
 * Date: 4-18-2012
 * License: MIT License 2012
 * A BUILDS Production
 *
 * 
 */
#include "Keyboard.h"
#include "NESController.h"

#define NES_CLK 2
#define NES_LATCH 3
#define NES_IN 4
#define BAUDRATE 9600

uint8_t keycodes[8] = { KEY_Z, KEY_X, KEY_A, KEY_S, KEY_UARROW, 
                        KEY_DARROW, KEY_LARROW, KEY_RARROW };

byte buf[8] = { 0 };	/* Keyboard report buffer */
uint8_t j = 2;
NESController controller(NES_IN, NES_CLK, NES_LATCH);
//Keyboard keyboard();

void setup() 
{
//    keyboard.initialize(BAUDRATE);
//    keyboard.clear();
    Serial.begin(9600);
    delay(200);
}



void loop()
{
    j = 2; // Reset buttons count
    controller.update();
//    keyboard.clear();
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 0;

    if ((controller.read() | 0b11111110) != 0xFF) {
        buf[j] = KEY_Z;
//        keyboard.setBuffer(j, KEY_Z);
        j += 1;
    }
    
    if ((controller.read() | 0b11111101) != 0xFF) {
        buf[j] = KEY_X;
//        keyboard.setBuffer(j, KEY_X);
        j += 1;
    }
    
    if ((controller.read() | 0b11111011) != 0xFF) {
        buf[j] = KEY_A;
        //keyboard.setBuffer(j, KEY_A);
        j += 1;
    }
    
    if ((controller.read() | 0b11110111) != 0xFF) {
        buf[j] = KEY_S;
//        keyboard.setBuffer(j, KEY_S);
        j += 1;
    }
    
    if ((controller.read() | 0b11101111) != 0xFF) {
        buf[j] = KEY_UARROW;
//        keyboard.setBuffer(j, KEY_UARROW);
        j += 1;
    }
    
    if ((controller.read() | 0b11011111) != 0xFF) {
        buf[j] = KEY_DARROW;
//        keyboard.setBuffer(j, KEY_DARROW);
        j += 1;
    }
    
    if ((controller.read() | 0b10111111) != 0xFF) {
        buf[j] = KEY_LARROW;
//        keyboard.setBuffer(j, KEY_LARROW);
        j += 1;
    }
 
   if ((controller.read() | 0b01111111) != 0xFF) {
        buf[j] = KEY_RARROW;
//        keyboard.setBuffer(j, KEY_RARROW);
        j += 1;
    }
    
//    keyboard.write();
    Serial.write(buf, 8);	// Send keypress
    delay(100);
}