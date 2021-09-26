//
// Created by ming on 2021/1/31.
//

#ifndef CMAKETEST_Q0839_NUMSIMILARGROUPS_HPP
#define CMAKETEST_Q0839_NUMSIMILARGROUPS_HPP

#endif //CMAKETEST_Q0839_NUMSIMILARGROUPS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    int n, str_len;
    std::vector<int> parent;

    void init() {
        parent = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int get(int x) {
        if (parent[x] == x)return x;
        return parent[x] = get(parent[x]);
    }

    void merge(int x, int y) {
        parent[get(y)] = get(x);
    }


    bool is_similar(std::string &s1, std::string &s2) {
        int count = 0;
        for (int i = 0; i < str_len; ++i) {
            if (s1[i] != s2[i])count++;
            if (count > 2)return false;
        }
        return true;
    }


public:
    int numSimilarGroups(std::vector<std::string> &strs) {
        n = strs.size(), str_len = strs[0].size();
        init();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (is_similar(strs[j],strs[i]))merge(j,i);
            }
        }
        std::unordered_set<int> rcd;
        for(int x:parent){
            if (rcd.find(get(x))==rcd.end())rcd.insert(get(x));
        }
        return rcd.size();
    }

    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};