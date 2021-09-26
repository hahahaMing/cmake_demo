#include "tools.hpp"

using namespace std;

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int rst_val = 0, rst_len = 1;
        vector<int> rcd(n, 1);
        for (int i = 1; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && rcd[j] > tmp) {
                    tmp = rcd[j];
                }
            }
            rcd[i] = tmp + 1;
            if (rcd[i] > rst_len) {
                rst_len = rcd[i];
                rst_val = nums[i];
            }
        }
        //倒推
        vector<int> rst = {};
        for (int i = n-1; i >= 0; i--) {
            if (rst_val % nums[i] == 0 && rst_len==rcd[i]) {
                rst.push_back(nums[i]);
                rst_val = nums[i];
                rst_len--;
            }
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> v, v2;
    for (int i = 1; i <= 1000; i++)
        v2.push_back(i);
    v = {1};
    tools::printVectorInt(slt.largestDivisibleSubset(v));    
    v = {1, 2, 3};
    tools::printVectorInt(slt.largestDivisibleSubset(v));
    v = {1, 2, 4, 8};
    tools::printVectorInt(slt.largestDivisibleSubset(v));
    v = {4,8,10,240};
    tools::printVectorInt(slt.largestDivisibleSubset(v));
    tools::printVectorInt(slt.largestDivisibleSubset(v2));
    return 0;
}
