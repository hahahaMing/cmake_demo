//
// Created by ming on 2020/5/23.
//

#ifndef CMAKETEST_Q0076_MINWINDOW_HPP
#define CMAKETEST_Q0076_MINWINDOW_HPP

#endif //CMAKETEST_Q0076_MINWINDOW_HPP

#include"tools.hpp"

class Solution {
    // 给定两个初值，在一个有序vector中取n个数，找到跨度最小的两个初值
    // vector保证能取n个值
    void updateByVector(int &fst, int &lst, std::vector<int> v, int n) {
        int len = v.size() - n + 1;
        int range = std::max(v[v.size() - 1], lst) - std::min(v[0], fst);
        int tl, tr;
        int ll, rr;
        int l, r;
        bool flag = false;
        for (int i = 0; i < len; ++i) {

            l = v[i];
            r = v[i + n - 1];
            if (l >= fst)flag = true;
            tl = std::min(l, fst);
            tr = std::max(r, lst);
            if (tr -tl <= range) {
                ll = tl;
                rr = tr;
            }
            if (flag)break;
        }
        fst = ll;
        lst = rr;
    }


public:
    std::string minWindow(std::string s, std::string t) {
        std::map<char, int> map_t;
        std::map<char, std::vector<int>> map_s, temp;
        for (auto i:t) {
            if (map_t.find(i) != map_t.end())map_t[i]++;
            else {
                map_t[i] = 1;
                map_s[i] = {};
                temp[i] = {};
            }
        }
        tools::printMap(map_t);
        for (int j = 0; j < s.size(); j++) {
            if (map_t.find(s[j]) != map_t.end())map_s[s[j]].push_back(j);
        }
        tools::printMap(map_s);
        //  问题转化为： 在几个有序数组中取固定几个数使得这些数的最大值和最小值之差最小
        // 循环找差最小的组合
        int fst, lst;
        int first,last;
        int range = s.size();
        int num = map_s.begin()->second.size() - map_t[map_s.begin()->first]+ 1;
        if (num<=0)return "";
        for (int j = 0; j < num ; j++) {
            if (map_s.begin()->second.size() < map_t[map_s.begin()->first])return "";
            fst = map_s.begin()->second[j];
            lst = map_s.begin()->second[j - 1 + map_t[map_s.begin()->first]];
            for (auto k = map_s.begin(); k != map_s.end(); ++k) {
                if (k == map_s.begin())continue;
                if (k->second.size() < map_t[k->first])return "";
                updateByVector(fst,lst,k->second,map_t[k->first]);
            }
            if (lst-fst<range){
                range = lst-fst;
                first = fst;last= lst;
            }
        }
        return s.substr(first,range+1);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string S, T;

//        S = "ADOBECODEBANC", T = "ABC";
//        std::cout << minWindow(S, T) << std::endl;

//        S = "ADOBECODEBANC", T = "AABC";
//        std::cout << minWindow(S, T) << std::endl;

//        S = "a", T = "aa";
//        std::cout << minWindow(S, T) << std::endl;



        S = "cabwefgewcwaefgcf", T = "cae";
        std::cout << minWindow(S, T) << std::endl;
    }

};