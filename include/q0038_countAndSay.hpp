//
// Created by ming on 2021/2/23.
//

#ifndef CMAKETEST_Q0038_COUNTANDSAY_HPP
#define CMAKETEST_Q0038_COUNTANDSAY_HPP

#endif //CMAKETEST_Q0038_COUNTANDSAY_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::string countAndSay(int n) {
        if(n==1)return "1";
        int k = 1;
        std::string rst = "1";
        while(k<n){
            std::string tmp = "";
            int len = rst.size(),i = 0;
            while(i<len){
                int count = 0;
                char c = rst[i];
                while(i<len && rst[i]==c){
                    i++;
                    count++;
                }
                std::string c_str = std::to_string(count);
                tmp.insert(tmp.end(),c_str.begin(),c_str.end());
                tmp.push_back(c);
            }
            rst = tmp;
            k++;
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        for (int i = 1; i <=30 ; ++i) {
            std::cout<<countAndSay(i)<<std::endl;
        }

    }
};