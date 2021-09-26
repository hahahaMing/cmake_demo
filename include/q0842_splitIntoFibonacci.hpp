//
// Created by ming on 2020/12/8.
//

#ifndef CMAKETEST_Q0842_SPLITINTOFIBONACCI_HPP
#define CMAKETEST_Q0842_SPLITINTOFIBONACCI_HPP

#endif //CMAKETEST_Q0842_SPLITINTOFIBONACCI_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
    std::vector<int> rst;

    bool matching(std::string &S, std::string s1, std::string s2, int begin) {

        int n1 , n2 ;
        try{
            n1 = std::stoi(s1), n2 = std::stoi(s2);
        }catch (std::out_of_range){
            return false;
        }
        rst = {n1,n2};
        while (begin<S.size()){
            if (INT32_MAX-n1<n2)return false;
            int tmp= n1+n2;
            n1 = n2;
            n2 = tmp;
            std::string st = std::to_string(n2);
            for (int i = 0; i < st.size(); ++i) {
                if (begin+i>=S.size())return false;
                if (S[begin+i]!=st[i])return false;
            }
            begin+=st.size();
            rst.push_back(n2);
        }
        return begin==S.size();
    }


public:
    std::vector<int> splitIntoFibonacci(std::string S) {
        int n = S.size();
        for (int i = 1; i < n - n / 2; ++i) {
            std::string s1 = S.substr(0,i);
            for (int j = 1; j <= n - 2 * i; ++j) {
                std::string s2 = S.substr(i,j);
                if (matching(S,s1,s2,i+j)){
                    return rst;
                }
            }
        }
        return {};
    }


    void test() {
        std::cout << "test start" << std::endl;
        std::string S;
        S = "123456579";
        tools::printVectorInt(splitIntoFibonacci(S));
        S = "11235813";
        tools::printVectorInt(splitIntoFibonacci(S));
        S = "112358130";
        tools::printVectorInt(splitIntoFibonacci(S));
        S = "0123";
        tools::printVectorInt(splitIntoFibonacci(S));
        S = "1101111";
        tools::printVectorInt(splitIntoFibonacci(S));
    }
};