//
// Created by ming on 2020/6/11.
//

#ifndef CMAKETEST_Q0739_DAILYTEMPERATURE_HPP
#define CMAKETEST_Q0739_DAILYTEMPERATURE_HPP

#endif //CMAKETEST_Q0739_DAILYTEMPERATURE_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &T) {
        std::vector<int> rst(T.size());
        for (int i = T.size() - 2; i >= 0; --i) {
            int j = i + 1;
            while (1) {
                if (T[j] > T[i]) {
                    rst[i] = j - i;
                    break;
                } else {
                    if (rst[j] == 0)break;
                    j += rst[j];
                }
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> t;
        t = {73, 74, 75, 71, 69, 72, 76, 73};
        tools::printVectorInt(dailyTemperatures(t));

    }
};