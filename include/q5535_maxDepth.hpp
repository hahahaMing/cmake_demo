//
// Created by ming on 2020/10/11.
//

#ifndef CMAKETEST_Q5535_MAXDEPTH_HPP
#define CMAKETEST_Q5535_MAXDEPTH_HPP

#endif //CMAKETEST_Q5535_MAXDEPTH_HPP
#include"tools.hpp"
class Solution {
public:
    int maxDepth(std::string s) {
        int rst = 0,mr = 0;
        for(char c:s){
            if(c=='(')rst++;
            else if(c==')') rst--;
            if (mr<rst)mr=rst;
        }
        return mr;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string s;
        s = "";
        std::cout<<maxDepth(s)<<std::endl;
        s = "()";
        std::cout<<maxDepth(s)<<std::endl;
        s = "2/";
        std::cout<<maxDepth(s)<<std::endl;
        s = "(1+(2*3)+((8)/4))+1";
        std::cout<<maxDepth(s)<<std::endl;
        s = "(1)+((2))+(((3)))";
        std::cout<<maxDepth(s)<<std::endl;
        s = "1+(2*3)/(2-1)";
        std::cout<<maxDepth(s)<<std::endl;
        s = "1";
        std::cout<<maxDepth(s)<<std::endl;





    }
};