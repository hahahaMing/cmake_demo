//
// Created by ming on 2021/2/5.
//

#ifndef CMAKETEST_Q1028_EQUALSUBSTRING_HPP
#define CMAKETEST_Q1028_EQUALSUBSTRING_HPP

#endif //CMAKETEST_Q1028_EQUALSUBSTRING_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int n = s.size();
        std::vector<int> rcd(n);
        for (int i = 0; i < n; ++i) {
            rcd[i] = abs(s[i] - t[i]);
        }
        int l = 0, r = 0, cur = rcd[0], rst = 0;
        while (r < n) {
            if (cur > maxCost) {
                cur -= rcd[l];
                l++;
            } else {
                if (r - l + 1 > rst) {
                    rst = r - l + 1;
                }
                r++;
                if (r<n)cur+=rcd[r];
                else break;
            }
        }
        return rst;
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