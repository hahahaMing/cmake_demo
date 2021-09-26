#include "tools.hpp"

using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
        vector<int> change = {1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1};
        vector<string> strs = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                               "XL", "X",  "IX", "V",  "IV", "I"};
        string rst;
        for (int i = 0; i < 13; ++i) {
            if (num == 0)
                break;
            while (num >= change[i]) {
                rst += strs[i];
                num -= change[i];
            }
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
