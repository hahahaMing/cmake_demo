//
// Created by ming on 2020/10/2.
//

#ifndef CMAKETEST_Q0771_NUMJEWELSINSTONES_HPP
#define CMAKETEST_Q0771_NUMJEWELSINSTONES_HPP

#endif //CMAKETEST_Q0771_NUMJEWELSINSTONES_HPP
#include"tools.hpp"
class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        int count = 0;
        for(char j : J){
            for(char s:S){
                if (j==s)count++;
            }
        }
        return count;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};