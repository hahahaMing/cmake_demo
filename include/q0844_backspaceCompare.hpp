//
// Created by ming on 2020/10/19.
//

#ifndef CMAKETEST_Q0844_BACKSPACECOMPARE_HPP
#define CMAKETEST_Q0844_BACKSPACECOMPARE_HPP

#endif //CMAKETEST_Q0844_BACKSPACECOMPARE_HPP

#include"tools.hpp"

class Solution {
    std::string reverse_backspace(std::string S) {
        std::string s;
        int ls = S.size() - 1;
        int es = 0;
        while (ls >= 0) {
            if (S[ls] != '#' && es <= 0) {
                s.push_back(S[ls]);
            } else if (S[ls] == '#') {
                es++;
            } else {
                es--;
            }
            ls--;
        }
        std::reverse(s.begin(), s.end());
        std::cout << s << std::endl;
        return s;
    }


public:
    bool backspaceCompare(std::string S, std::string T) {
        return reverse_backspace(S) == reverse_backspace(T);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s, t;
        s = "ab#c";
        t = "ad#c";
        std::cout <<backspaceCompare(s,t) << std::endl;
        s = "ab##";
        t = "c#d#";
        std::cout <<backspaceCompare(s,t) << std::endl;
        s = "a##c";
        t = "#a#c";
        std::cout <<backspaceCompare(s,t) << std::endl;
        s = "a#c";
        t = "b";
        std::cout <<backspaceCompare(s,t) << std::endl;
        s="xywrrmp";
        t="xywrrmu#p";
        std::cout <<backspaceCompare(s,t) << std::endl;



    }
};