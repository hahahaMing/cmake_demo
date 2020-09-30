//
// Created by ming on 2020/9/9.
//

#ifndef CMAKETEST_Q0039_COMBINATIONSUM_HPP
#define CMAKETEST_Q0039_COMBINATIONSUM_HPP

#endif //CMAKETEST_Q0039_COMBINATIONSUM_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> rst;
        std::unordered_map<int, std::vector<std::vector<int>>> hash;
        for (int &candidate : candidates) {
            int minus = target - candidate, count = 1, tmp = candidate;
            std::vector<int> tmp_v = {candidate};
            while (minus >= 0) {
                hash[minus].emplace_back(tmp_v);
                if (hash.find(tmp) != hash.end()) {
                    for (const std::vector<int> &v:hash[tmp]) {
                        std::vector<int> vt = v;
                        vt.insert(vt.end(), tmp_v.begin(), tmp_v.end());
                        rst.push_back(vt);
                    }
                }
                for (auto iter = hash.begin();iter!=hash.end();iter++) {
                    int k,key = iter->first;
                    k = key - tmp;

                    if (k > 0) {
                        for (const std::vector<int> &v:iter->second) {
                            std::vector<int> vt = v;
                            vt.insert(vt.end(), tmp_v.begin(), tmp_v.end());
                            hash[k].emplace_back(vt);
                        }
                    }
                }
                minus -= candidate;
                tmp += candidate;
                count++;
                tmp_v.emplace_back(candidate);
            }
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> c;
        int t;
        c = {2,3,6,7};
        t = 7;

        tools::print2DVector(combinationSum(c,t));

    }
};