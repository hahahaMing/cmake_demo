//
// Created by ming on 2021/1/26.
//

#ifndef CMAKETEST_Q1128_NUMEQUIVDOMINOPAIRS_HPP
#define CMAKETEST_Q1128_NUMEQUIVDOMINOPAIRS_HPP

#endif //CMAKETEST_Q1128_NUMEQUIVDOMINOPAIRS_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::unordered_map<int,int> count;
        for(const auto&v:dominoes){
            int x = v[0],y=v[1];
            if(x>y)std::swap(x,y);
            if(count.find(x*10+y)==count.end())count[x*10+y]=1;
            else count[x*10+y]++;
        }
        int rst = 0;
        for(const auto&it:count){
            rst+=it.second*(it.second-1)/2;
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<std::vector<int>> d;
        d = tools::string2matrixInt("[[1,2],[2,1],[3,4],[5,6]]");
        std::cout<<numEquivDominoPairs(d)<<std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};