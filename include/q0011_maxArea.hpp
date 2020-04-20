//
// Created by ming on 2020/4/18.
//

#ifndef CMAKETEST_Q0011_MAXAREA_HPP
#define CMAKETEST_Q0011_MAXAREA_HPP

#endif //CMAKETEST_Q0011_MAXAREA_HPP

#include "tools.hpp"

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int len = height.size();
        if (len < 2)return 0;
        int L = 0, R = len - 1,mx = 0,temp=0;
        while(L<R){
            temp = std::min(height[L],height[R])*(R-L);
            if(temp>mx) mx = temp;
            if(height[L]<height[R])L++;
            else R--;
        }
        return mx;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> h;


        h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        std::cout << maxArea(h) << std::endl;

        h = {1, 8};
        std::cout << maxArea(h) << std::endl;

        h = {};
        std::cout << maxArea(h) << std::endl;
    }
};