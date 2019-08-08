TODO List
=========

NGOS:

- Refactor

- Complete with interruptions
- Implement boot screen for kernel
- Per CPU?
- Initialization via multiple CPU cores

- Add option to disable inline
- Add stack protector to build

- All resources for one application (Turbo mode)



Bootloader:

- Implement GUI
- Find all OS and create buttons
- Find all tools and create buttons
- Start external application



Code verifier:

- Verify for void functions
- Verify for headers in assembler
- Verify for function asserts
- Verify for log alignment



Docs verifier:

- Verify for Project structure
- Verify for Configuration
- Verify for How to Build
- Verify for Scripts
- Verify for amount of links (amount of tools/libraries/applications)



Tests verifier:

- ...



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



QMake:

- Implement tool
- Move all projects to Qt pro files
- Compile projects with own qmake



USB Boot Maker:

- Verify code



MathZip:

- Implement tool
- Try to think how we can produce original file with some magic function



webapps:

- Replicate apps to registered server
- Create web site



Generic:

- Write documentation
- Jenkins
- Bug tracker
