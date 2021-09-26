#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        vector<int> rcd(32, 0);
        for (int x : nums) {
            for (int i = 0; i < 32; ++i) {
                int a = 1 << i;
                int b = x & a;
                if (b != 0)
                    rcd[i]++;
                if (rcd[i] == 3)
                    rcd[i] = 0;
            }
        }
        int rst = 0;
        for (int i = 0; i < 32; ++i) {
            rst += (rcd[i] << i);
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> nums;
    nums = {2, 2, 3, 2};
    cout << slt.singleNumber(nums) << endl;
    return 0;
}
