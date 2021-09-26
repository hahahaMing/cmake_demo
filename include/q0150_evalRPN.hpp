//
// Created by ming on 2021/3/20.
//

#ifndef CMAKETEST_Q0150_EVALRPN_HPP
#define CMAKETEST_Q0150_EVALRPN_HPP

#endif //CMAKETEST_Q0150_EVALRPN_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        for(const auto&s:tokens){
            if(s.back()<'0'||s.back()>'9'){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(s=="+")a+=b;
                else if(s=="-")a-=b;
                else if(s=="*")a*=b;
                else if(s=="/")a/=b;
                stk.push(a);
            }else{
                stk.push(std::stoi(s));
            }
        }
        return stk.top();
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<std::string> tokens;
        tokens = tools::string2Vector("[\"4\",\"13\",\"5\",\"/\",\"+\"]");
        std::cout<<evalRPN(tokens)<<std::endl;
        tokens = tools::string2Vector("[\"10\",\"6\",\"9\",\"3\",\"+\",\"-11\",\"*\",\"/\",\"*\",\"17\",\"+\",\"5\",\"+\"]");
        std::cout<<evalRPN(tokens)<<std::endl;

    }
};