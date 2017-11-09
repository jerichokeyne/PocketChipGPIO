#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>

using namespace std;
///
// This function will get all of the files in a directory (dir) and return them in an array (files)
///
int getDir (string dir, vector<string> &files) {
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		cout << "Error (" << errno << ") opening " << dir << endl;
		return errno;
	}

	while (( dirp = readdir(dp)) != NULL) {
		files.push_back(string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

///
// This function will take a generic pin number (offset) and find the specific pin number for this chip (base+offset)
///
int getPIN(int offset) {
	int base;
	string dir = string("/sys/class/gpio");
	vector<string> files = vector<string>();

	getDir(dir,files);
	ifstream labelFile;
	for (unsigned int i = 0; i < files.size(); i++) {
		stringstream labelFileName;
		labelFileName << "/sys/class/gpio/" << files[i] << "/label";
		labelFile.open(labelFileName.str().c_str());
		if (labelFile.is_open()) {
			string label;
			labelFile >> label;
			if (label == "pcf8574a") {
				stringstream baseFileName;
				baseFileName << "/sys/class/gpio/" << files[i] << "/base";
				ifstream baseFile(baseFileName.str().c_str());
				baseFile >> base;
				return base+offset;
			}
		}
		labelFile.close();
	}
}

///
// This function will take a pin (pin) and enable it and set it to the correct mode (mode, "out" or "in")
///
void setupPIN(int pin, string mode) {
	ofstream exportFile("/sys/class/gpio/export");
	exportFile << pin;
	exportFile.close();
	stringstream dFileName;
	dFileName << "/sys/class/gpio/gpio" << pin << "/direction";
	ofstream directionFile(dFileName.str().c_str());
	directionFile << "out";
	directionFile.close();
}	

/// 
// This function will take the pin (pin) and set it to a value (state)
///
void writePIN(int pin, int state) {
	stringstream vFileName;
	vFileName << "/sys/class/gpio/gpio" << pin << "/value";
	ofstream valueFile(vFileName.str().c_str());
	if (state == 1) {
		valueFile << state << "\0";
		cout << "LED off\n";
	} else if (state == 0) {
		valueFile << state << "\0";
		cout << "LED on\n";
	}
	valueFile.close();
}

int readPIN(int pin) {
	stringstream vFileName;
	vFileName << "/sys/class/gpio/gpio" << pin << "/value";
	ifstream valueFile(vFileName.str().c_str());
	int state;
	valueFile >> state;
	valueFile.close();
	return state;
}
/*
///
// This function flashed pin 2 on and off 10 times
///
int main() {
	int pin = getPin(2); // GPIO1 on PocketChip
	cout << "Flash LEDs by Jericho Keyne" << endl;
	cout << "This program should blink an LED connteced between 3v and GPIO1/XIO-P2" << endl;
	cout << "If the LED does not blink check your connections and try running as root" << endl;
	setupPin(pin, "out");
	for (int i = 0; i < 9; i++) {
		writeLED(pin, 0);
		sleep(1);
		writeLED(pin, 1);
		sleep(1);
	}
	return 0;
}
*/
