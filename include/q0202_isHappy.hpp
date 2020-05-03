//
// Created by ming on 2020/4/30.
//

#ifndef CMAKETEST_Q0202_ISHAPPY_HPP
#define CMAKETEST_Q0202_ISHAPPY_HPP

#endif //CMAKETEST_Q0202_ISHAPPY_HPP
#include "tools.hpp"

class Solution {
public:
    bool isHappy(int n) {
        std::map<int,bool> map;
        map[n]=true;
        int temp,sum=n;
        while (true){
            temp = sum;
            sum = 0;
            while (temp>0){
                sum+=(temp%10)*(temp%10);
                temp/=10;
            }
            std::cout<<sum<<std::endl;
            if (sum==1)return true;
            if (map.find(sum)!=map.end())return false;
            map[sum]=true;
        }
        return false;


        //提取各位
        //计算平方和并存下这个数
        //循环，如果数为一就返回true，如果在数组里已经有了，返回false

    }
    void test(){
        std::cout<<"test start"<<std::endl;
        int n;

        n = 19;
        std::cout<<isHappy(n)<<std::endl;



    }
};