//
// Created by ming on 2020/12/20.
//

#ifndef CMAKETEST_Q0316_REMOVEDUPLICATELETTERS_HPP
#define CMAKETEST_Q0316_REMOVEDUPLICATELETTERS_HPP

#endif //CMAKETEST_Q0316_REMOVEDUPLICATELETTERS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<std::vector<int>> locations(26, std::vector<int>(0));
        int n = s.size();
        std::vector<bool> rst_rcd(n, true);
        for (int i = 0; i < n; ++i) {
            locations[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; ++i) {
            if (locations[i].empty())continue;
            int last = locations[i][0], len = locations[i].size();
            for (int j = 0; j < len - 1; ++j) {
                if (s[last + 1]>'a'+i){
                    rst_rcd[last] = false;
                    last = locations[i][j+1];
                }else{
                    rst_rcd[locations[i][j+1]] = false;
                }
            }
        }
        std::string  rst;
        for (int i = 0; i < n; ++i) {
            if (rst_rcd[i])rst.push_back(s[i]);
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "bcabc";
        std::cout << removeDuplicateLetters(s) << std::endl;
        s = "cbacdcbc";
        std::cout << removeDuplicateLetters(s) << std::endl;
        s = "abacb";
        std::cout << removeDuplicateLetters(s) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};