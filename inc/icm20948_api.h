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

/*! @file icm20948_api.h
 * @brief Public header file for the ICM20948 9-Axis MEMS device API.
 */

#ifndef _ICM20948_API_H_
#define _ICM20948_API_H_

typedef int8_t(*icm20948_read_fptr_t)(uint8_t addr, uint8_t *data, uint32_t len);
typedef int8_t(*icm20948_write_fptr_t)(uint8_t addr, uint8_t *data, uint32_t len);
typedef void(*icm20948_delay_us_fptr_t)(uint32_t period);

int8_t icm20948_intf_init(icm20948_read_fptr_t r, icm20948_write_fptr_t w, icm20948_delay_us_fptr_t delay);
int8_t icm20948_writeRegs(void);

#endif // _ICM20948_API_H_