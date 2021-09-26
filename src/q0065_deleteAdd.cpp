/*
 * @Author: your name
 * @Date: 2021-06-17 09:25:55
 * @LastEditTime: 2021-06-17 19:49:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0065_deleteAdd.cpp
 */
#include"tools.hpp"

using namespace std;

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
  public:
    bool isNumber(string s) {
        // find e/E
    bool isAllNum(string &s) {
        for (char c : s) {
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }
            s = s.substr(1);
        }
    }
class Solution {
    void deleteAdd(string &s) {
        if (s[0] == '+' || s[0] == '-') {

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
