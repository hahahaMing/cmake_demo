//
// Created by ming on 2021/3/10.
//

#ifndef CMAKETEST_Q0224_CALCULATE_HPP
#define CMAKETEST_Q0224_CALCULATE_HPP

#endif //CMAKETEST_Q0224_CALCULATE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::string my_s;
    int n;

    int sum_in_brackets(int& start){
        //输入括号开始位，输出括号内的计算值,同时将i变为对应括回一位的值
        bool is_add = true;
        std::string num;
        int rst = 0;
        int i = start+1;
        while (i<n){
            if (my_s[i] == ' ' ) {
                i++;
                continue;
            }
            if (my_s[i] >= '0' && my_s[i] <= '9')num.push_back(my_s[i]);
            else{

                if (my_s[i]=='('){
                    rst+=is_add?sum_in_brackets(i):-sum_in_brackets(i);
                    i++;
                    continue;
                }
                int tmp = num.empty()?0:std::stoi(num);
                rst += is_add ? tmp : -tmp;
                num = "";
                if (my_s[i]==')')break;
                if (my_s[i] == '+') {
                    is_add = true;
                } else if (my_s[i] == '-') {
                    is_add = false;
                }
            }
            i++;
        }
        start = i;
        if (my_s[i]!=')'){
            int tmp = num.empty()?0:std::stoi(num);
            rst += is_add ? tmp : -tmp;
        }
        return rst;
    }

public:
    int calculate(std::string s) {
        my_s = s;
        n = s.size();
        int i = -1;
        return sum_in_brackets(i);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "- (3 + (4 + 5))";
        std::cout << calculate(s) << std::endl;
        s = "-2+ 1";
        std::cout << calculate(s) << std::endl;
        s = "1 + 1";
        std::cout << calculate(s) << std::endl;
        s = " 2-1 + 2 ";
        std::cout << calculate(s) << std::endl;
        s = "(1+(4+5+2)-3)+(6+8)";
        std::cout << calculate(s) << std::endl;

    }
};