//
// Created by ming on 2020/11/22.
//

#ifndef CMAKETEST_Q0242_ISANAGRAM_HPP
#define CMAKETEST_Q0242_ISANAGRAM_HPP

#endif //CMAKETEST_Q0242_ISANAGRAM_HPP

#include"tools.hpp"

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::map<char, int> hash;
        for (char c:s) {
            if (hash.find(c) != hash.end())hash[c]++;
            else hash[c] == 1;
        }
        for (char c:t) {
            if (hash.find(c) != hash.end()) {
                hash[c]--;
                if (hash[c] < 0)return false;
            } else {
                return false;
            }
        }
        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};