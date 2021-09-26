//
// Created by ming on 2020/12/16.
//

#ifndef CMAKETEST_Q0290_WORDPATTERN_HPP
#define CMAKETEST_Q0290_WORDPATTERN_HPP

#endif //CMAKETEST_Q0290_WORDPATTERN_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
    std::vector<std::string> split(const std::string &s, const char flag = ' ') {
        std::vector<std::string> sv;
        std::istringstream iss(s);
        std::string temp;
        while (getline(iss, temp, flag)) {
            sv.push_back(temp);
        }
        return sv;
    }

public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> sv = split(s, ' ');
        if (pattern.size() != sv.size())return false;
        int n = pattern.size();
        std::vector<std::string> rcd(26, "");
        std::unordered_set<std::string> str_set;
        for (int i = 0; i < n; ++i) {
            if (rcd[pattern[i] - 'a'] == "") {
                if (str_set.find(sv[i]) == str_set.end()) {
                    rcd[pattern[i] - 'a'] = sv[i];
                    str_set.insert(sv[i]);
                } else return false;
            } else if (rcd[pattern[i]-'a'] != sv[i])return false;
        }
        return true;
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