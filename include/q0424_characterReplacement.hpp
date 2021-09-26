//
// Created by ming on 2021/2/2.
//

#ifndef CMAKETEST_Q0424_CHARACTERREPLACEMENT_HPP
#define CMAKETEST_Q0424_CHARACTERREPLACEMENT_HPP

#endif //CMAKETEST_Q0424_CHARACTERREPLACEMENT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int characterReplacement(std::string s, int k) {
        if (s.empty())return 0;
        //滑动窗口
        int l = 0, r = 1;
        int n = s.size();
        std::vector<int> rcd(26, 0);
        rcd[s[0] - 'A']++;
        while (r < n) {
            rcd[s[r] - 'A']++;
            if (r - l + 1 - *std::max_element(rcd.begin(), rcd.end()) > k) {
                rcd[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return r - l;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        int k;
        s = "ABBBBBBBB";
        k = 2;
        std::cout << characterReplacement(s, k) << std::endl;
        s = "ABAB", k = 2;
        std::cout << characterReplacement(s, k) << std::endl;
        s = "AABABBA", k = 1;
        std::cout << characterReplacement(s, k) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};