TODO List
=========

NGOS:

- Refactor
- Use global variable for GUID
- Replace zeros with nullptr
- Bool to string
- Centralize CPUID like in edk2
- Check for asm volatile
- Make global GET_UNALIGNED_LE32 and PUT_UNALIGNED_LE32 for all sizes
- Encapsulate flag types into struct
- Check for mouse wheel on table widget
- Convert FLAGS_TO_STRING to template
- Move include to shared/common
- Check for log includes: common or early?
- Convert installer to UEFI application
- Make kernelbase just for kernel
- Check where we can use enumToString and flagToString
- Add SecureBoot support: https://m.habr.com/ru/post/273497/

- Complete with interruptions
- Implement boot screen for kernel
- Per CPU?
- Initialization via multiple CPU cores

- Add option to provide timestamp for logs
- Add option to log in serial only/UDP only/All
- Add option to log with UDP
- Add option to disable inline
- Add stack protector to build

- All resources for one application (Turbo mode)



Bootloader:

- Custom arguments
- Check for last started OS on real hardware



Code verifier:

- Verify for void functions
- Verify for headers in assembler
- Verify for function asserts
- Verify for log alignment
- Verify for amount of arguments in log
- Verify for asserts alignment
- Upgrade verifier for trace arguments (Check format with the types)
- Verify for spaces in `{ 5, 4 }`



Docs verifier:

- Verify for Project structure
- Verify for Configuration
- Verify for How to Build
- Verify for Scripts
- Verify for amount of links (amount of tools/libraries/applications)



Tests verifier:

- Verify code



Code generator:

- Generate documentation for applications



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

- Verify code



USB Boot Maker:

- Verify code



MathZip:

- Implement tool
- Try to think how we can produce original file with some magic function



SpecVerifier:

- Implement tool
- Check the code with several specifications like SMBIOS, TCP ...



webapps:

- Replicate apps to registered server
- Create web site



Generic:

- Write documentation
- Coverity
- Klocwork
- Valgrind
- Jenkins
- Bug tracker (Redmine)
