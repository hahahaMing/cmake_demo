//
// Created by ming on 2020/6/8.
//

#ifndef CMAKETEST_Q0990_EQUATIONSPOSSIBLE_HPP
#define CMAKETEST_Q0990_EQUATIONSPOSSIBLE_HPP

#endif //CMAKETEST_Q0990_EQUATIONSPOSSIBLE_HPP

#include"tools.hpp"

class Solution {
public:
    bool equationsPossible(std::vector<std::string> &equations) {
        //思路：给相等的赋值相同的数，不等的赋值为不同的数，
        //方法有错误，没法更新后更改的等式
        std::unordered_map<char, int> map;
        char t1, t2;
        int n1, n2;
        int count = 1;
        for (auto e :equations) {
            n1 = 0, n2 = 0;
            t1 = e[0];
            t2 = e[3];
            if (map.find(t1) != map.end()) n1 = map.find(t1)->second;
            if (map.find(t2) != map.end()) n2 = map.find(t2)->second;
            if (e[1] == '=') {
                if (n1 == 0) {
                    if (n2 == 0) {
                        map[t1] = count;
                        map[t2] = count;
                        count++;
                    } else {
                        map[t1] = n2;
                    }
                } else {
                    if (n2 == 0) {
                        map[t2] = n1;
                    } else {
                        if (n1 != n2)return false;
                    }
                }
            } else {
                if(t1==t2)return false;
                if (n1 == 0) {
                    map[t1] = count++;
                    if (n2 == 0) {
                        map[t2] = count++;
                    }
                } else {
                    if (n2 == 0) {
                        map[t2] = count++;
                    } else {
                        if (n1 == n2)return false;
                    }
                }

            }

        }
        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::string> e;
//        e = {"a==b","b!=a"};
//        std::cout << equationsPossible(e) << std::endl;
//
//        e = {"b==a","a==b"};
//        std::cout << equationsPossible(e) << std::endl;
//        e = {"a==b","b==c","a==c"};
//        std::cout << equationsPossible(e) << std::endl;
//        e = {"a==b","b!=c","c==a"};
//        std::cout << equationsPossible(e) << std::endl;
//        e = {"c==c","b==d","x!=z"};
//        std::cout << equationsPossible(e) << std::endl;
        e = {"a!=a"};
        std::cout << equationsPossible(e) << std::endl;


    }
};