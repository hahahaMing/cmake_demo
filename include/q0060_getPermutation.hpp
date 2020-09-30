//
// Created by ming on 2020/9/5.
//

#ifndef CMAKETEST_Q0060_GETPERMUTATION_HPP
#define CMAKETEST_Q0060_GETPERMUTATION_HPP

#endif //CMAKETEST_Q0060_GETPERMUTATION_HPP

#include"tools.hpp"

class Solution {
    std::vector<std::string> arrange(std::vector<std::string> arranged, std::vector<int> wfa) {
        if (wfa.empty())return arranged;
        std::vector<std::string> rst, tmp;
        std::vector<int> wfa_tmp;
        if (arranged.empty()) {

            for (int i = 0; i < wfa.size(); ++i) {
                wfa_tmp.assign(wfa.begin(), wfa.end());
                wfa_tmp.erase(wfa_tmp.begin() + i);
                tmp = arrange({{static_cast<char>('0' + wfa[i])}}, wfa_tmp);
                rst.insert(rst.end(), tmp.begin(), tmp.end());
            }
            return rst;
        } else {
            for (int i = 0; i < wfa.size(); ++i) {
                std::vector<std::string> arr_tmp;
                arr_tmp.assign(arranged.begin(), arranged.end());
                wfa_tmp.assign(wfa.begin(), wfa.end());
                wfa_tmp.erase(wfa_tmp.begin() + i);
                for (std::string &j : arr_tmp) {
                    j.push_back(static_cast<char>('0' + wfa[i]));
                }
                tmp = arrange(arr_tmp, wfa_tmp);
                rst.insert(rst.end(), tmp.begin(), tmp.end());
            }
            return rst;
        }

    }


public:
    std::string getPermutation(int n, int k) {
        /*
         * 先把n个的排列弄出来
         *
         * 查看k的前缀
         */
        std::string str, rst;
        for (int i = 0; i < n; ++i) {
            str.push_back('0' + i + 1);
        }

        int c = n - 1, m = 1, turn;
        std::vector<int> factorials = {1};
        for (int i = 1; i < n; ++i) {
            m *= i;
            factorials.push_back(m);
        }
        //开始除
        while (!str.empty()) {
            turn = k/ factorials[c];
            k = k % factorials[c];
            if (k!=0){
                rst.push_back(str[turn]);
                str.erase(str.begin() + turn);
            }else{
                rst.push_back(str[turn-1]);
                str.erase(str.begin() + turn-1);
                std::reverse(str.begin(),str.end());

                rst.insert(rst.end(),str.begin(),str.end());
                str = "";
            }
            c--;
        }
        return rst;


//        std::vector<int> wfa;
//        for (int i = 0; i < n; ++i) {
//            wfa.emplace_back(i + 1);
//        }
//        std::vector<std::string> rst = arrange({}, wfa);
//        for (const std::string &s:rst) {
//            std::cout << s << std::endl;
//        }
//        return rst[k - 1];
    }

    void test() {
        std::cout << "test start" << std::endl;
//        std::vector<std::string> v=(arrange({},{1,2,3,4}));
        std::cout << getPermutation(4, 9) << std::endl;
        std::cout << getPermutation(3,2) << std::endl;
    }
};