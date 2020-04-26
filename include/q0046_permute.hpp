//
// Created by ming on 2020/4/25.
//

#ifndef CMAKETEST_Q0046_PERMUTE_HPP
#define CMAKETEST_Q0046_PERMUTE_HPP

#endif //CMAKETEST_Q0046_PERMUTE_HPP

#include "tools.hpp"

class Solution {
private:
    std::vector<std::vector<int>> record;
    void recursion(std::vector<int> head,std::vector<int> rest){
        if(rest.empty()) record.push_back(head);
        for(auto i=0;i<rest.size();i++){
            auto temp_rest = rest;
            temp_rest.erase(temp_rest.begin()+i);
            auto temp_head = head;
            temp_head.push_back(rest[i]);
            recursion(temp_head,temp_rest);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        record = {};
        recursion({},nums);
        return record;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;

        nums = {1,2,3};
        tools::print_matrix(permute(nums));

        nums = {1,2,3};
        tools::print_matrix(permute(nums));
    }
};