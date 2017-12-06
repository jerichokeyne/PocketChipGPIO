## Introduction
If you've used a PocketCHIP, you might be like me and wanted to figure out how to use the GPIO pins on the top.

You might've even gone on the documentation and found out that there's two options, either a python API or the filesystem.

I wanted to be able to use C++ so I figured I would make a C++ API.

## Including
```c++
#include "gpio.cpp"
```

## Primary Functions
Function							| Description
------------------------------------|----------------------------------------------------------------
int getPIN(int offset)		        | Returns the correct pin number for the chip based on the offset)
void setupPIN(int pin, string mode) | Sets up the pin for either "in" or "out" mode
void writePIN(int pin, int state)   | Writes state to pin
int readPIN(int pin)                | Reads pin's current state
