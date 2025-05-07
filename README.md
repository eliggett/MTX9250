# MTX9250
Motorola MTX9250 CPS Patch for 900 MHz Ham Radio usage

# What this does
This C code patches the CPS exe, typically named `cps_95nt.exe`, to extend the limits of the 900 MHz MTX9250 to cover the 927 MHz Ham Radio band. You can compile the code in a modern linux environment and probably also on windows (untested). 

# How to compile
```gcc patcher.c -o patcher```

# How to run
```./patcher cps_95nt.exe cps_patched.exe```

# Typical program output:
```
./patcher cps_95nt.exe patchedfile.exe
Searching for byte pattern 94 28 BB 37 to replace with D4 10 68 35
Original file will not be modified. Patched version will be saved as 'patchedfile.exe'
Replacing pattern at offset: 0x19E74
Replacing pattern at offset: 0x1A93B
Replacing pattern at offset: 0x891E5
Replacing pattern at offset: 0x8D188
Replacing pattern at offset: 0x1FFAD4
Replacing pattern at offset: 0x1FFB08
Replacing pattern at offset: 0x1FFD44
Replacing pattern at offset: 0x1FFD78
Replacing pattern at offset: 0x2000EC
Replacing pattern at offset: 0x200120
Replacing pattern at offset: 0x200154
Replacing pattern at offset: 0x200188
Replacing pattern at offset: 0x2001BC
Replacing pattern at offset: 0x2001F0

Total replacements made: 14
Patched file saved as 'patchedfile.exe'
```

# Credits:
This is based on the [a post by N9LLO](https://batboard.batlabs.com/viewtopic.php?f=3&t=31214). 

# Notes:
I have not tested this on every version of CPS. But it should work to patch around any similar versions using the same encoding for frequency limits. 
