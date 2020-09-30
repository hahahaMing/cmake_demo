//
// Created by ming on 2020/8/3.
//

#ifndef CMAKETEST_Q0415_ADDSTRINGS_HPP
#define CMAKETEST_Q0415_ADDSTRINGS_HPP

#endif //CMAKETEST_Q0415_ADDSTRINGS_HPP
#include"tools.hpp"
class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        /*
         * 按十进制相加相加，从尾到头，记录进位
         */
        int l1 = num1.size()-1,l2 = num2.size()-1;
        std::string rst;
        int c1=0,c2=0,carry = 0,current;
        while (l1>=0||l2>=0){
            c1 = l1>=0?int(num1[l1])-48:0;
            c2 = l2>=0?int(num2[l2])-48:0;
            current = c1+c2+carry;
            if (current>9){
                carry = 1;
                current-=10;
            } else carry = 0;
            rst = std::to_string(current)+rst;
            l1--,l2--;
        }
        if (carry)rst='1'+rst;
        return rst;

    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string n1,n2;
        n1 = "0";
        n2 = "0";
        std::cout<<addStrings(n1,n2)<<std::endl;
//        std::cout<<int('0')<<std::endl;
    }
};