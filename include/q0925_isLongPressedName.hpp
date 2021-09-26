//
// Created by ming on 2020/10/21.
//

#ifndef CMAKETEST_Q0925_ISLONGPRESSEDNAME_HPP
#define CMAKETEST_Q0925_ISLONGPRESSEDNAME_HPP

#endif //CMAKETEST_Q0925_ISLONGPRESSEDNAME_HPP

#include"tools.hpp"

class Solution {
public:
    bool isLongPressedName(std::string name, std::string typed) {
        if (name.empty())return true;
        if (name[0] != typed[0])return false;
        char last_s = name[0];
        int i = 1, j = 1, n = name.size(), t = typed.size();
        while (i < n) {
            if (j >= t)return false;
            if (name[i] == typed[j]) {
                last_s = name[i];
                i++, j++;
                continue;
            } else {
                if (typed[j] == last_s) {
                    j++;
                    continue;
                } else {
                    return false;
                }
            }
        }
        while (j<t){
            if(typed[j]!=name.back())return false;
            else j++;
        }
        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::string> names, typeds;
        std::vector<bool> anss;
        names = {"alex", "saeed", "leelee", "laiden","alex"};
        typeds = {"aaleex", "ssaaedd", "lleeelee", "laiden","alexxr"};
        anss = {true, false, true, true, false};
        for (int i = 0; i < anss.size(); ++i) {
            if (anss[i]^isLongPressedName(names[i],typeds[i])){
                std::cout << names[i]<<" wrong!"<< std::endl;
            }
        }
//        std::string name, typed;
//        name = "alex";
//        typed = "aaleex";
//        std::cout << isLongPressedName(name, typed) << std::endl;


    }
};