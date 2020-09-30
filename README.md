# ICM-20948 9-Axis MEMS Motion Tracking Sensor Driver
[![Release](https://img.shields.io/github/release/stephendpmurphy/icm20948.svg?style=flat-square)](https://github.com/stephendpmurphy/icm20948/releases/latest)
![CI](https://github.com/stephendpmurphy/icm20948/workflows/CI/badge.svg)

</br>
C Driver for the IC-20948 9-Axis Telemetry sensor. This driver can be included directly into a developers source or a static library can be created and then linked against.
</br></br>
Development is done on the *dev* branch, and official releases can be found on the *master* branch. Releases will be made on a ~monthly basis assuming no driver breaking bugs are found. Otherwise, a fix will be released to *master* ASAP.

## Retrieving the Source
The source is located on Github and can be either downloaded and included directly into a developers source directoriy or the developer can add this repo as a submodule into their source (The latter is the preferred method).

To include the driver as a git submodule
```bash
$ cd ./${DIR_WHERE_YOU_WANT_TO_ADD_THE_MODULE}
$ git submodule add https://github.com/stephendpmurphy/icm20948.git
```

## Integration
#### Creating & Linking against a static library
To create a static library to link against, you must first source your build environment and ensure the **CC** environment variable is set to your desired toolchain. Once your cross-compiler is properly setup. Execute the following commands:
```bash
$ mkdir build && cd build
$ cmake ..
$ make
```
The output library (lib_icm20948.a) can be found in the **lib/** folder. Link against this file, and include the icm20948_api.h header file into your source include directories.
```c
#include "icm20948_api.h"
```

#### Adding to your own source/project
The other option for integrating the source into your project, is to include everything directly into your project
* Set your include directories to both the inc/ and src/ folders.
* Add the icm20948.c to your source list to be compiled.
* Include the API header file wherever you intended to implement the driver source.
```c
#include "icm20948_api.h"
```

## Implementing the driver
After following the integration steps above, you are ready to implement the driver and start retrieving telemetry data. An example [***main.c***](./template/main.c) can be found in the templates folder that shows how to implement the init, settings, and data retrieval API. Note that you will need to fill out your own ***usr_*** functions for reading, writing, and a uS delay. You can build the example ***main.c*** by first compiling the static lib following the steps in the ***"Creating & Linking against a static library"*** and then executing the following commands.
```bash
$ cd template
$ mkdir build && cd build
$ cmake ..
$ make
```
Example application and main can be found below:
```C
#include <stdint.h>
#include "icm20948_api.h"

int8_t usr_write(uint8_t addr, uint8_t *data, uint32_t len) {
    icm20948_return_code_t ret = ICM20948_RET_OK;
    
    // Assert the CS

    // Write the address

    // Write the data from the provided data buffer

    // De-assert the CS
    
    return ret;
}

int8_t usr_read(uint8_t addr, uint8_t *data, uint32_t len) {
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
        // Enable the gyro
        settings.gyro_en = ICM20948_GYRO_ENABLE;
        // Enable the accelerometer
        settings.accel_en = ICM20948_ACCEL_ENABLE;
        // Apply the settings
        ret = icm20948_applySettings(&settings);
    }

    while(1) {
        // Retireve the Gyro data and store it in our gyro_data struct
        ret |= icm20948_getGyroData(&gyro_data);
        // Retrieve the Accel data and store it in our accel_data struct
        ret |= icm20948_getAccelData(&accel_data);
    }

    return 0;
}
```

## License
MIT License
