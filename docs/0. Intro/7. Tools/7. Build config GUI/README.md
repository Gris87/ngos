NGOS
====

0.7.7. Build config GUI
-----------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/build_config_gui/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

Build config GUI is special editor tool for [include/buildconfig.h](../../../../include/buildconfig.h) file.

### Usage

```sh
build_config_gui
```

### How to ...

This tool shall read [include/buildconfig.h](../../../../include/buildconfig.h) file and shall generate UI controls for each parameter according to provided meta information.

You can reset all parameters to their default values with reset button ![Reset button](../../../../tools/qt/build_config_gui/assets/images/reset.png).

Use reload button ![Reload button](../../../../tools/qt/build_config_gui/assets/images/reload.png) in order to restore parameter values from [include/buildconfig.h](../../../../include/buildconfig.h) file.

When you finish to configure parameters press save button ![Save button](../../../../tools/qt/build_config_gui/assets/images/save.png) to store them back to [include/buildconfig.h](../../../../include/buildconfig.h) file.
