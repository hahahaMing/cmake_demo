//
// Created by ming on 2020/6/23.
//

#ifndef CMAKETEST_Q0067_ADDBINARY_HPP
#define CMAKETEST_Q0067_ADDBINARY_HPP

#endif //CMAKETEST_Q0067_ADDBINARY_HPP


#include"tools.hpp"
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int la = a.size()-1,lb = b.size()-1;
        std::string rst;
        bool carry=false;

        while (la>=0||lb>=0){
            int temp = 0;
            if (la>=0&&a[la]=='1')temp++;
            if (lb>=0&&b[lb]=='1')temp++;
            if (carry)temp++;
            switch (temp) {
                case 0:{
                    rst = '0'+rst;
                    carry = false;
                    break;
                }
                case 1:{
                    rst = '1'+rst;
                    carry = false;
                    break;
                }
                case 2:{
                    rst = '0'+rst;
                    carry = true;
                    break;
                }
                case 3:{
                    rst = '1'+rst;
                    carry = true;
                    break;
                }
                default:
                    break;
            }
            la--;lb--;
        }
        if (carry)rst = '1'+rst;
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string a,b;
        a = "1010";
        b = "1111";
        std::cout<<addBinary(a,b)<<std::endl;

    }
};