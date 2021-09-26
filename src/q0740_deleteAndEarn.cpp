#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> rcd(n + 1, 0);
        vector<int> dp(n + 1, 0);
        for (int x : nums)
            rcd[x]++;
        int rst = 0;
        for (int i = 1; i < n + 1; ++i) {
            if (i < 3) {
                dp[i] = i * rcd[i];
            } else {
                dp[i] = i * rcd[i] + max(dp[i - 2], dp[i - 3]);
            }
            if (dp[i] > rst)
                rst = dp[i];
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    return 0;
}
