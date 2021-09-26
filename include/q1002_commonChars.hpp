//
// Created by ming on 2020/10/14.
//

#ifndef CMAKETEST_Q1002_COMMONCHARS_HPP
#define CMAKETEST_Q1002_COMMONCHARS_HPP

#endif //CMAKETEST_Q1002_COMMONCHARS_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& A) {
        /*
         * 直接遍历得到字符串哈希表
         */
        if (A.empty())return {};
        std::unordered_map<char,int> rst_hash,cur_hash;
        int min_len = A[0].size(),n = A.size(),short_index = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i].size()<min_len){
                short_index = i;
                min_len = A[i].size();
            }
        }
        for (auto c : A[short_index]) {
            if (rst_hash.find(c)!=rst_hash.end())rst_hash[c]=1;
            else rst_hash[c]++;
        }
        A.erase(A.begin()+short_index);
        n--;
        if


    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};