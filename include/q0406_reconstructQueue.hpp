//
// Created by ming on 2020/11/16.
//

#ifndef CMAKETEST_Q0406_RECONSTRUCTQUEUE_HPP
#define CMAKETEST_Q0406_RECONSTRUCTQUEUE_HPP

#endif //CMAKETEST_Q0406_RECONSTRUCTQUEUE_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people) {
        /*
         * 小的放哪里都无所谓
         * 所以先放大的
         *
         */
        if (people.empty())return {};
        std::sort(people.begin(), people.end(), [](std::vector<int> a, std::vector<int> b) {
            if (a[0] == b[0])return a[1] < b[1];
            return a[0] > b[0];
        });
        std::vector<std::vector<int>> rst;
        int last_h = people[0][0];
        for (auto sp:people) {
            rst.insert(rst.begin()+sp[1], sp);
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> p;
        p = tools::string2matrixInt("[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]");
        tools::print2DVector(reconstructQueue(p));
//        tools::print2DVector(p);
        p = tools::string2matrixInt("[]");
        tools::print2DVector(reconstructQueue(p));
        p = tools::string2matrixInt("[[7,0]]");
        tools::print2DVector(reconstructQueue(p));

    }
};