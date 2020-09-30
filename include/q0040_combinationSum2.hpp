//
// Created by ming on 2020/9/10.
//

#ifndef CMAKETEST_Q0040_COMBINATIONSUM2_HPP
#define CMAKETEST_Q0040_COMBINATIONSUM2_HPP

#endif //CMAKETEST_Q0040_COMBINATIONSUM2_HPP

#include"tools.hpp"

class Solution {
    std::vector<std::vector<int>> dfs(std::vector<int> sub, int target) {
        if (sub.empty() || target < 0)return {};//todo
        int cur = sub.front(), count = 0;
        while (!sub.empty()&&sub.front()==cur){
            sub.erase(sub.begin());
            count++;
        }
        std::vector<std::vector<int>> rst;
        //去重
        for (int i = 1; i <= count; ++i) {
            std::vector<int> n_cur(i,cur);
            if (target == cur*i){
                rst.push_back(n_cur);
            }
            for (std::vector<int> v:dfs(sub, target - cur*i)) {
                v.insert(v.begin(),n_cur.begin(),n_cur.end());
                rst.push_back(v);
            }

        }
        std::vector<std::vector<int>> tmp = dfs(sub, target);
        rst.insert(rst.end(), tmp.begin(), tmp.end());





        return rst;


    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
//        std::reverse(candidates.begin(), candidates.end());
        return dfs(candidates, target);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> v;
        int t;

        v = {10, 1, 2, 7, 6, 1, 5};
        t = 8;
        tools::print2DVector(combinationSum2(v, t));

        v = {2,5,2,1,2};
        t = 5;
        tools::print2DVector(combinationSum2(v, t));
    }
};