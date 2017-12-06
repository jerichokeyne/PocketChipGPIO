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
	directionFile << mode;
	directionFile.close();
}	

///
// This function will release pin (pin)
///
void releasePIN(int pin) {
	ofstream unexportFile("/sys/class/gpio/unexport");
	unexportFile << pin;
	unexportFile.close();
}

/// 
// This function will take the pin (pin) and set it to a value (state)
///
void writePIN(int pin, bool state) {
	stringstream vFileName;
	vFileName << "/sys/class/gpio/gpio" << pin << "/value";
	ofstream valueFile(vFileName.str().c_str());
	valueFile << (int)state << "\0";
	valueFile.close();
}

///
// This function will take the pin (pin) and return its state
///
bool readPIN(int pin) {
	stringstream vFileName;
	vFileName << "/sys/class/gpio/gpio" << pin << "/value";
	ifstream valueFile(vFileName.str().c_str());
	bool state;
	valueFile >> state;
	valueFile.close();
	return state;
}
