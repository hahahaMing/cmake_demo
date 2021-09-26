/*
 * @Author: your name
 * @Date: 2021-05-24 09:15:05
 * @LastEditTime: 2021-05-24 10:19:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0664_strangePrinter.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {

  public:
    int strangePrinter(string s) {
        //简化s
        string ss;
        char last = '0';
        for (char c : s) {
            if (c != last) {
                ss.push_back(c);
                last = c;
            }
        }
        swap(s, ss);
        cout << 0 << s << endl;

        int n = s.size();
        vector<vector<int>> rcd(n, vector<int>(n, 0));
        for (int dif = 0; dif < n; ++dif) {
            for (int i = 0; i < n - dif; ++i) {
                int j = i + dif;
                if (i == j) {
                    rcd[i][j] = 1;
                    continue;
                }
                int tmp =
                    s[i] == s[j] ? rcd[i + 1][j - 1] + 1 : rcd[i][j - 1] + 1;
                for (int k = i + 1; k < j; ++k) {
                    if (s[k] == s[j]) {
                        tmp = min(tmp, rcd[i][k - 1] + 1 + rcd[k + 1][j - 1]);
                    }
                }
                rcd[i][j] = tmp;
            }
        }
        tools::print2DVector(rcd);
        return rcd[0][n - 1];
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    string s;
    s = "bacdadacbdb";
    cout << s << endl;
    cout << slt.strangePrinter(s) << endl;

    return 0;
}
