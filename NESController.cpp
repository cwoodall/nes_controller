#include "NESController.h"

NESController::NESController(uint8_t d, uint8_t c, uint8_t l) {
    // Set pins for Serial Input, NES Clock and NES Latch
    din = d;
    clk = c;
    latch = l;

    // Initialize data to 0
    data = 0;

    // Setup input/output pins.
    pinMode(latch, OUTPUT);
    pinMode(clk, OUTPUT);
    pinMode(din, INPUT);

    // Initialize latch and clk to default LOW states
    digitalWrite(latch, LOW);
    digitalWrite(clk, LOW);
}

/**
 * void NESController::update()
 *
 * Does a read on the NES controller updating the data buffer.
 * The NES controller is made up of a 8 bit shift register. To 
 * do a read you raise latch HIGH for 2us, to latch the data into
 * the shift register. Read off the first bit and then clock the
 * shift register 8 times to read out the rest of the data and empty
 * the shift register (clock 250kHz).
 */
void NESController::update() {
    data = 0;
    digitalWrite(latch, LOW);
    digitalWrite(clk, LOW);

    digitalWrite(latch, HIGH);
    delayMicroseconds(2);
    digitalWrite(latch, LOW);

    data = digitalRead(din);

    for (int i = 1; i <= 7; i++) {
        digitalWrite(clk, HIGH);
        delayMicroseconds(2);
        data |= digitalRead(din) << i;
        digitalWrite(clk, LOW);
        delayMicroseconds(2);
        digitalWrite(clk, LOW);
    }
}

uint8_t NESController::read() {
    return data;
}
