//
// Created by ming on 2020/12/27.
//

#ifndef CMAKETEST_Q0205_ISISOMORPHIC_HPP
#define CMAKETEST_Q0205_ISISOMORPHIC_HPP

#endif //CMAKETEST_Q0205_ISISOMORPHIC_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> rcd1, rcd2;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (rcd1.find(s[i]) != rcd1.end() && rcd1[s[i]] != t[i])return false;
            if (rcd2.find(t[i]) != rcd2.end() && rcd2[t[i]] != s[i])return false;
            rcd1[s[i]] = t[i];
            rcd2[t[i]] = s[i];
        }
        return true;
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