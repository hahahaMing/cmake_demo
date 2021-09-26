/*
 * @Author: your name
 * @Date: 2021-06-22 16:18:00
 * @LastEditTime: 2021-06-22 16:20:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\offer0038_permutation.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {

  public:
    vector<string> permutation(string s) {
        len = s.size();
        rcd = vector<int>(26, 0);
        for (char c : s) {
            rcd[c - 'a']++;
        }
        rst = {};
        dfs("", -1);
        return rst;
    }

  private:
    vector<string> rst;
    vector<int> rcd;
    int len;
    void dfs(string ss, int noi) {
        if (ss.size() == len) {
            rst.push_back(ss);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (i == noi)
                continue;
            for (int j = 1; j <= rcd[i]; ++j) {
                rcd[i] -= j;
                string sss = ss;
                for (int k = 0; k < j; k++) {
                    sss += 'a' + i;
                }
                dfs(sss, i);
                rcd[i] += j;
            }
        }
    }
};
// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;

    return 0;
}
