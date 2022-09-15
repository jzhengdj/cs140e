/*
 * Implement the following routines to set GPIO pins to input or output,
 * and to read (input) and write (output) them.
 *
 * DO NOT USE loads and stores directly: only use GET32 and PUT32 
 * to read and write memory.  Use the minimal number of such calls.
 *
 * See rpi.h in this directory for the definitions.
 */
#include "rpi.h"

// see broadcomm documents for magic addresses.
#define GPIO_BASE 0x20200000
static unsigned* gpfsel = GPIO_BASE;
static const unsigned gpio_set0  = (GPIO_BASE + 0x1C);
static const unsigned gpio_clr0  = (GPIO_BASE + 0x28);
static const unsigned gpio_lev0  = (GPIO_BASE + 0x34);

//
// Part 1 implement gpio_set_on, gpio_set_off, gpio_set_output
//

// set <pin> to be an output pin.  
//
// note: fsel0, fsel1, fsel2 are contiguous in memory, so you 
// can (and should) use array calculations!
void gpio_set_output(unsigned pin) {
    // implement this
    // use <gpio_fsel0>
    uint32_t sel = get32(&gpfsel[pin/10]);
    sel = ( sel & ~ (0x7<<(pin%10*3))) | (0x1 << (pin%10*3));
    put32(&gpfsel[pin/10], 0x1);

    // 1. works 
    // uint32_t sel = 0x1;
    // put32(GPIO_BASE + 8, sel);

    // 2. works
    // put32(&gpfsel[pin/10], 0x1);
}

// set GPIO <pin> on.
void gpio_set_on(unsigned pin) {
    // implement this
    // use <gpio_set0>
    uint32_t set0 = GET32(gpio_set0) | (0x1 << pin);
    PUT32(gpio_set0, set0);
}

// set GPIO <pin> off
void gpio_set_off(unsigned pin) {
    // implement this
    // use <gpio_clr0>
    uint32_t clr0 = GET32(gpio_clr0) | (0x1 << pin);
    PUT32(gpio_clr0, clr0);
}

// set <pin> to <v> (v \in {0,1})
void gpio_write(unsigned pin, unsigned v) {
    if(v)
       gpio_set_on(pin);
    else
       gpio_set_off(pin);
}

//
// Part 2: implement gpio_set_input and gpio_read
//

// set <pin> to input.
void gpio_set_input(unsigned pin) {
    // implement.
}

// return the value of <pin>
int gpio_read(unsigned pin) {
    unsigned v = 0;

    // implement.
    return v;
}
