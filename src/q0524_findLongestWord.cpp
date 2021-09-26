/*
 * @Author: your name
 * @Date: 2021-09-14 11:09:54
 * @LastEditTime: 2021-09-14 11:27:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0524_findLongestWord.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string rst = "";
        int n = s.size();
        for (string ds : dictionary) {
            int len = ds.size();
            if (len < rst.size())
                continue;
            int j = 0;
            bool match = true;
            for (int i = 0; i < len; ++i) {
                while (j < n && s[j] != ds[i]) {
                    j++;
                }
                if(j>=n){
                    match = false;
                    break;
                }else{
                    j++;
                }
            }
            if(match){
                if(len==rst.size() && rst.compare(ds)>0){
                        rst = ds;
                }
                if(len>rst.size())rst = ds;
            }
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
