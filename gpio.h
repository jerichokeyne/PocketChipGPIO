#include <string>
#include <vector>

using namespace std;

namespace GPIO {
    int getDir (string dir, vector<string> &files);
    class PIN {
        public:
        void setup(int offset, string mode);
        void releasePIN();
        void writePIN(bool state);
        bool readPIN();

        private:
        int getPIN(int offset);
        void setupPIN(string mode);
        int pin_number;
    };
}
