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

static icm20948_usr_bank_t usr_bank;
static icm20948_dev_intf_t interface;

int8_t icm20948_init(icm20948_dev_intf_t *intf) {

    uint8_t reg[5];
    // Store the interface passed in to us. This has pointer references
    // for our read, write, and delay functions.
    interface.read = intf->read;
    interface.write = intf->write;
    interface.delay_us = intf->delay_us;

    interface.read(0x01, usr_bank.bank0.arr, sizeof(usr_bank.bank0.arr));
    interface.write(0x01, usr_bank.bank0.arr, sizeof(usr_bank.bank0.arr));
    interface.delay_us(56);

    return 1;
}

int8_t icm20948_writeRegs(void) {
    interface.write(0x00, usr_bank.bank0.arr, sizeof(usr_bank.bank0.arr));
    interface.write(0x01, usr_bank.bank1.arr, sizeof(usr_bank.bank1.arr));
    interface.write(0x02, usr_bank.bank2.arr, sizeof(usr_bank.bank2.arr));
    interface.write(0x03, usr_bank.bank3.arr, sizeof(usr_bank.bank3.arr));

    return 1;
}
