//
// Created by ming on 2021/2/10.
//

#ifndef CMAKETEST_Q0567_CHECKINCLUSION_HPP
#define CMAKETEST_Q0567_CHECKINCLUSION_HPP

#endif //CMAKETEST_Q0567_CHECKINCLUSION_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::vector<int> frac1(26, 0), frac2(26, 0);
        for (char c:s1)frac1[c - 'a']++;
        int len = s1.size(), l2 = s2.size(), l = 0, r = len;//[l,r)
        if (l2 < len)return false;
        for (int i = 0; i < len; ++i) {
            frac2[s2[i] - 'a']++;
        }
        bool rst = true;
        for (int i = 0; i < 26; ++i) {
            if (frac1[i] != frac2[i]) {
                rst = false;
                break;
            }
        }
        if (rst)return rst;
        while (r < l2) {
            frac2[s2[l++] - 'a']--;
            frac2[s2[r++] - 'a']++;
            rst = true;
            for (int i = 0; i < 26; ++i) {
                if (frac1[i] != frac2[i]) {
                    rst = false;
                    break;
                }
            }
            if (rst == true)break;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s1, s2;
        s1 = "ab";
        s2 = "a";
        std::cout << checkInclusion(s1, s2) << std::endl;

    }
};