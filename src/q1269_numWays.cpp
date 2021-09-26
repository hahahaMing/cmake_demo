#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int numWays(int steps, int arrLen) {
        vector<int> dp(min(arrLen, steps + 1), 0);
        dp[0] = 1;
        for (int i = 0; i < steps; ++i) {
            int a = 0, b = dp[0], c = arrLen > 1 ? dp[1] : 0;
            for (int j = 0; j < arrLen; ++j) {
                if (a == 0 && b == 0 && c == 0)
                    break;
                dp[j] = (a + b) % 1000000007 + c;
                dp[j] %= 1000000007;
                a = b;
                b = c;
                c = j + 2 < arrLen ? dp[j + 2] : 0;
            }
        }
        return dp[0];
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
