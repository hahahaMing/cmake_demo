//
// Created by ming on 2020/12/14.
//

#ifndef CMAKETEST_Q0049_GROUPANAGRAMS_HPP
#define CMAKETEST_Q0049_GROUPANAGRAMS_HPP

#endif //CMAKETEST_Q0049_GROUPANAGRAMS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::string> rcds = strs;
        for (auto &rcd:rcds) {
            std::sort(rcd.begin(), rcd.end());
        }
        std::vector<std::vector<std::string>> rst;
        std::unordered_map<std::string, int> table;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            if (table.find(rcds[i]) == table.end()) {
                rst.push_back({strs[i]});
                table[rcds[i]] = rst.size() - 1;
            } else {
                rst[table[rcds[i]]].emplace_back(strs[i]);
            }
        }
        return rst;
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