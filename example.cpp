#include "gpio.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    GPIO::PIN pin_write;
    GPIO::PIN pin_read;
    int state;

    pin_write.setup(2, "out");
    pin_read.setup(3, "in");

    cout << "If nothing happens, check your wiring and run as root\n";

    cout << "Flashing LED between GPIO1 and 3 volts\n";
    for (int i = 0; i < 9; i++) {
        pin_write.writePIN(0); // Set pin_write low
        cout << "LED on\n";
        sleep(1);
        pin_write.writePIN(1); // Set pin_write high
        cout << "LED off\n";
        sleep(1);
    }

    cout << "Now reading from GPIO2\n";
    for (int i = 0; i < 10; i++) {
        state = pin_read.readPIN(); // This will read the state of the pin as a boolean
        cout << state << endl;
        sleep(1);
    }

    pin_write.releasePIN(); // This tells the system that these pins are no longer being used
    pin_read.releasePIN();
    return 0;
}
