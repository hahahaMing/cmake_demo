//
// Created by ming on 2020/9/15.
//

#ifndef CMAKETEST_Q0037_SOLVESUDOKU_HPP
#define CMAKETEST_Q0037_SOLVESUDOKU_HPP

#endif //CMAKETEST_Q0037_SOLVESUDOKU_HPP

#include"tools.hpp"

class Solution {
    std::vector<std::vector<char>> tmp_board;
    std::vector<std::vector<bool>> fix;
    std::vector<std::vector<std::unordered_set<char>>> prob;


public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        tmp_board = board;
        fix = std::vector<std::vector<bool>>(9,std::vector<bool>(9,true));
        prob = std::vector<std::vector<std::unordered_set<char>>>(9,std::vector<std::unordered_set<char>>(9,{'0'}));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j]!='.'){

                }
            }
        }
    }
    void test() {
        std::cout << "test start" << std::endl;
        std::string s = R"([["5","3",".",".","7",".",".",".","."],
                            ["6",".",".","1","9","5",".",".","."],
                            [".","9","8",".",".",".",".","6","."],
                            ["8",".",".",".","6",".",".",".","3"],
                            ["4",".",".","8",".","3",".",".","1"],
                            ["7",".",".",".","2",".",".",".","6"],
                            [".","6",".",".",".",".","2","8","."],
                            [".",".",".","4","1","9",".",".","5"],
                            [".",".",".",".","8",".",".","7","9"]])";
        std::vector<std::vector<char>> b = tools::string2matrix(s);
        tools::print_matrix(b);
    }
};