//
// Created by ming on 2021/2/26.
//

#ifndef CMAKETEST_Q1178_FINDNUMOFVALIDWORDS_HPP
#define CMAKETEST_Q1178_FINDNUMOFVALIDWORDS_HPP

#endif //CMAKETEST_Q1178_FINDNUMOFVALIDWORDS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<int> findNumOfValidWords(std::vector<std::string> &words, std::vector<std::string> &puzzles) {
        //建立一个26*n的两数组
        int w_len = words.size(), p_len = puzzles.size();
        std::vector<std::vector<int>> w_vec(w_len, std::vector<int>(26, 0))
        , p_vec(p_len, std::vector<int>(26, 0));
        for (int i = 0; i < w_len; ++i) {
            for (char c:words[i]) {
                w_vec[i][c - 'a']++;
            }
        }
        for (int i = 0; i < p_len; ++i) {
            for (char c:puzzles[i]) {
                p_vec[i][c - 'a']++;
            }
        }
        std::vector<int> rst(p_len, 0);
        for (int i = 0; i < p_len; ++i) {
            for (int j = 0; j < w_len; ++j) {
                bool is_ans = true;
                //首字母
                if (w_vec[j][puzzles[i][0] - 'a'] == 0)continue;
                //每一个字母
                for (int k = 0; k < 26; ++k) {
                    if (w_vec[j][k] != 0 && p_vec[i][k] == 0) {
                        is_ans = false;
                        break;
                    }
                }
                //增加
                if (is_ans)rst[i]++;
            }
        }
        return rst;

        //挨个对比？会超时吧
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::string> words, puzzles;
        words = {"apple", "pleas", "please"},
                puzzles = {"saelpxy", "xaelpsy"};
        tools::printVectorInt(findNumOfValidWords(words, puzzles));
        words = {"apple", "pleas", "please"},
                puzzles = {"aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"};
        tools::printVectorInt(findNumOfValidWords(words, puzzles));

        words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"},
                puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
        tools::printVectorInt(findNumOfValidWords(words, puzzles));

    }
};