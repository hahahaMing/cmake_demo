/*
 * @Author: your name
 * @Date: 2021-06-12 16:10:35
 * @LastEditTime: 2021-06-13 11:49:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1449_largestNumber.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }
        int l = firstPlayer - 1, m = secondPlayer - firstPlayer - 1,
            r = n - secondPlayer;
        if (r == l)
            return {1, 1};
        if (r < l) {
            swap(l, r);
        }
        int srst = 0, lrst = 0;
        int len = n;
        while (l < r) {
            r--;
            int change = len / 2;
            change -= 2;
            if (l + m + 2 == len / 2 + 1 && len % 2 == 1) {
                change += 1;
            } else if (l + m + 2 > len / 2) {
                m--;
            } else {
                r--;
            }
            if (r == l && change % 2 != 0 && m == 0) {
                r -= change / 2;
                l -= change / 2 + 1;
            } else {
                if (change >= r - l) {
                    l = r;
                } else {
                    r -= change;
                }
            }

            len -= len / 2;
            srst++;
        }
        l = firstPlayer - 1, m = secondPlayer - firstPlayer - 1,
        r = n - secondPlayer;
        if (r < l) {
            swap(l, r);
        }
        len = n;
        while (l < r) {
            r--;
            int change = len / 2;
            change -= 2;
            if (l + m + 2 == len / 2 + 1 && len % 2 == 1) {
                change += 1;
            } else if (l + m + 2 > len / 2) {
                m--;
            } else {
                r--;
            }
            while (l > 0 && change > 0) {
                l--;
                change--;
            }
            while (m > 0 && change > 0) {
                m--;
                change--;
            }
            while (r > 0 && change > 0) {
                r--;
                change--;
            }
            len -= len / 2;
            lrst++;
        }
        return {srst + 1, lrst + 1};
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    // tools::printVectorInt(slt.earliestAndLatest(5, 2, 3));
    // tools::printVectorInt(slt.earliestAndLatest(5, 1, 3));
    // tools::printVectorInt(slt.earliestAndLatest(4, 1, 2));
    tools::printVectorInt(slt.earliestAndLatest(11, 2, 4));

    return 0;
}
