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
	/*for (int i = 0; i < 9; i++) {
		writePIN(pin, 0);
		sleep(1);
		writePIN(pin, 1);
		sleep(1);
	}*/
	while (true) {
		state = readPIN(pinR);
		cout << state << endl;
		sleep(1);
	}
	return 0;
}
