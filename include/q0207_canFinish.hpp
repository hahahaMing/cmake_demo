//
// Created by ming on 2020/8/4.
//

#ifndef CMAKETEST_Q0207_CANFINISH_HPP
#define CMAKETEST_Q0207_CANFINISH_HPP

#endif //CMAKETEST_Q0207_CANFINISH_HPP

#include"tools.hpp"

class Solution {


public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        /*
         * 建立双链表结构，然后去掉所有末端，如果有剩余，那就证明有环的存在，那就不能全选
         */
        std::map<int, std::vector<int>> bf, af;
        for (auto arc : prerequisites) {
            bf[arc[1]].push_back(arc[0]);
            af[arc[0]].push_back(arc[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (bf[i].empty()||af[i].empty())continue;
            else {
                int slow = i,fast = i;

            }
        }

        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};