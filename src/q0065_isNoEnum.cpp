/*
 * @Author: your name
 * @Date: 2021-06-17 08:54:00
 * @LastEditTime: 2021-06-17 09:21:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0065_isNoEnum.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
    void deleteAdd(string &s) {
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
    }
    bool isAllNum(string &s) {
        for (char c : s) {
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }

  public:
    bool isNumber(string s) {
        // find e/E
        int ie = -1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                ie = i;
                break;
            }
        }

        if (ie != -1) { // found e
            string a = s.substr(0, ie);
            deleteAdd(a);
            if (a.empty())
                return false;
            // find dot
            int idot = -1;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] == '.') {
                    idot = i;
                    break;
                }
            }
            if (idot != -1) { // found dot
                string a1 = a.substr(0, idot), a2 = a.substr(idot + 1);
                if (!isAllNum(a1) || !isAllNum(a2) ||
                    (a1.empty() && a2.empty()))
                    return false;
            } else { // no dot
                if (!isAllNum(a))
                    return false;
            }
            string b = s.substr(ie + 1);
            deleteAdd(b);
            if (b.empty())
                return false;
            if (!isAllNum(b))
                return false;
        } else {
            deleteAdd(s);
            int idot = -1;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '.') {
                    idot = i;
                    break;
                }
            }
            if (idot != -1) { // found dot
                string s1 = s.substr(0, idot), s2 = s.substr(idot + 1);
                if (!isAllNum(s1) || !isAllNum(s2) ||
                    (s1.empty() && s2.empty()))
                    return false;
            } else { // no dot
                if (!isAllNum(s))
                    return false;
            }
        }
        return true;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    string s;
    s = "-123.456e789";
    cout << slt.isNumber(s) << endl;

    return 0;
}
