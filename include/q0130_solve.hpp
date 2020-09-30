//
// Created by ming on 2020/8/11.
//

#ifndef CMAKETEST_Q0130_SOLVE_HPP
#define CMAKETEST_Q0130_SOLVE_HPP

#endif //CMAKETEST_Q0130_SOLVE_HPP

#include"tools.hpp"

class Solution {
    void O2I(std::vector<std::vector<char>> &board, int x, int y) {
        //给定坐标把0变为I然后把联通区域也变了
        if (board[y][x] == 'I' || board[y][x] == 'X')return;
        board[y][x] = 'I';
        if (y - 1 >= 0 && board[y - 1][x] == 'O')O2I(board, x, y - 1);
        if (x - 1 >= 0 && board[y][x - 1] == 'O')O2I(board, x - 1, y);
        if (y + 1 < board.size() && board[y + 1][x] == 'O')O2I(board, x, y + 1);
        if (x + 1 < board[0].size() && board[y][x + 1] == 'O')O2I(board, x + 1, y);
    }

public:
    void solve(std::vector<std::vector<char>> &board) {
        /*
         * 从边界找没有被包围的区域，赋值为'I'
         * 然后整体遍历，!'I'->'X','I'->'O'
         */
        if (board.empty())return;
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O')O2I(board, 0, i);
            if (board[i][board[0].size()-1] == 'O')O2I(board, board[0].size()-1, i);
        }
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O')O2I(board, i, 0);
            if (board[board.size()-1][i] == 'O')O2I(board, i, board.size()-1);
        }
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                if (board[y][x] == 'I')board[y][x] = 'O';
                else if (board[y][x] == 'O')board[y][x] = 'X';
            }
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string test = "[[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"O\",\"O\",\"X\"],[\"X\",\"X\",\"O\",\"X\"],[\"X\",\"O\",\"X\",\"X\"]]";
        std::vector<std::vector<char>> a;
        a = tools::string2matrix(test);
        tools::print_matrix(a);
        solve(a);
        tools::print_matrix(a);


    }
};