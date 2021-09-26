/*
 * @Author: your name
 * @Date: 2021-06-19 09:29:32
 * @LastEditTime: 2021-06-19 09:38:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1239_.cpp
 */
#include "tools.hpp"

using namespace std;

#include <algorithm>
class Solution {
    vector<vector<int>> rcd;
    vector<string> arrs;
    int n;
    int dfs(unordered_set<int> cc) { // can't choose
        int rst = 0;
        for (int i = 0; i < n; ++i) {
            if (cc.find(i) == cc.end()) {
                auto cc1 = cc;
                cc1.insert(i);
                for (int x : rcd[i]) {
                    cc1.insert(x);
                }
                rst = max(rst, int(arrs[i].size()) + dfs(cc1));
            }
        }
        return rst;
    }

  public:
    int maxLength(vector<string> &arr) {
        n = arr.size();
        arrs = arr;
        rcd = vector<vector<int>>(n, vector<int>(n, 1));
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(26, 0);
            for (char c : arr[i]) {
                tmp[c - 'a']++;
            }
            for (int j = 0; j < n; ++j) {
                for (char c : arr[j]) {
                    if (tmp[c - 'a']) {
                        rcd[i][j] = 0;
                        rcd[j][i] = 0;
                        break;
                    }
                }
            }
        }
        unordered_set<int> used;
        return dfs(used);
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<string> arr;
    arr = {"un", "iq", "ue"};
    cout << slt.maxLength(arr) << endl;

    return 0;
}
