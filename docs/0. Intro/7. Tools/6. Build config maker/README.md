NGOS
====

0.7.6. Build config maker
-------------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/build_config_maker/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

Build config maker is command line tool for editing [include/buildconfig.h](../../../../include/buildconfig.h) file.

### Usage

```sh
build_config_maker PATH_TO_BUILDCONFIG_H [--reset] {BUILD_PARAMETER=VALUE}
    * PATH_TO_BUILDCONFIG_H - path to buildconfig.h file
    * BUILD_PARAMETER       - One of the parameters from buildconfig.h file
    * VALUE                 - What value should be assigned to the BUILD_PARAMETER

    --reset - Reset all parameters to their defaults
```

### How to ...

Build config maker will update each specified parameter to it's value in PATH_TO_BUILDCONFIG_H file.<br/>
Please check the [list of available parameters](../../3.%20Configuration/README.md#-general-parameters-)
