//
// Created by ming on 2020/12/18.
//

#ifndef CMAKETEST_Q0389_FINDTHEDIFFERENCE_HPP
#define CMAKETEST_Q0389_FINDTHEDIFFERENCE_HPP

#endif //CMAKETEST_Q0389_FINDTHEDIFFERENCE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        std::vector<int> rcd(26, 0);
        for (char &c:s) {
            rcd[c - 'a']++;
        }
        for (char &c:t) {
            rcd[c - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (rcd[i] != 0)return 'a' + i;
        }
        return 'a';
    }

    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};