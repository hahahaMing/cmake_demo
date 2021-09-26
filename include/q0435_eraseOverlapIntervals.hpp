//
// Created by ming on 2020/12/31.
//

#ifndef CMAKETEST_Q0435_ERASEOVERLAPINTERVALS_HPP
#define CMAKETEST_Q0435_ERASEOVERLAPINTERVALS_HPP

#endif //CMAKETEST_Q0435_ERASEOVERLAPINTERVALS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0]<b[0];
        });
        std::vector<int> last = {};
        int rst = 0;
        for (auto v:intervals) {
            if (last.empty()) {
                last = v;
                continue;
            }
            if (last[1] > v[0]) {
                //有重叠，去除尾巴长的那个
                rst++;
                if (last[1] > v[1])last = v;
            } else {
                last = v;
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