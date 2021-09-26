//
// Created by ming on 2020/12/11.
//

#ifndef CMAKETEST_Q0649_PREDICTPARTYVICTORY_HPP
#define CMAKETEST_Q0649_PREDICTPARTYVICTORY_HPP

#endif //CMAKETEST_Q0649_PREDICTPARTYVICTORY_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
    std::string senate_str;
    int len;
    std::vector<bool> rcd;

    int find_next_man(char party, int start) {
        if (start == -1) {
            for (int i = 0; i < len; ++i) {
                if (senate_str[i] == party)return i;
            }
            return -1;
        }
        int rst = start + 1;
        while (rst != start) {
            if (rcd[rst] && senate_str[rst] == party)return rst;
            rst++;
            if (rst >= len)rst = 0;
        }
        if (rcd[rst] && senate_str[rst] == party)return rst;
        return -1;
    }


public:
    std::string predictPartyVictory(std::string senate) {
        senate_str = senate;
        len = senate.size();
        rcd = std::vector<bool>(len, true);
        int r = find_next_man('R', -1), d = find_next_man('D', -1);
        int i = 0;
        while (true) {
            if (r == -1)return "Dire";
            if (d == -1)return "Radiant";
            if (rcd[i]) {
                if (senate[i] == 'R') {
                    rcd[d] = false;
                    d = find_next_man('D', d);
                    r = find_next_man('R', i);
                } else {
                    rcd[r] = false;
                    r = find_next_man('R', r);
                    d = find_next_man('D', i);
                }
            }
            i++;
            if (i >= len)i = 0;
        }
        return "Radiant";
    }

    void test() {
        std::cout << "test start" << std::endl;
//        std::cout << predictPartyVictory("DRRDRDRDRDDRDRDR") << std::endl;
//        std::cout << predictPartyVictory("DR") << std::endl;
        std::cout << predictPartyVictory("RD") << std::endl;


//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};