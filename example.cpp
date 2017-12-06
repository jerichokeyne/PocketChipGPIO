#include "gpio.cpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	int pin = getPIN(2);
	int pinR = getPIN(3);
	int state;
	setupPIN(pin, "out");
	setupPIN(pinR, "in");

	cout << "Flashing LED between GPIO1 and 3 volts\n";
	for (int i = 0; i < 9; i++) {
		writePIN(pin, 0);
		cout << "LED on\n";
		sleep(1);
		writePIN(pin, 1);
		cout << "LED off\n";
		sleep(1);
	}

	cout << "Now reading from GPIO2\n";
	for (int i = 0; i < 10; i++) {
		state = readPIN(pinR);
		cout << state << endl;
		sleep(1);
	}

	releasePIN(pin);
	releasePIN(pinR);
	return 0;
}
