#include "tools.hpp"

using namespace std;

class Solution {
  public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        vector<int> fv(26, 0), bv(26, 0);
        int n = s1.size();

        if (n == 1 && s1 != s2)
            return false;
        bool rst = false;
        for (int i = 0; i < n - 1; i++) {
            bool is_f = true, is_b = true;
            fv[s1[i] - 'a']--;
            bv[s1[i] - 'a']--;
            fv[s2[i] - 'a']++;
            bv[s2[n - 1 - i] - 'a']++;
            for (int x : fv) {
                if (x != 0) {
                    is_f = false;
                    break;
                }
            }
            for (int x : bv) {
                if (x != 0) {
                    is_b = false;
                    break;
                }
            }
            if (is_f)
                rst = rst ||
                      (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &&
                       isScramble(s1.substr(i + 1), s2.substr(i + 1)));
            if (rst)
                return true;
            if (is_b)
                rst = rst ||
                      (isScramble(s1.substr(0, i + 1), s2.substr(n - i - 1)) &&
                       isScramble(s1.substr(i + 1), s2.substr(0, n - i - 1)));
            if (rst)
                return true;
        }
        return false;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution solution;
    string s1, s2;
    s1 = "great", s2 = "rgeat";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "abcde", s2 = "caebd";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "a", s2 = "a";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "abbbb", s2 = "bbbba";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "baaabbb", s2 = "bbbaaab";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "baaabbb", s2 = "abbabab";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "eebaacbcbcadaaedceaaacadccd", s2 = "eadcaacabaddaceacbceaabeccd";
    cout << solution.isScramble(s1, s2) << endl;
    s1 = "cbcbcadaaedcea", s2 = "cabaddaceacbce";

    return 0;
}
