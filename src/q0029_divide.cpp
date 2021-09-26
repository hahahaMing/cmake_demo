/*
 * @Author: your name
 * @Date: 2021-09-06 14:47:10
 * @LastEditTime: 2021-09-06 15:17:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0029_divide.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
        // 定义符号
        bool pos = true;
        if (dividend < 0) {

            pos = !pos;
        } else {
            dividend = -dividend;
        }
        if (divisor < 0) {

            pos = !pos;
        } else {
            divisor = -divisor;
        }
        // 建立数组
        vector<vector<int>> rcd = {{divisor, -1}};
        while (rcd.back()[0] > dividend && rcd.back()[0] > -1073741824) {
            rcd.push_back(
                {rcd.back()[0] + rcd.back()[0], rcd.back()[1] + rcd.back()[1]});
        }
        int rst = 0;
        for (int i = rcd.size() - 1; i >= 0; --i) {
            while (dividend <= rcd[i][0]) {
                dividend -= rcd[i][0];
                rst += rcd[i][1];
            }
        }
        // 开始减，减到小于被除数为止
        if (pos) {
            if (rst == -2147483648)
                return 2147483647;
            rst = -rst;
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    cout<<slt.divide(2147483647,3);
    return 0;
}
