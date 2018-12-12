NGOS
====

0.7.4. Test verifier
--------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/test_verifier/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

Test verifier tool is checking that all declared functions has tests for testing such functions.

Please fill your source code with the tests as much as possible. Use comment `// TEST: NO` if it's not needed to provide tests for some functions.

### Usage

```sh
test_verifier PATH
    * PATH - path to folder
```

### How to ...

Test verifier tool will check all C++ headers in specified PATH argument for the declared functions.<br/>
It will inform you if there is no tests for declared functions.
