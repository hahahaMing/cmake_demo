//
// Created by ming on 2020/9/8.
//

#ifndef CMAKETEST_Q0077_COMBINE_HPP
#define CMAKETEST_Q0077_COMBINE_HPP

#endif //CMAKETEST_Q0077_COMBINE_HPP

#include"tools.hpp"

class Solution {
    std::vector<std::vector<int>> cmb(std::vector<int> sub, int k) {

        std::vector<std::vector<int>> rst, sub_rst;

        if (k == 1) {
            for (int i :sub) {
                rst.push_back({i});
            }
            return rst;

        };

        std::vector<int> tmp, ep;
        while (sub.size() >= k) {
            int t = sub.front();
            sub.erase(sub.begin());
            sub_rst = cmb(sub, k - 1);
            for (std::vector<int> &j : sub_rst) {
                ep = {t};
                ep.insert(ep.end(), j.begin(), j.end());
                rst.push_back(ep);
            }
        }

    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> v;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(i + 1);
        }
        return cmb(v, k);

    }

    void test() {
        std::cout << "test start" << std::endl;
        tools::print2DVector(combine(4, 2));
        tools::print2DVector(combine(4, 4));
        tools::print2DVector(combine(5, 1));
        tools::print2DVector(combine(5, 2));


    }
};