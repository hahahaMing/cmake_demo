//
// Created by ming on 2020/11/11.
//

#ifndef CMAKETEST_Q0514_FINDROTATESTEPS_HPP
#define CMAKETEST_Q0514_FINDROTATESTEPS_HPP

#endif //CMAKETEST_Q0514_FINDROTATESTEPS_HPP

#include"tools.hpp"

class Solution {

    /*
     * 可能，当前最短步骤并不是最优步骤的前几步
     * 如果后面都是一步就很快，但前面可能不是很短
     */
    int myFind(std::string &key, int ring_location, int key_location) {
        if (key_location >= key.size())return 0;
        int n = ring_hash[key[key_location]].size();
        int rst = 10000, step = n;
        for (int next_ring_location : ring_hash[key[key_location]]) {
            step = std::min(abs(next_ring_location - ring_location) + 1,
                            ring_length + 1 - abs(next_ring_location - ring_location));
            rst = std::min(rst, step + myFind(key, next_ring_location, key_location + 1));
        }
        return rst;
    }
    std::map<char, std::vector<int>> ring_hash;
    int ring_length;
public:
    int findRotateSteps(std::string ring, const std::string &key) {
        for (int i = 0; i < ring.size(); ++i) {
            ring_hash[ring[i]].emplace_back(i);
        }
        ring_length = ring.size();
        std::vector<std::pair<int, int>> dp = {std::make_pair(0, 0)}, new_dp = {};
        for (char k:key) {
            for (int next_ring_location : ring_hash[k]) {
                int steps = 10000, tmp_step;
                for (auto pr:dp) {
                    tmp_step = std::min(abs(next_ring_location - pr.first) + 1,
                                        ring_length + 1 - abs(next_ring_location - pr.first));
                    steps = std::min(steps, tmp_step + pr.second);
                }
                new_dp.emplace_back(next_ring_location, steps);
            }
            dp = new_dp;
            new_dp = {};
        }
        int rst = 10000;
        for (auto pr:dp) {
            if (pr.second < rst)rst = pr.second;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string ring, key;
        ring = "godding", key = "gd";
        std::cout << findRotateSteps(ring, key) << std::endl;
        ring = "caotmcaataijjxi", key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";//137？
        std::cout << findRotateSteps(ring, key) << std::endl;

    }
};