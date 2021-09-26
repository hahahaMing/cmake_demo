//
// Created by ming on 2020/10/1.
//

#ifndef CMAKETEST_LCP19_MINIMUMOPERATIONS_HPP
#define CMAKETEST_LCP19_MINIMUMOPERATIONS_HPP

#endif //CMAKETEST_LCP19_MINIMUMOPERATIONS_HPP
#include"tools.hpp"
class Solution {
public:
    int minimumOperations(std::string leaves) {
        /*
         * 动态规划
         * 存成为ryr,ry,r的形式所需最小步骤
         */
        int ryr=0,ry=0,r=0,i=3,len = leaves.size();
        r = leaves[0]=='r'?0:1;
        //初始化
        if (leaves[1]=='y'){
            ry = r++;
        }else{
            ry = r+1;
        }
        if (leaves[2]=='r'){
            ryr = ry;
            ry = std::min(ry+1,r+1);
        }else{//y
            ryr = ry+1;
            ry = std::min(ry,r);
            r++;
        }
        //开始迭代
        while (i<len){
            if (leaves[i]=='r'){
                ryr = std::min(ryr,ry);
                ry = std::min(ry+1,r+1);
            }else{////y
                ryr = std::min(ryr+1,ry+1);
                ry = std::min(ry,r);
                r++;
            }
            i++;
        }
        return ryr;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string leaves;
        leaves = "rrryyyrryyyrr";
        std::cout<<minimumOperations(leaves)<<std::endl;
        leaves = "ryr";
        std::cout<<minimumOperations(leaves)<<std::endl;
    }
};