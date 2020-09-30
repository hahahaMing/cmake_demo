//
// Created by ming on 2020/9/13.
//

#ifndef CMAKETEST_Q0079_EXIST_HPP
#define CMAKETEST_Q0079_EXIST_HPP

#endif //CMAKETEST_Q0079_EXIST_HPP

#include"tools.hpp"

class Solution {
    std::vector<std::vector<char>> bd;
    std::vector<std::vector<bool>> used;
    int xmx, ymx;

    bool dfs(int x, int y, std::string word) {
        if (x < 0 || x > xmx || y < 0 || y > ymx || used[y][x])return false;
        if (bd[y][x] == word.front()) {
            used[y][x] = true;
            word.erase(word.begin());
            if (word.empty()) {
                return true;
            }
            if (dfs(x - 1, y, word) ||
                dfs(x + 1, y, word) ||
                dfs(x, y - 1, word) ||
                dfs(x, y + 1, word))
                return true;

            used[y][x] = false;
        }
        return false;
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        bd = board;
        xmx = board[0].size() - 1;
        ymx = board.size() - 1;
        used = std::vector<std::vector<bool>>(ymx + 1, std::vector<bool>(xmx + 1, false));
        for (int i = 0; i < ymx + 1; ++i) {
            for (int j = 0; j < xmx + 1; ++j) {
                if (dfs(j, i, word))return true;
            }
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<char>> b;
        b = tools::string2matrix("[[\"A\",\"B\",\"C\",\"E\"],[\"S\",\"F\",\"C\",\"S\"],[\"A\",\"D\",\"E\",\"E\"]]");
        tools::print_matrix(b);
        std::cout << exist(b, "ABCCED") << std::endl;
        std::cout << exist(b, "SEE") << std::endl;
        std::cout << exist(b, "ABCB") << std::endl;

    }
};