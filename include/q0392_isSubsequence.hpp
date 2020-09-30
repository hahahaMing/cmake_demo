//
// Created by ming on 2020/7/27.
//

#ifndef CMAKETEST_Q0392_ISSUBSEQUENCE_HPP
#define CMAKETEST_Q0392_ISSUBSEQUENCE_HPP

#endif //CMAKETEST_Q0392_ISSUBSEQUENCE_HPP

#include"tools.hpp"

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty())return true;
        int l = 0 ,r = s.size()-1;
        int ll = 0,rr = t.size()-1;
        while (ll<rr){
            if (s[l]==t[ll])l++;
            ll++;
            if (s[r]==t[rr])r--;
            rr--;
            if (l>r)return true;
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s,  t;
        s = "abc";
        t="ahbgdc";
        std::cout << isSubsequence(s,t) << std::endl;
        s = "axc";
        t="ahbgdc";
        std::cout << isSubsequence(s,t) << std::endl;

    }
};