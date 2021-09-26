//
// Created by ming on 2020/11/6.
//

#ifndef CMAKETEST_Q1356_SORTBYBITS_HPP
#define CMAKETEST_Q1356_SORTBYBITS_HPP

#endif //CMAKETEST_Q1356_SORTBYBITS_HPP

#include"tools.hpp"

class Solution {
    static int count_byte(int num) {
        int rst = 0;
        while (num > 0) {
            rst += (num & 1);
            num = num >> 1;
        }
        return rst;
    }
    static bool my_com(int &n1,int &n2){
        int c1 = count_byte(n1),c2 = count_byte(n2);
        if (c1==c2)return n1<n2;
        return c1<c2;
    }

public:
    std::vector<int> sortByBits(std::vector<int> &arr) {
        std::sort(arr.begin(),arr.end(),my_com);
        return arr;
    }

    void test() {
        std::cout << "test start" << std::endl;
//        std::cout << count_byte(2) << std::endl;
//        std::cout << count_byte(3) << std::endl;
//        std::cout << count_byte(1232) << std::endl;
        std::vector<int> arr;
        arr = {1024,512,256,128,64,32,16,8,4,2,1};
        tools::printVectorInt(sortByBits(arr));
        arr = {0,1,2,3,4,5,6,7,8};
        tools::printVectorInt(sortByBits(arr));
        arr = {10000,10000};
        tools::printVectorInt(sortByBits(arr));
        arr = {2,3,5,7,11,13,17,19};
        tools::printVectorInt(sortByBits(arr));
        arr = {10,100,1000,10000};
        tools::printVectorInt(sortByBits(arr));
        arr = {};
        tools::printVectorInt(sortByBits(arr));
    }
};