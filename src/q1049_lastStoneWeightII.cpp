/*
 * @Author: your name
 * @Date: 2021-06-08 10:17:13
 * @LastEditTime: 2021-06-08 14:17:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1049_lastStoneWeightII.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0), bag = sum / 2;
        int n = stones.size();
        vector<vector<int>> dp(
            n, vector<int>(bag + 1, 0)); //表示在第i位前能否凑出j
        dp[0][0] = 1;
        if (stones[0] <= bag)
            dp[0][stones[0]] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= bag; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - stones[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i]];
                }
            }
        }
        for (int j = bag; j >= 0; --j) {
            if (dp.back()[j])
                return sum - 2 * j;
        }
        return 0;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
