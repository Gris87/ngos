TODO List
=========

NGOS:

- Replace char with char8
- Complete with interruptions
- Implement boot screen for kernel
- Per CPU?
- Initialization via multiple CPU cores

- Add option for optimization level `-O2 | -O3`
- Add option to disable inline
- Add stack protector to build
- All resources for one application (Turbo mode)



Code verifier:

- Verify for void functions
- Verify for headers in assembler
- Verify for function asserts
- Verify for char type
- Verify for usage of COMMON_, EARLY_, EUFI_ in wrong location



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
- Extend C++ headers hierarchy for each C++ file
- Iterate over all possible options for header inclusions
- Try to delete some inclusions if it's not harmful for build



USB Boot Maker:

- Verify code



MathZip:

- Implement tool
- Try to think how we can produce original file with some magic function



webapps:

- Replicate apps to registered server
- Create web site



Common:

- Write documentation
- Jenkins
- Bug tracker
