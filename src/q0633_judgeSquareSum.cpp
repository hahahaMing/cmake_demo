#include "tools.hpp"

using namespace std;

class Solution {
  public:
    bool judgeSquareSum(int c) {
        //硬搜索
        int l = 1, r = int(sqrt(c));
        for (int i = l; i <= r; ++i) {
            if (pow(i, 2) + pow(int(sqrt(c - i * i)), 2) == c) {
                printf("%d,%d,%d\n", i, int(sqrt(c - i * i)), c);
                return true;
            }
        }
        return false;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    for (int i = 1; i < 200000; i++) {
        slt.judgeSquareSum(i);
    }

    cout << slt.judgeSquareSum(13) << endl;
    return 0;
}
