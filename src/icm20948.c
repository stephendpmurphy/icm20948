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

#include <string.h>
#include "icm20948.h"
#include "icm20948_api.h"

static icm20948_dev_t dev;
static icm20948_settings_t settings;

static icm20948_return_code_t _spi_read(uint8_t addr, uint8_t *data, uint32_t len) {
    return dev.intf.read((addr | (0x01 << 7)), data, len);
}

static icm20948_return_code_t _spi_write(uint8_t addr, uint8_t *data, uint32_t len) {
    return dev.intf.write(addr, data, len);
}

icm20948_return_code_t icm20948_init(icm20948_read_fptr_t r, icm20948_write_fptr_t w, icm20948_delay_us_fptr_t delay) {

    icm20948_return_code_t ret = ICM20948_RET_OK;

    // Verify that the function pointers given to us are not invalid
    if( (r == NULL) || (w == NULL) || (delay == NULL) ) {
        // One of the functions given to us was a NULL pointer, return with a
        // NULL PTR return code
        ret = ICM20948_RET_NULL_PTR;
    }

    // Store the interface functions passed in to us to be used to
    // communicate with the IC.
    dev.intf.read = r;
    dev.intf.write = w;
    dev.intf.delay_us = delay;

    // Select user register bank 0
    dev.usr_bank.reg_bank_sel = ICM20948_USER_BANK_0;

    if( ret == ICM20948_RET_OK ) {
        // Write to the reg bank select to select bank 0
        ret = _spi_write(ICM20948_ADDR_REG_BANK_SEL, &dev.usr_bank.reg_bank_sel, 0x01);
    }

    if( ret == ICM20948_RET_OK) {
        // If the bank was selected, read the WHO_AM_I register
        ret = _spi_read(ICM20948_ADDR_WHO_AM_I, &dev.usr_bank.bank0.bytes.WHO_AM_I, 0x01);

        // If we read the register, and the ID doesn't match, return with a general failure
        if( (ret == ICM20948_RET_OK) && (dev.usr_bank.bank0.bytes.WHO_AM_I != ICM20948_WHO_AM_I_DEFAULT) ) {
            // The WHO_AM_I ID was incorrect.
            ret = ICM20948_RET_GEN_FAIL;
        }
        else {
            // We read the ID and it matched to what we expected. All is good.
            ret = ICM20948_RET_OK;
        }
    }

    // Return our init status
    return ret;
}

icm20948_return_code_t icm20948_applySettings(icm20948_settings_t *newSettings) {

    // Copy over the new settings
    memcpy(&settings, newSettings, sizeof(settings));

    // Act upon and apply the new settings

    if( settings.accel_en == ICM20948_ACCEL_ENABLE ) {
        // Enable the accelerometer
    }
    else {
        // Disable the accelerometer
    }

    return ICM20948_RET_OK;
}