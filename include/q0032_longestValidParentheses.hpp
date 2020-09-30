//
// Created by ming on 2020/7/4.
//

#ifndef CMAKETEST_Q0032_LONGESTVALIDPARENTHESES_HPP
#define CMAKETEST_Q0032_LONGESTVALIDPARENTHESES_HPP

#endif //CMAKETEST_Q0032_LONGESTVALIDPARENTHESES_HPP
#include"tools.hpp"
class Solution {
public:
    int longestValidParentheses(std::string s) {
        //动态规划
        /*
         * 保存：
         * 1. 包含当前位并以当前位结尾的最长有效子串长度p1
         * 2. 以当前位结尾的子串的最长有效子串长度p2
         * 更新方法：
         *
         *
         */
        if (s.empty())return 0;
        int rst = 0;
        std::vector<int> p1 = {0},p2={0};
        for (int i = 1; i < s.size(); ++i) {
            if (s[i]=='('){
                p1.push_back(0);
                p2.push_back(p2[i-1]) ;
            }else{
                int front = i-p1[i-1]-1;
                if (front>=0&&s[front]=='('){
                    if (front>0){
                        p1.push_back(p1[i-1]+2+p1[front-1]);
                    } else p1.push_back(p1[i-1]+2);

                }
                else p1.push_back(0);
                p2.push_back(std::max(p1[i],p2[i-1]));
                rst = std::max(rst,p2[i]);
            }
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string s;

//        s = "(()";
//        std::cout<<longestValidParentheses(s)<<std::endl;

        s = ")()())";
        std::cout<<longestValidParentheses(s)<<std::endl;

        s = "()(()";
        std::cout<<longestValidParentheses(s)<<std::endl;



    }
};