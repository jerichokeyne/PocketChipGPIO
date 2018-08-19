## Introduction
If you've used a PocketCHIP, you might be like me and wanted to figure out how to use the GPIO pins on the top.

You might have even gone on the documentation and found out that there's two options, either a python API or the file system API.

I wanted to be able to use C++ so I figured I would make a C++ API.

## Including
```c++
#include "gpio.h"
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

## Note
I will likely not be working on the project anymore, as while I was testing out the example code I accidentally connect the 5V and 3.3V lines on my only PocketCHIP, this seems to have completely fried the CHIP. As such I can no longer do any testing of any code. Feel free to contribute if you would like to see more features added to this. 
