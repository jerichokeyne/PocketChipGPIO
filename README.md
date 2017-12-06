## Introduction
If you've used a PocketCHIP, you might be like me and wanted to figure out how to use the GPIO pins on the top.

You might've even gone on the documentation and found out that there's two options, either a python API or the filesystem.

I wanted to be able to use C++ so I figured I would make a C++ API.

## Including
```c++
#include "gpio.cpp"
```

## Primary Functions

Function                            | Description
------------------------------------|----------------------------------------------------------------
int getPIN(int offset)              | Returns the correct pin number for the chip based on the offset)
void setupPIN(int pin, string mode) | Sets up the pin for either "in" or "out" mode
void releasePIN(int pin)            | Releases/unexports the pin
void writePIN(int pin, bool state)  | Writes state to pin (true = on, false = off)
bool readPIN(int pin)               | Reads pin's current state (true = on, false = off)

## Common Offsets
Here are some common offsets you might want to use

| PocketCHIP name | CHIP name | Offset |
| ----------------|-----------|------- |
| XIO-P0          | XIO-P0    | 0      | 
| XIO-P1          | XIO-P1    | 1      |
| GPIO1           | XIO-P2    | 2      |
| GPIO2           | XIO-P3    | 3      |
| GPIO3           | XIO-P4    | 4      |
| GPIO4           | XIO-P5    | 5      |
| GPIO5           | XIO-P6    | 6      |
| GPIO6           | XIO-P7    | 7      |

[This page has a list of all the gpio pins](https://github.com/xtacocorex/CHIP_IO)
