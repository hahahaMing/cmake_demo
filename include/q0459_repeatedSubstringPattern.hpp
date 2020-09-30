//
// Created by ming on 2020/8/24.
//

#ifndef CMAKETEST_Q0459_REPEATEDSUBSTRINGPATTERN_HPP
#define CMAKETEST_Q0459_REPEATEDSUBSTRINGPATTERN_HPP

#endif //CMAKETEST_Q0459_REPEATEDSUBSTRINGPATTERN_HPP
#include"tools.hpp"
class Solution {
    bool sub_repeated(std::string s,std::string sub){

    }
public:
    bool repeatedSubstringPattern(std::string s) {

        int len = s.size();
        std::vector<int> divisors = {};
        for (int i = 1; i <= len/2; ++i) {
            if (len%i==0&&len/i>1)divisors.push_back(i);
        }
        for (int divisor : divisors) {
            bool flag = true;
            int r = len/divisor;
            std::string sub = s.substr(0,divisor);
            for (int j = 1; j < r; ++j) {
                if (sub!=s.substr(j*divisor,divisor)){
                    flag = false;
                    break;
                }
            }
            if (flag)return true;
        }
        return false;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string s;
        s = "ababa";
        std::cout<<repeatedSubstringPattern(s)<<std::endl;
        s = "abab";
        std::cout<<repeatedSubstringPattern(s)<<std::endl;
        s = "abcabcabcabc";
        std::cout<<repeatedSubstringPattern(s)<<std::endl;
        s = "a";
        std::cout<<repeatedSubstringPattern(s)<<std::endl;
    }
};