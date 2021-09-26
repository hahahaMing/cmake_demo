/*
 * @Author: your name
 * @Date: 2021-05-25 16:56:01
 * @LastEditTime: 2021-05-25 17:21:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1787_minChanges.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int minChanges(vector<int> &nums, int k) {
        //按循环位置放置数字
        vector<unordered_map<int, int>> rcd(k);
        vector<int> lens(k, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (rcd[i % k].find(nums[i]) != rcd[i % k].end()) {
                rcd[i % k][nums[i]] = 1;
            } else {
                rcd[i % k][nums[i]]++;
            }
            lens[i % k]++;
        }
        vector<int> most_freq(k);
        int min_gx = 2 * n / k;
        int xor_sum = 0;
        int rst = 0;
        for (int i = 0; i < k; ++i) {
            int max_frec_x = nums[i];
            for (auto it : rcd[i]) {
                if (it.second > rcd[i][max_frec_x]) {
                    max_frec_x = it.first;
                }
            }
            xor_sum ^= max_frec_x;
            rst += rcd[i][max_frec_x];
        }
        for (int i = 0; i < k; ++i) {
            if (lens[i] + rcd[i][most_freq[i]] -
                    rcd[i][xor_sum ^ most_freq[i]] <
                min_gx) {
                min_gx = lens[i] + rcd[i][most_freq[i]] -
                    rcd[i][xor_sum ^ most_freq[i]];
            }
        }
        return rst - min_gx;

    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
