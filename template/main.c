/****************************************************************************
    ICM-20948 9-Axis MEMS Motion Tracking Device Driver

    Copyright (C) 2020 Stephen Murphy - github.com/stephendpmurphy

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
****************************************************************************/

#include <stdint.h>
#include "icm20948_api.h"

int8_t usr_write(uint8_t addr, uint8_t *data, uint32_t len) {

    // Assert the CS

    // Write your data

    // De-assert the CS
    return 1;
}

int8_t usr_read(uint8_t addr, uint8_t *data, uint32_t len) {
    // Assert the CS

    // Write your data

    // De-assert the CS
    return 1;
}

void usr_delay_us(uint32_t period) {
    // Delay for the requested period
}

int main(void) {

    icm20948_dev_intf_t interface;

    // Store pointers to our read, write, and delay functions
    interface.write = usr_write;
    interface.read = usr_read;
    interface.delay_us = usr_delay_us;

    // Init the icm module and pass in our dev interface struct
    icm20948_init(&interface);

    // Write the regs
    icm20948_writeRegs();

    return 0;
}