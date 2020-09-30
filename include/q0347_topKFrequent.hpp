//
// Created by ming on 2020/9/7.
//

#ifndef CMAKETEST_Q0347_TOPKFREQUENT_HPP
#define CMAKETEST_Q0347_TOPKFREQUENT_HPP

#endif //CMAKETEST_Q0347_TOPKFREQUENT_HPP
#include"tools.hpp"
class Solution {
    typedef std::pair<int, int> PAIR;

    static bool cmp_val(const PAIR &left,const PAIR &right)
    {
        return left.second < right.second;
    }


public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int,int> fq;
        for(int num:nums){
            if (fq.find(num)==fq.end())fq[num]=1;
            else fq[num]++;
        }
        std::vector<PAIR> vec(fq.begin(),fq.end());
        std::sort(vec.begin(),vec.end(),cmp_val);
        std::vector<int> rst;
        for (int i = 0; i < k; ++i) {
            rst.emplace_back(vec[i].first);
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};