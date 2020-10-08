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

/*! @file icm20948.h
 * @brief Private header file for the ICM20948 9-Axis MEMS device driver.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ICM20948_H_
#define _ICM20948_H_

#include <stdint.h>
#include "icm20948_api.h"

#define ICM20948_BANK0_REG_COUNT            (65)
#define ICM20948_BANK1_REG_COUNT            (14)
#define ICM20948_BANK2_REG_COUNT            (20)
#define ICM20948_BANK3_REG_COUNT            (25)

#define ICM20948_WHO_AM_I_DEFAULT           (0xEA)
#define ICM20948_EXT_SLV_SENS_DATA_COUNT    (25)

#define ICM20948_GYRO_RATE_250              (0x00)
#define ICM20948_GYRO_LPF_17HZ              (0x29)

typedef enum {
    ICM20948_USER_BANK_0 = 0x00,
    ICM20948_USER_BANK_1 = 0x01,
    ICM20948_USER_BANK_2 = 0x02,
    ICM20948_USER_BANK_3 = 0x03
} icm20948_reg_bank_sel_t;

#define ICM20948_ADDR_REG_BANK_SEL          (0x7F)

typedef enum {
    ICM20948_ADDR_WHO_AM_I = 0x00,
    ICM20948_ADDR_PWR_MGMT_1 = 0x06,
    ICM20948_ADDR_PWR_MGMT_2 = 0x07,
    ICM20948_ADDR_ACCEL_XOUT_H = 0x2D,
    ICM20948_ADDR_ACCEL_XOUT_L = 0x2E,
    ICM20948_ADDR_ACCEL_YOUT_H = 0x2F,
    ICM20948_ADDR_ACCEL_YOUT_L = 0x30,
    ICM20948_ADDR_ACCEL_ZOUT_H = 0x31,
    ICM20948_ADDR_ACCEL_ZOUT_L = 0x32,
    ICM20948_ADDR_GYRO_XOUT_H = 0x33,
    ICM20948_ADDR_GYRO_XOUT_L = 0x34,
    ICM20948_ADDR_GYRO_YOUT_H = 0x35,
    ICM20948_ADDR_GYRO_YOUT_L = 0x36,
    ICM20948_ADDR_GYRO_ZOUT_H = 0x37,
    ICM20948_ADDR_GYRO_ZOUT_L = 0x38,
} icm20948_reg_bank0_addr_t;

typedef enum {
    ICM20948_ADDR_GYRO_SMPLRT_DIV = 0x00,
    ICM20948_ADDR_GYRO_CONFIG_1 = 0x01,
    ICM20948_ADDR_ACCEL_SMPLRT_DIV_1 = 0x10,
    ICM20948_ADDR_ACCEL_SMPLRT_DIV_2 = 0x11,
    ICM20948_ADDR_ACCEL_CONFIG  = 0x14,
    ICM20948_ADDR_ACCEL_CONFIG_2 = 0x15,
} icm20948_reg_bank2_addr_t;

typedef union {
    struct {
        uint8_t WHO_AM_I;

        union {
            struct {
                uint8_t RSVD                : 1;
                uint8_t I2C_MST_RST         : 1;
                uint8_t SRAM_RST            : 1;
                uint8_t DMP_RST             : 1;
                uint8_t I2C_IF_DS           : 1;
                uint8_t I2C_MST_EN          : 1;
                uint8_t FIFO_EN             : 1;
                uint8_t DMP_EN              : 1;
            } bits;
            uint8_t byte;
        } USER_CTRL;

        union {
            struct {
                uint8_t RSVD0               : 4;
                uint8_t GYRO_CYCLE          : 1;
                uint8_t ACCEL_CYCLE         : 1;
                uint8_t I2C_MST_CYCLE       : 1;
                uint8_t RSVD1               : 1;
            } bits;
            uint8_t byte;
        } LP_CONFIG;

        union {
            struct {
                uint8_t CLKSEL              : 3;
                uint8_t TEMP_DIS            : 1;
                uint8_t RSVD                : 1;
                uint8_t LP_EN               : 1;
                uint8_t SLEEP               : 1;
                uint8_t DEVICE_RESET        : 1;
            } bits;
            uint8_t byte;
        } PWR_MGMT_1;

        union {
            struct {
                uint8_t DISABLE_GYRO        : 3;
                uint8_t DISABLE_ACCEL       : 3;
                uint8_t RSVD                : 2;
            } bits;
            uint8_t byte;
        } PWR_MGMT_2;

        union {
            struct {
                uint8_t RSVD                : 1;
                uint8_t BYPASS_EN           : 1;
                uint8_t FSYNC_INT_MODE_EN   : 1;
                uint8_t ACTL_FSYNC          : 1;
                uint8_t INT_ANYRD_2CLEAR    : 1;
                uint8_t INT1_LATCH__EN      : 1;
                uint8_t INT1_OPEN           : 1;
                uint8_t INT1_ACTL           : 1;
            } bits;
            uint8_t byte;
        } INT_PIN_CFG;

        union {
            struct {
                uint8_t I2C_MST_INT_EN      : 1;
                uint8_t DMP_INT1_EN         : 1;
                uint8_t PLL_RDY_EN          : 1;
                uint8_t WOM_INT_EN          : 1;
                uint8_t RSVD                : 3;
                uint8_t REG_WOF_EN          : 1;
            } bits;
            uint8_t byte;
        } INT_ENABLE;

        union {
            struct {
                uint8_t RAW_DATA_0_RDY_EN   : 1;
                uint8_t RSVD                : 7;
            } bits;
            uint8_t byte;
        } INT_ENABLE_1;

        union {
            struct {
                uint8_t FIFO_OVERFLOW_EN    : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } INT_ENABLE_2;

        union {
            struct {
                uint8_t FIFO_W_EN           : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } INT_ENABLE_3;

        union {
            struct {
                uint8_t I2C_SLV0_NACK       : 1;
                uint8_t I2C_SLV1_NACK       : 1;
                uint8_t I2C_SLV2_NACK       : 1;
                uint8_t I2C_SLV3_NACK       : 1;
                uint8_t I2C_SLV4_NACK       : 1;
                uint8_t I2C_LOST_ARB        : 1;
                uint8_t I2C_SLV4_DONE       : 1;
                uint8_t PASS_THROUGH        : 1;
            } bits;
            uint8_t byte;
        } I2C_MST_STATUS;

        union {
            struct {
                uint8_t I2C_MST_INT         : 1;
                uint8_t DMP_INT1            : 1;
                uint8_t PLL_RDY_INT         : 1;
                uint8_t WOM_INT             : 1;
                uint8_t RSVD                : 4;
            } bits;
            uint8_t byte;
        } INT_STATUS;

        union {
            struct {
                uint8_t RAW_DATA_0_RDY_INT  : 1;
                uint8_t RSVD                : 7;
            } bits;
            uint8_t byte;
        } INT_STATUS_1;

        union {
            struct {
                uint8_t FIFO_OVERFLOW_INT   : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } INT_STATUS_2;

        union {
            struct {
                uint8_t FIFO_WM_INT         : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } INT_STATUS_3;

        uint8_t DELAY_TIMEH;
        uint8_t DELAY_TIMEL;
        uint8_t ACCEL_XOUT_H;
        uint8_t ACCEL_XOUT_L;
        uint8_t ACCEL_YOUT_H;
        uint8_t ACCEL_YOUT_L;
        uint8_t ACCEL_ZOUT_H;
        uint8_t ACCEL_ZOUT_L;
        uint8_t GYRO_XOUT_H;
        uint8_t GYRO_XOUT_L;
        uint8_t GYRO_YOUT_H;
        uint8_t GYRO_YOUT_L;
        uint8_t GYRO_ZOUT_H;
        uint8_t GYRO_ZOUT_L;
        uint8_t TEMP_OUT_H;
        uint8_t TEMP_OUT_L;
        uint8_t EXT_SLV_SENS_DATA[ICM20948_EXT_SLV_SENS_DATA_COUNT];

        union {
            struct {
                uint8_t SLV_0_FIFO_EN       : 1;
                uint8_t SLV_1_FIFO_EN       : 1;
                uint8_t SLV_2_FIFO_EN       : 1;
                uint8_t SLV_3_FIFO_EN       : 1;
                uint8_t RSVD                : 4;
            } bits;
            uint8_t byte;
        } FIFO_EN_1;

        union {
            struct {
                uint8_t TEMP_FIFO_EN        : 1;
                uint8_t GYRO_X_FIFO_EN      : 1;
                uint8_t GYRO_Y_FIFO_EN      : 1;
                uint8_t GYRO_Z_FIFO_EN      : 1;
                uint8_t ACCEL_FIFO_EN       : 1;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } FIFO_EN_2;

        union {
            struct {
                uint8_t FIFO_RESET          : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } FIFO_RST;

        union {
            struct {
                uint8_t FIFO_MODE           : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } FIFO_MODE;

        union {
            struct {
                uint8_t FIFO_COUNTH         : 5;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } FIFO_COUNTH;

        uint8_t FIFO_COUNTL;
        uint8_t FIFO_R_W;
        uint8_t DATA_RDY_STATUS;
        uint8_t FIFO_CFG;

        union {
            struct {
                uint8_t RSVD0               : 4;
                uint8_t USER_BANK           : 2;
                uint8_t RSVD1               : 2;
            } bits;
            uint8_t byte;
        } REG_BANK_SEL;
    } bytes;
    uint8_t arr[ICM20948_BANK0_REG_COUNT];
} icm20948_reg_bank_0_t;

typedef union {
    struct {
        uint8_t SELF_TEST_X_GYRO;
        uint8_t SELF_TEST_Y_GYRO;
        uint8_t SELF_TEST_Z_GYRO;
        uint8_t SELF_TEST_X_ACCEL;
        uint8_t SELF_TEST_Y_ACCEL;
        uint8_t SELF_TEST_Z_ACCEL;
        uint8_t XA_OFFS_H;

        union {
            struct {
                uint8_t RSVD                : 1;
                uint8_t XA_OFFS             : 7;
            } bits;
            uint8_t byte;
        } XA_OFFS_L;

        uint8_t YA_OFFS_H;

        union {
            struct {
                uint8_t RSVD                : 1;
                uint8_t YA_OFFS             : 7;
            } bits;
            uint8_t byte;
        } YA_OFFS_L;

        uint8_t ZA_OFFS_H;

        union {
            struct {
                uint8_t RSVD                : 1;
                uint8_t ZA_OFFS             : 7;
            } bits;
            uint8_t byte;
        } ZA_OFFS_L;

        uint8_t TIMEBASE_CORRECTION_PLL;

        union {
            struct {
                uint8_t RSVD0               : 4;
                uint8_t USER_BANK           : 2;
                uint8_t RSVD1               : 2;
            } bits;
            uint8_t byte;
        } REG_BANK_SEL;
    } bytes;
    uint8_t arr[ICM20948_BANK1_REG_COUNT];
} icm20948_reg_bank_1_t;

typedef union {
    struct {
        uint8_t GYRO_SMPLRT_DIV;

        union {
            struct {
                uint8_t GYRO_FCHOICE        : 1;
                uint8_t GYRO_FS_SEL         : 2;
                uint8_t GYRO_DLPFCFG        : 3;
                uint8_t RSVD                : 2;
            } bits;
            uint8_t byte;
        } GYRO_CONFIG_1;

        union {
            struct {
                uint8_t GYRO_AVGCFG         : 3;
                uint8_t ZGYRO_CTEN          : 1;
                uint8_t YGYRO_CTEN          : 1;
                uint8_t XGYRO_CTEN          : 1;
                uint8_t RSVD                : 2;
            } bits;
            uint8_t byte;
        } GYRO_CONFIG_2;

        uint8_t XG_OFFS_USRH;
        uint8_t XG_OFFS_USRL;
        uint8_t YG_OFFS_USRH;
        uint8_t YG_OFFS_USRL;
        uint8_t ZG_OFFS_USRH;
        uint8_t ZG_OFFS_USRL;

        union {
            struct {
                uint8_t ODR_ALIGN_EN        : 1;
                uint8_t RSVD                : 7;
            } bits;
            uint8_t byte;
        } ODR_ALIGN_EN;

        union {
            struct {
                uint8_t ACCEL_SMPLRT_DIV    : 4;
                uint8_t RSVD                : 4;
            } bits;
            uint8_t byte;
        } ACCEL_SMPLRT_DIV_1;

        uint8_t ACCEL_SMPLRT_DIV_2;

        union {
            struct {
                uint8_t ACCEL_INTEL_MODE_INT    : 1;
                uint8_t ACCEL_INTEL_EN      : 1;
                uint8_t RSVD                : 6;
            } bits;
            uint8_t byte;
        } ACCEL_INTEL_CTRL;

        uint8_t ACCEL_WOM_THR;

        union {
            struct {
                uint8_t ACCEL_FCHOICE       : 1;
                uint8_t ACCEL_FS_SEL        : 2;
                uint8_t ACCEL_DLPFCFG       : 3;
                uint8_t RSVD                : 2;
            } bits;
            uint8_t byte;
        } ACCEL_CONFIG;

        union {
            struct {
                uint8_t DEC3_CFG            : 2;
                uint8_t AZ_ST_EN_REG        : 1;
                uint8_t AY_ST_EN_REG        : 1;
                uint8_t AX_ST_EN_REG        : 1;
                uint8_t RSVD                : 3;
            } bits;
            uint8_t byte;
        } ACCEL_CONFIG_2;

        union {
            struct {
                uint8_t EXT_SYNC_SET        : 4;
                uint8_t WOF_EDGE_INT        : 1;
                uint8_t WOF_DEGLITCH_EN     : 1;
                uint8_t RSVD                : 1;
                uint8_t DELAY_TIME_EN       : 1;
            } bits;
            uint8_t byte;
        } FSYNC_CONFIG;

        union {
            struct {
                uint8_t TEMP_DLPFCFG        : 3;
                uint8_t RSVD                : 5;
            } bits;
            uint8_t byte;
        } TEMP_CONFIG;

        union {
            struct {
                uint8_t REG_LP_DMP_EN       : 1;
                uint8_t RSVD                : 7;
            } bits;
            uint8_t byte;
        } MOD_CTRL_USR;

        union {
            struct {
                uint8_t RSVD0               : 4;
                uint8_t USER_BANK           : 2;
                uint8_t RSVD1               : 2;
            } bits;
            uint8_t byte;
        } REG_BANK_SEL;

    } bytes;
    uint8_t arr[ICM20948_BANK2_REG_COUNT];
} icm20948_reg_bank_2_t;

typedef union {
    struct {
        union {
            struct {
                uint8_t I2C_MST_ODR_CONFIG  : 4;
                uint8_t RSVD                : 4;
            } bits;
            uint8_t byte;
        } I2C_MST_ODR_CONFIG;

        union {
            struct {
                uint8_t I2C_MST_CLK         : 4;
                uint8_t I2C_MST_P_NSR       : 1;
                uint8_t RSVD                : 2;
                uint8_t MULT_MST_EN         : 1;
            } bits;
            uint8_t byte;
        } ISC_MST_CTRL;

        union {
            struct {
                uint8_t I2C_SLV0_DELAY_EN   : 1;
                uint8_t I2C_SLV1_DELAY_EN   : 1;
                uint8_t I2C_SLV2_DELAY_EN   : 1;
                uint8_t I2C_SLV3_DELAY_EN   : 1;
                uint8_t I2C_SLV4_DELAY_EN   : 1;
                uint8_t RSVD                : 2;
                uint8_t DELAY_ES_SHADOW     : 1;
            } bits;
            uint8_t byte;
        } I2C_MST_DELAY_CTRL;

        // Slave 0
        union {
            struct {
                uint8_t I2C_ID_0            : 7;
                uint8_t I2C_SLV0_RNW        : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV0_ADDR;

        uint8_t I2C_SLV0_REG;

        union {
            struct {
                uint8_t I2C_SLV0_LENG       : 4;
                uint8_t I2C_SLV0_GRP        : 1;
                uint8_t I2C_SLV0_REG_DIS    : 1;
                uint8_t I2C_SLV0_BYTE_SW    : 1;
                uint8_t I2C_SLV0_EN         : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV0_CTRL;

        uint8_t I2C_SLV0_DO;

        // Slave 1
        union {
            struct {
                uint8_t I2C_ID_0            : 7;
                uint8_t I2C_SLV0_RNW        : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV1_ADDR;

        uint8_t I2C_SLV1_REG;

        union {
            struct {
                uint8_t I2C_SLV1_LENG       : 4;
                uint8_t I2C_SLV1_GRP        : 1;
                uint8_t I2C_SLV1_REG_DIS    : 1;
                uint8_t I2C_SLV1_BYTE_SW    : 1;
                uint8_t I2C_SLV1_EN         : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV1_CTRL;

        uint8_t I2C_SLV1_DO;

        // Slave 2
        union {
            struct {
                uint8_t I2C_ID_2            : 7;
                uint8_t I2C_SLV2_RNW        : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV2_ADDR;

        uint8_t I2C_SLV2_REG;

        union {
            struct {
                uint8_t I2C_SLV2_LENG       : 4;
                uint8_t I2C_SLV2_GRP        : 1;
                uint8_t I2C_SLV2_REG_DIS    : 1;
                uint8_t I2C_SLV2_BYTE_SW    : 1;
                uint8_t I2C_SLV2_EN         : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV2_CTRL;

        uint8_t I2C_SLV2_DO;

        // Slave 3
        union {
            struct {
                uint8_t I2C_ID_3            : 7;
                uint8_t I2C_SLV3_RNW        : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV3_ADDR;

        uint8_t I2C_SLV3_REG;

        union {
            struct {
                uint8_t I2C_SLV3_LENG       : 4;
                uint8_t I2C_SLV3_GRP        : 1;
                uint8_t I2C_SLV3_REG_DIS    : 1;
                uint8_t I2C_SLV3_BYTE_SW    : 1;
                uint8_t I2C_SLV3_EN         : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV3_CTRL;

        uint8_t I2C_SLV3_DO;

        // Slave 4
        union {
            struct {
                uint8_t I2C_ID_4            : 7;
                uint8_t I2C_SLV4_RNW        : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV4_ADDR;

        uint8_t I2C_SLV4_REG;

        union {
            struct {
                uint8_t I2C_SLV4_LENG       : 4;
                uint8_t I2C_SLV4_GRP        : 1;
                uint8_t I2C_SLV4_REG_DIS    : 1;
                uint8_t I2C_SLV4_BYTE_SW    : 1;
                uint8_t I2C_SLV4_EN         : 1;
            } bits;
            uint8_t byte;
        } I2C_SLV4_CTRL;

        uint8_t I2C_SLV4_DO;

        union {
            struct {
                uint8_t RSVD0               : 4;
                uint8_t USER_BANK           : 2;
                uint8_t RSVD1               : 2;
            } bits;
            uint8_t byte;
        } REG_BANK_SEL;

    } bytes;
    uint8_t arr[ICM20948_BANK3_REG_COUNT];
} icm20948_reg_bank_3_t;

typedef struct {
    icm20948_reg_bank_0_t bank0;
    icm20948_reg_bank_1_t bank1;
    icm20948_reg_bank_2_t bank2;
    icm20948_reg_bank_3_t bank3;
    icm20948_reg_bank_sel_t reg_bank_sel;
} icm20948_usr_bank_t;

typedef struct {
    icm20948_read_fptr_t read;
    icm20948_write_fptr_t write;
    icm20948_delay_us_fptr_t delay_us;
} icm20948_dev_intf_t;

typedef struct {
    icm20948_dev_intf_t intf;
    icm20948_usr_bank_t usr_bank;
} icm20948_dev_t;

#endif // _ICM20948_H_

#ifdef __cplusplus
}
#endif