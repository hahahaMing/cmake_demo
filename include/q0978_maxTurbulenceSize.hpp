//
// Created by ming on 2021/2/8.
//

#ifndef CMAKETEST_Q0978_MAXTURBULENCESIZE_HPP
#define CMAKETEST_Q0978_MAXTURBULENCESIZE_HPP

#endif //CMAKETEST_Q0978_MAXTURBULENCESIZE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int maxTurbulenceSize(std::vector<int> &arr) {
        if (arr.size() < 2)return arr.size();
        if (arr.size() == 2)return arr[0] == arr[1] ? 1 : 2;
        //动态规划，记录以当前数结尾的最后一个符号与长度，记录最长的长度
        int rst = 1, tmp = 1;
        int state = 0;//0表示无状态，1表示小于号，2表示大于号
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if(arr[i]==arr[i-1]){//断了，就记录前面的
                if (tmp>rst)rst = tmp;
                tmp = 1;
                state = 0;
            }else if(arr[i]<arr[i-1]){
                if (state==1){//断了，就记录前面的
                    if (tmp>rst)rst = tmp;
                    tmp = 2;
                }else{//继续
                    tmp++;
                    state = 1;
                }
            }else{
                if(state==2){//断了，就记录前面的
                    if (tmp>rst)rst = tmp;
                    tmp = 2;
                }else{//继续
                    tmp++;
                    state = 2;
                }
            }
        }
        if (tmp>rst)rst = tmp;
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> arr;
        arr = {9,4,2,10,7,8,8,1,9};
        std::cout <<maxTurbulenceSize(arr)<< std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};