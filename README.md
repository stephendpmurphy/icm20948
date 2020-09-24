# ICM-20948 9-Axis MEMS Motion Tracking Sensor Driver
[![Release](https://img.shields.io/github/release/stephendpmurphy/icm20948.svg?style=flat-square)](https://github.com/stephendpmurphy/icm20948/releases/latest)
![CI](https://github.com/stephendpmurphy/icm20948/workflows/CI/badge.svg)

</br>
C Driver for the IC-20948 9-Axis Telemetry sensor. This driver can be included directly into a developers source or a static library can be created and then linked against.


## Retrieving the Source
The source is located on Github and can be either downloaded and included directly into a developers source directoriy or the developer can add this repo as a submodule into their source (The latter is the preferred method).

To include the driver as a git submodule
```bash
$ cd ./${DIR_WHERE_YOU_WANT_TO_ADD_THE_MODULE}
$ git submodule add https://github.com/stephendpmurphy/icm20948.git
```

## Integration
#### Creating & Linking against a static library
To create a static library to link against, exectue the following commands.
```bash
$ mkdir build && cd build
$ cmake ..
$ make
```
The output library (lib_icm20948.a) can be found in the *lib/* folder. Link against this file, and include the icm20948_api.h header file into your source include directories.
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
// TO-DO
