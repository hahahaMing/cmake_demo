//
// Created by ming on 2020/11/5.
//

#ifndef CMAKETEST_Q0127_LADDERLENGTH_HPP
#define CMAKETEST_Q0127_LADDERLENGTH_HPP

#endif //CMAKETEST_Q0127_LADDERLENGTH_HPP

#include"tools.hpp"

class Solution {
    bool can_change(std::string &s1, std::string &s2) {
        if (s1.size() != s2.size())return false;
        int dif = 0, n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i])dif++;
            if (dif > 1)return false;
        }
        return true;
    }


public:
    int ladderLength(std::string &beginWord, std::string &endWord, std::vector<std::string> &wordList) {
        int n = wordList.size();
        std::vector<std::string> tmp_words = {beginWord}, new_words;
        std::queue<std::string> que;
        for (const auto &word:wordList)que.push(word);
        for (int i = 2; i <= n + 1; ++i) {
            new_words = {};
            int qn = que.size();
            for (int j = 0; j < qn; ++j) {
                std::string tmp_str = que.front();
                que.pop();
                bool connect = false;
                for (const auto &tw:tmp_words) {
                    if (tw==tmp_str){
                        connect = true;
                        break;
                    }
                    if (can_change(const_cast<std::string &>(tw), tmp_str)) {
                        if (tmp_str==endWord)return i;
                        new_words.push_back(tmp_str);
                        connect = true;
                        break;
                    }
                }
                if (!connect)que.push(tmp_str);
            }
            if (new_words.empty())break;
            tmp_words = new_words;
        }
        return 0;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string beginWord, endWord;
        std::vector<std::string> wordList;
        beginWord = "hit",
        endWord = "cog",
        wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;
        beginWord = "hit",
        endWord = "cog",
        wordList = {"hot", "dot", "dog", "lot", "log"};
        std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;
        beginWord = "a",
        endWord = "c",
        wordList = {"a","b","c"};
        std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;
        beginWord = "hot",
        endWord = "dog",
        wordList = {"hot", "dog", "dot"};
        std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;

    }
};