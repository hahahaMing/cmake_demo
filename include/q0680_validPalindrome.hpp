//
// Created by ming on 2020/5/18.
//

#ifndef CMAKETEST_Q0680_VALIDPALINDROME_HPP
#define CMAKETEST_Q0680_VALIDPALINDROME_HPP

#endif //CMAKETEST_Q0680_VALIDPALINDROME_HPP

#include "tools.hpp"
class Solution {
    bool vP(std::string s){
        auto t = s;
        std::reverse(s.begin(),s.end());
        return t==s;
    }
public:
    bool validPalindrome(std::string s) {
        int L = 0,R = s.size()-1;
        while (R>L){
            if (s[L]!=s[R]){
//                std::cout<<s.substr(L,R-L)<<std::endl;
//                std::cout<<s.substr(L+1,R-L)<<std::endl;
                return vP(s.substr(L,R-L))||vP(s.substr(L+1,R-L));
            }
            R--,L++;
        }
        return true;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string s;
        s = "aba";
        std::cout<<validPalindrome(s)<<std::endl;
        s = "abbca";
        std::cout<<validPalindrome(s)<<std::endl;
        s = "abcda";
        std::cout<<validPalindrome(s)<<std::endl;

        s = "";
        std::cout<<validPalindrome(s)<<std::endl;
        s = "a";
        std::cout<<validPalindrome(s)<<std::endl;
    }
};