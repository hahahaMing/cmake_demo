//
// Created by ming on 2021/1/11.
//

#ifndef CMAKETEST_Q1202_SMALLESTSTRINGWITHSWAPS_HPP
#define CMAKETEST_Q1202_SMALLESTSTRINGWITHSWAPS_HPP

#endif //CMAKETEST_Q1202_SMALLESTSTRINGWITHSWAPS_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> father;
    void init(int len){
        father = std::vector<int>(len,0);
        for (int i = 0; i < len; ++i) {
            father[i] = i;
        }
    }
    int get(int x){
        if (father[x]==x){
            return x;
        }
        return father[x] = get(father[x]);
    }
    void merge(int x,int y){
        x = get(x),y = get(y);
        if (x!=y){
            father[y] = x;
        }
    }

public:
    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs) {
        int n = s.size();
        init(n);
        for(const auto& v:pairs){
            merge(v[0],v[1]);
        }
        std::unordered_map<int,std::vector<int>>rcd;
        for (int i = 0; i < n; ++i) {
            rcd[get(i)].emplace_back(i);
        }
        for(const auto& item:rcd){
            std::string tmp_s="";
            for(int i:item.second){
                tmp_s.push_back(s[i]);
            }
            std::sort(tmp_s.begin(),tmp_s.end());
            int t_len = item.second.size();
            for (int i = 0; i < t_len; ++i) {
                s[item.second[i]] = tmp_s[i];
            }
        }
        return s;
    }
    void test(){
        std::cout<<"test start"<<std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};