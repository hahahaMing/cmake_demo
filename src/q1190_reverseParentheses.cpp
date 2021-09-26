/*
 * @Author: your name
 * @Date: 2021-05-26 11:06:08
 * @LastEditTime: 2021-05-26 11:14:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1190_reverseParentheses.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    string reverseParentheses(string s) {
        stack<stack<char>> stk;
        string rst;
        for (char c : s) {
            if (c == '(') {
                stack<char> tmp;
                stk.push(tmp);
            } else if (c == ')') {
                auto tmp = stk.top();
                stk.pop();
                if (stk.empty()) {
                    while (!tmp.empty()) {
                        rst.push_back(tmp.top());
                        tmp.pop();
                    }
                } else {
                    while (!tmp.empty()) {
                        stk.top().push(tmp.top());
                        tmp.pop();
                    }
                }

            } else {
                if (stk.empty()) {
                    rst.push_back(c);
                } else {
                    stk.top().push(c);
                }
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
