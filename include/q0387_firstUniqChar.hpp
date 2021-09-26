//
// Created by ming on 2020/12/23.
//

#ifndef CMAKETEST_Q0387_FIRSTUNIQCHAR_HPP
#define CMAKETEST_Q0387_FIRSTUNIQCHAR_HPP

#endif //CMAKETEST_Q0387_FIRSTUNIQCHAR_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int firstUniqChar(std::string s) {
        if (s.empty())return -1;
        int n = s.size();
        std::vector<int> rcd(26, 0);
        for (int i = n - 1; i >= 0; --i) {
            rcd[s[i]-'a']++;
        }
        for (int i = 0; i < n; ++i) {
            if (rcd[s[i]-'a']==1)return i;
        }
        return -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "dddccdbba";
        std::cout << firstUniqChar(s) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};