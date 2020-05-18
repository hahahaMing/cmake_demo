//
// Created by ming on 2020/5/9.
//

#ifndef CMAKETEST_Q0069_MYSQRT_HPP
#define CMAKETEST_Q0069_MYSQRT_HPP

#endif //CMAKETEST_Q0069_MYSQRT_HPP


#include"tools.hpp"
class Solution {
public:
    int mySqrt(int x) {
        if (x==0)return 0;
        //二分法靠谱
        int l = 0,r = x,m = x/2+1;
        int a,b;
        while (1){
            a = x/m;b = x/(m+1)-1;
            if (a>=m&&b<m)return m;
            if (r-l==1){
                m++;
                continue;
            }
            if (a>m)l=m;
            else r= m;
            m = (l+r)/2;
        }
    }

    void test(){
        std::cout<<"test start"<<std::endl;
//        std::cout<<mySqrt(183)<<std::endl;
        std::cout<<mySqrt(1)<<std::endl;
    }
};