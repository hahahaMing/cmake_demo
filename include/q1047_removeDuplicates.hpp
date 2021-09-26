//
// Created by ming on 2021/3/9.
//

#ifndef CMAKETEST_Q1047_REMOVEDUPLICATES_HPP
#define CMAKETEST_Q1047_REMOVEDUPLICATES_HPP

#endif //CMAKETEST_Q1047_REMOVEDUPLICATES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {



public:
    std::string removeDuplicates(std::string S) {
        std::string s;
        for(char c:S){
            if (s.empty())s.push_back(c);
            else{
                if (s.back()==c)s.pop_back();
                else s.push_back(c);
            }
        }
        return s;

    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};