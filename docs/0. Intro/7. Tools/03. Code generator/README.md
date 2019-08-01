NGOS
====

0.7.03. Code generator
----------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/code_generator/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

Code generator tool is a very nice tool that let you to save your time.<br/>
It can be used to generate some files that could be difficult to create manually.

Code generation is highly required for realtime functions since we need to guarantee expected accuracy for the different values of [NGOS_BUILD_REALTIME_RAM_USAGE](../../3.%20Configuration/README.md#-----------ngos_build_realtime_ram_usage-----------) configuration parameter.

### Usage

```sh
code_generator PATH
    * PATH - path to NGOS project folder
```

### How to ...

Code generator tool expecting that [ngos.files](../../../../ngos.files) file existing in the specified PATH.

If it exists it will start generate files in several threads.
