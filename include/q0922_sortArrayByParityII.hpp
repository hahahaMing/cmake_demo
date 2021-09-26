//
// Created by ming on 2020/11/12.
//

#ifndef CMAKETEST_Q0922_SORTARRAYBYPARITYII_HPP
#define CMAKETEST_Q0922_SORTARRAYBYPARITYII_HPP

#endif //CMAKETEST_Q0922_SORTARRAYBYPARITYII_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int> &A) {
        std::queue<int> q0, q1;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1 && A[i] % 2 == 0) {
                if (q1.empty())q0.push(i);
                else{
                    std::swap(A[i],A[q1.front()]);
                    q1.pop();
                }
            } else if (i % 2 == 0 && A[i] % 2 == 1) {
                if (q0.empty())q1.push(i);
                else{
                    std::swap(A[i],A[q0.front()]);
                    q0.pop();
                }
            }
        }
        return A;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> A;
        A = {4,2,5,7};
        tools::printVectorInt(sortArrayByParityII(A));
        A = {1,2};
        tools::printVectorInt(sortArrayByParityII(A));
        A = {2,2,2,2,2,1,1,1,1,1};
        tools::printVectorInt(sortArrayByParityII(A));

    }
};