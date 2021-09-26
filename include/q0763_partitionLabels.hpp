//
// Created by ming on 2020/10/22.
//

#ifndef CMAKETEST_Q0763_PARTITIONLABELS_HPP
#define CMAKETEST_Q0763_PARTITIONLABELS_HPP

#endif //CMAKETEST_Q0763_PARTITIONLABELS_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> partitionLabels(std::string S) {
        int n = S.size();
        std::vector<bool> used(n, 0);
        std::vector<int> rst;
        std::unordered_set<char> used_char;
        int l = 0, r = n - 1;
        while (l < n) {
            char temp = S[l];
            used_char.emplace(temp);
            while (S[r] != temp) {
                r--;
            }
            int count = 0;
            while (l < r) {
                count++;
                l++;
                temp = S[l];
                if (used_char.find(temp) != used_char.end())continue;
                used_char.emplace(temp);
                int rr = n - 1;
                while (S[rr] != temp && rr > r) {
                    rr--;
                }
                if (rr > r)r = rr;
            }
            l++;
            rst.push_back(count+1);
            r = n - 1;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string S = "ababcbacadefegdehijhklij";
        tools::printVectorInt(partitionLabels(S));

    }
};