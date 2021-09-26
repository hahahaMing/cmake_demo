/*
 * @Author: your name
 * @Date: 2021-06-07 12:43:21
 * @LastEditTime: 2021-06-07 14:31:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0494_findTargetSumWays.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), -target);
        if (target * 2 + sum < 0 || sum < 0)
            return 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp; //存某些数字相反后总和比原来小多少
        mp[sum] = 0;
        mp[0] = 1;
        for (int x : nums) {
            if (x * 2 > sum)
                break;
            queue<pair<int, int>> que;
            for (auto &pr : mp) {
                int tmp = pr.first + x * 2;
                if (tmp <= sum) {
                    que.push({tmp, mp[pr.first]});
                }
            }
            while (!que.empty()) {
                if (mp.find(que.front().first) == mp.end()) {
                    mp[que.front().first] = que.front().second;
                } else {
                    mp[que.front().first] += que.front().second;
                }
                que.pop();
            }
        }
        return mp[sum];
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> nums;
    nums = {1, 2, 1};
    cout << slt.findTargetSumWays(nums, 0);

    return 0;
}
