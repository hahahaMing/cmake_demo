//
// Created by ming on 2021/1/25.
//

#ifndef CMAKETEST_Q0959_REGIONSBYSLASHES_HPP
#define CMAKETEST_Q0959_REGIONSBYSLASHES_HPP

#endif //CMAKETEST_Q0959_REGIONSBYSLASHES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> parents;

    void union_find_init(int n) {
        parents = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    int get_parent(int x) {
        if (parents[x] == x)return x;
        return parents[x] = get_parent(parents[x]);
    }

    void merge(int x, int y) {
        parents[get_parent(y)] = get_parent(x);
    }


public:
    int regionsBySlashes(std::vector<std::string> &grid) {
        //一个方块划为上右下左0123 四个部分，遍历方块并查
        int n = grid.size();
        union_find_init(4 * n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = 4 * (i * n + j);
                //上左
                if (i != 0)merge(id - 4 * n + 2, id);
                if (j != 0)merge(id - 4 + 1, id + 3);
                //按斜杠分
                if (grid[i][j] == '/') {
                    merge(id, id + 3);
                    merge(id + 1, id + 2);
                } else if (grid[i][j] == '\\') {
                    merge(id, id + 1);
                    merge(id + 3, id + 2);
                } else {
                    merge(id, id + 1);
                    get_parent(1);
                    merge(id + 1, id + 2);
                    merge(id + 2, id + 3);
                }
            }
        }
        std::unordered_set<int> rcd;
        for (int x:parents) {
            if (rcd.find(get_parent(x)) == rcd.end())rcd.insert(get_parent(x));
        }
        return rcd.size();
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::string> grid;
        grid = {" /", "/ "};
        std::cout << regionsBySlashes(grid) << std::endl;


//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};