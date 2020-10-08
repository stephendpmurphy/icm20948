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

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ICM20948_API_H_
#define _ICM20948_API_H_

#include <stdint.h>
#include <stdbool.h>

typedef int8_t(*icm20948_read_fptr_t)(const uint8_t addr, uint8_t *data, const uint32_t len);
typedef int8_t(*icm20948_write_fptr_t)(const uint8_t addr, const uint8_t *data, const uint32_t len);
typedef void(*icm20948_delay_us_fptr_t)(uint32_t period);

typedef enum {
    ICM20948_RET_OK = 0,
    ICM20948_RET_GEN_FAIL = -1,
    ICM20948_RET_INV_PARAM  = -2,
    ICM20948_RET_NULL_PTR   = -3,
    ICM20948_RET_INV_CONFIG = -4,
    ICM20948_RET_TIMEOUT   = -5
} icm20948_return_code_t;

typedef enum {
    ICM20948_MOD_DISABLED = 0x00,
    ICM20948_MOD_ENABLED
} icm20948_mod_enable_t;

typedef enum {
    ICM20948_GYRO_FS_SEL_250DPS = 0x00,
    ICM20948_GYRO_FS_SEL_500DPS = 0x01,
    ICM20948_GYRO_FS_SEL_1000DPS = 0x02,
    ICM20948_GYRO_FS_SEL_2000DPS = 0x03
} icm20948_gyro_full_scale_select_t;

typedef struct {
    icm20948_mod_enable_t en;
    icm20948_gyro_full_scale_select_t fs;
} icm20948_gyro_settings_t;

typedef enum {
    ICM20948_ACCEL_FS_SEL_2G = 0x00,
    ICM20948_ACCEL_FS_SEL_4G = 0x01,
    ICM20948_ACCEL_FS_SEL_8G = 0x02,
    ICM20948_ACCEL_FS_SEL_16G = 0x03
} icm20948_accel_full_scale_select_t;

typedef struct {
    icm20948_mod_enable_t en;
    icm20948_accel_full_scale_select_t fs;
} icm20948_accel_settings_t;

typedef struct {
    icm20948_mod_enable_t en;
} icm20948_mag_settings_t;

typedef struct {
    icm20948_gyro_settings_t gyro;
    icm20948_accel_settings_t accel;
    icm20948_mag_settings_t mag;
} icm20948_settings_t;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} icm20948_gyro_t;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} icm20948_accel_t;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} icm20948_mag_t;

/*!
 * @brief This API initializes the ICM20948 comms interface, and then does a read from the device
 * to verify working comms
 *
 * @param[in] r: Function pointer to the developers SPI read function
 * @param[in] w: Function pointer to the developers SPI write function
 * @param[in] delay: Function pointer to the developers micro-second delay function
 *
 * @return Returns the status of initialization
 */
icm20948_return_code_t icm20948_init(icm20948_read_fptr_t r, icm20948_write_fptr_t w, icm20948_delay_us_fptr_t delay);

/*!
 * @brief This API applys the developers settings for configuring the ICM20948 components
 *
 * @param[in] newSettings: Pointer to the new ICM20948 settings to be applied
 *
 * @return Returns the status of applying settings
 */
icm20948_return_code_t icm20948_applySettings(icm20948_settings_t *newSettings);

/*!
 * @brief This API retrieves the current gyro data from the device
 *
 * @param[in] gyro: Pointer to the gyro data struct where the new samples
 * should be placed
 *
 * @return Returns the status of reading gyro data
 */
icm20948_return_code_t icm20948_getGyroData(icm20948_gyro_t *gyro);

/*!
 * @brief This API retrieves the current accel data from the device
 *
 * @param[in] accel: Pointer to the accel data struct where the new samples
 * should be placed
 *
 * @return Returns the status of reading accel data
 */
icm20948_return_code_t icm20948_getAccelData(icm20948_accel_t *accel);

#endif // _ICM20948_API_H_

#ifdef __cplusplus
}
#endif