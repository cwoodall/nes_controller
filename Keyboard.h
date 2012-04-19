#ifndef Keyboard_H
#define Keyboard_H

#include "Arduino.h"

// List of standard HID Keycodes
#define KEY_LEFT_CTRL 0x01
#define KEY_LEFT_SHIFT 0x02
#define KEY_RIGHT_CTRL 0x10
#define KEY_RIGHT_SHIFT 0x20
#define KEY_NULL 0
#define KEY_A 4
#define KEY_B 5 
#define KEY_C 6
#define KEY_D 7
#define KEY_E 8
#define KEY_F 9
#define KEY_G 10
#define KEY_H 11
#define KEY_I 12
#define KEY_J 13
#define KEY_K 14
#define KEY_L 15
#define KEY_M 16
#define KEY_N 17
#define KEY_O 18
#define KEY_P 19
#define KEY_Q 20
#define KEY_R 21
#define KEY_S 22
#define KEY_T 23
#define KEY_U 24
#define KEY_V 25
#define KEY_W 26
#define KEY_X 27
#define KEY_Y 28
#define KEY_Z 29
#define KEY_RARROW 79
#define KEY_LARROW 80
#define KEY_DARROW 81
#define KEY_UARROW 82
/*
class Keyboard
{
    uint8_t buf[8];
public:
    Keyboard(int);
    void clear();
    void setBuffer(uint8_t, uint8_t);
    void write();
    uint8_t read(uint8_t);
};
*/
#endif
