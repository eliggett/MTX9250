# MTX9250
Motorola MTX9250 CPS Patch for 900 MHz Ham Radio usage

# What this does
This C code patches the CPS exe, typically named `cps_95nt.exe`, to extend the limits of the 900 MHz MTX9250 to cover the 927 MHz Ham Radio band. You can compile the code in a modern linux environment and probably also on windows (untested). 

# How to compile
```gcc patcher.c -o patcher```

# How to run
```./patcher cps_95nt.exe cps_patched.exe```

# Credits:
This is based on the [a post by N9LLO](https://batboard.batlabs.com/viewtopic.php?f=3&t=31214). 

# Notes:
I have not tested this on every version of CPS. But it should work to patch around any similar versions using the same encoding for frequency limits. 
