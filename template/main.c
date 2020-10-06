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

int8_t usr_write(const uint8_t addr, const uint8_t *data, const uint32_t len) {
    icm20948_return_code_t ret = ICM20948_RET_OK;

    // Assert the CS

    // Write the address

    // Write the data from the provided data buffer

    // De-assert the CS

    return ret;
}

int8_t usr_read(const uint8_t addr, uint8_t *data, const uint32_t len) {
    icm20948_return_code_t ret = ICM20948_RET_OK;

    // Assert the CS

    // Write your data

    // Read out the data, placing the result in the data buffer

    // De-assert the CS

    return ret;
}

void usr_delay_us(uint32_t period) {
    // Delay for the requested period
}

int main(void) {
    icm20948_return_code_t ret = ICM20948_RET_OK;
    icm20948_settings_t settings;
    icm20948_gyro_t gyro_data;
    icm20948_accel_t accel_data;

    // Init the device function pointers
    ret = icm20948_init(usr_read, usr_write, usr_delay_us);

    if( ret == ICM20948_RET_OK ) {
        // Enable the Gyro
        settings.gyro.en = ICM20948_MOD_ENABLED;
        // Select the +-20000dps range
        settings.gyro.fs = ICM20948_GYRO_FS_SEL_2000DPS;
        // Enable the Accel
        settings.accel.en = ICM20948_MOD_ENABLED;
        // Select the +-2G range
        settings.accel.fs = ICM20948_ACCEL_FS_SEL_2G;
        ret = icm20948_applySettings(&settings);
    }

    while(1) {
        // Retrieve the Gyro data and store it in our gyro_data struct
        // Output is in dps (Degress per second)
        ret |= icm20948_getGyroData(&gyro_data);
        // Retrieve the Accel data and store it in our accel_data struct
        // Output is in mG
        ret |= icm20948_getAccelData(&accel_data);
    }

    return 0;
}