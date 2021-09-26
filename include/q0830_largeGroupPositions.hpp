//
// Created by ming on 2021/1/5.
//

#ifndef CMAKETEST_Q0830_LARGEGROUPPOSITIONS_HPP
#define CMAKETEST_Q0830_LARGEGROUPPOSITIONS_HPP

#endif //CMAKETEST_Q0830_LARGEGROUPPOSITIONS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<std::vector<int>> largeGroupPositions(std::string s) {
        int i = 0, n = s.size();
        std::vector<std::vector<int>> rst;
        while (i < n) {
            char last = s[i];
            int count = 0;
            while (i < n && s[i] == last) {
                count++;
                i++;
            }
            if (count > 2) {
                rst.push_back({i - count, i - 1});
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "abbxxxxzzy";
        tools::print2DVector(largeGroupPositions(s));
        s = "abc";
        tools::print2DVector(largeGroupPositions(s));
        s = "abcdddeeeeaabbbcd";
        tools::print2DVector(largeGroupPositions(s));
        s = "aba";
        tools::print2DVector(largeGroupPositions(s));
        s = "";
        tools::print2DVector(largeGroupPositions(s));
        s = "aaa";
        tools::print2DVector(largeGroupPositions(s));

//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};