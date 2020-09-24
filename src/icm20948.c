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

/*! @file icm20948.c
 * @brief Source file for the ICM20948 9-Axis MEMS device driver.
 */

#include "icm20948.h"
#include "icm20948_api.h"

static icm20948_dev_t dev;

int8_t icm20948_intf_init(icm20948_read_fptr_t r, icm20948_write_fptr_t w, icm20948_delay_us_fptr_t delay) {

    uint8_t reg[5];
    // Store the interface passed in to us. This has pointer references
    // for our read, write, and delay functions.
    dev.intf.read = r;
    dev.intf.write = w;
    dev.intf.delay_us = delay;

    dev.intf.read(0x01, dev.usr_bank.bank0.arr, sizeof(dev.usr_bank.bank0.arr));
    dev.intf.write(0x01, dev.usr_bank.bank0.arr, sizeof(dev.usr_bank.bank0.arr));
    dev.intf.delay_us(56);

    return 1;
}

int8_t icm20948_writeRegs(void) {
    dev.intf.write(0x00, dev.usr_bank.bank0.arr, sizeof(dev.usr_bank.bank0.arr));
    dev.intf.write(0x01, dev.usr_bank.bank1.arr, sizeof(dev.usr_bank.bank1.arr));
    dev.intf.write(0x02, dev.usr_bank.bank2.arr, sizeof(dev.usr_bank.bank2.arr));
    dev.intf.write(0x03, dev.usr_bank.bank3.arr, sizeof(dev.usr_bank.bank3.arr));

    return 1;
}
