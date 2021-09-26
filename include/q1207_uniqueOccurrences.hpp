//
// Created by ming on 2020/10/28.
//

#ifndef CMAKETEST_Q1207_UNIQUEOCCURRENCES_HPP
#define CMAKETEST_Q1207_UNIQUEOCCURRENCES_HPP

#endif //CMAKETEST_Q1207_UNIQUEOCCURRENCES_HPP
#include"tools.hpp"
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int,int> hash;
        for(int a : arr){
            if(hash.find(a)==hash.end())hash[a]=1;
            else hash[a]++;
        }
        std::unordered_set<int> rst;
        for(auto & it : hash){
            if (rst.find(it.second)==rst.end())rst.emplace(it.second);
            else return false;
        }
        return true;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};