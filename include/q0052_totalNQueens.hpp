//
// Created by ming on 2020/10/17.
//

#ifndef CMAKETEST_Q0052_TOTALNQUEENS_HPP
#define CMAKETEST_Q0052_TOTALNQUEENS_HPP

#endif //CMAKETEST_Q0052_TOTALNQUEENS_HPP

#include"tools.hpp"

class Solution {
private:
    std::vector<std::vector<int>> chessboard;
    int choices;
    int scale;


    void fill(int row, int col) {
//        chessboard[row][col]=1;
        int l = col - 1, r = col + 1;
        for (int i = row + 1; i < scale; ++i) {
            if (l >= 0)chessboard[i][l] = 1;
            if (r < scale)chessboard[i][r] = 1;
            chessboard[i][col] = 1;
            l--, r++;
        }


    }

    void dfs(int row) {
        auto last_chessboard = chessboard;
        for (int i = 0; i < scale; ++i) {
            if (chessboard[row][i] == 0) {
                if (row == scale - 1) {
                    choices++;
                    continue;
                } else {
                    fill(row,i);
                    dfs(row + 1);
                    chessboard = last_chessboard;
                }
            }
        }

    }

public:
    int totalNQueens(int n) {
        scale = n;
        chessboard = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        choices = 0;
        dfs(0);
        return choices;
    }

    void test() {
        std::cout << "test start" << std::endl;
        for (int i = 0; i < 11; ++i) {
            std::cout << totalNQueens(i) << std::endl;
        }
//        std::cout << totalNQueens(10) << std::endl;
    }
};