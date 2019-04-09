TODO List
=========

NGOS:

- Simplify build option taking in Makefiles
- Add tests for structure sizes
- Complete with interruptions
- Implement graphics for kernel
- Per CPU?
- Initialization via multiple CPU cores

- Add option for optimization level `-O2 | -O3`
- Add option to disable inline
- Add stack protector to build
- All resources for one application (Turbo mode)



Code verifier:

- Verify for `0x[0-9]*[a-f]`
- Verify for void functions
- Verify for headers in assembler



Docs verifier:

- Verify for Project structure
- Verify for Configuration
- Verify for How to Build
- Verify for Scripts
- Verify for amount of links (amount of tools/libraries/applications)



Tests verifier:

- Verify for structure sizes



Code generator:

- Generate documentation for applications



GDB Debug:

- Rewrite tool
- Load memory page by page



Assembler optimizer:

- Implement tool
- Auto inlining
- Value prediction
- Try to remove code if we know the results



C++ headers optimizer:

- Implement tool
- Investigate C++ headers hierarchy
- Collapse C++ headers hierarchy for each C++ file
- Iterate over all possible options for header inclusions
- Try to delete some inclusions if it's not harmful for build



USB Boot Maker:

- Request servers for installer latest version
- Store delays
- Download installer from server with the lowest delay
- Burn installer on USB
- Verify code



MathZip:

- Implement tool
- Try to think how we can produce original file with some magic function



webapps:

- Ignore duplicate version
- Replicate apps to registered server
- Create web site



Common:

- Write documentation
- Jenkins
- Bug tracker
