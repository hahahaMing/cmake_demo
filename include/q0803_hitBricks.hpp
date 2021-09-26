//
// Created by ming on 2021/1/16.
//

#ifndef CMAKETEST_Q0803_HITBRICKS_HPP
#define CMAKETEST_Q0803_HITBRICKS_HPP

#endif //CMAKETEST_Q0803_HITBRICKS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> base;

    int get_base(int x) {
        if (base[x] == x)return x;
        return base[x] = get_base(base[x]);
    }

    void merge(int x, int y) {
        base[get_base(y)] = base[x];
    }

public:
    std::vector<int> hitBricks(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &hits) {
        //建图
        int m = grid.size(), n = grid[0].size();
        base = std::vector<int>(m * n + 1);
        for (int i = 0; i <= m * n; ++i) {
            base[i] = i;
        }
        //按数组打掉所有砖块
        std::vector<std::vector<int>> copy_grid = grid;
        for (const auto &hit:hits) {
            copy_grid[hit[0]][hit[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (copy_grid[0][i] == 1)base[i] = m * n;
        }
        //并查残局
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (copy_grid[i][j] == 1) {
                    int id = i * m + j;
                    //上
                    if (copy_grid[i - 1][j] == 1) {
                        merge(id - n, id);
                    }
                    //左
                    if (j > 0 && copy_grid[i][j - 1] == 1) {
                        merge(id - 1, id);
                    }
                }

            }
        }
        //建立块map
        std::unordered_map<int, int> block;
        for (int id:base) {
            if (id == m * n) {
                if (block.find(id) == block.end())block[id] = 0;
                break;
            }
            if (copy_grid[id / n][id % n] == 1) {
                if (block.find(get_base(id)) == block.end())block[get_base(id)] = 1;
                else block[get_base(id)]++;
            }
        }
        //数组倒序逐个拼回，记录每次增加的与顶连接的砖块数

        std::vector<std::vector<int>> directions{{-1, 0},
                                                 {1,  0},
                                                 {0,  -1},
                                                 {0,  1}};
        int len = hits.size();
        std::vector<int> rst(len, 0);
        for (int i = len - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0)continue;
            copy_grid[x][y] = 1;
            //四个方向统计有几个base，base里有没有m*n
            std::unordered_set<int> base_set;
            for (const auto &d:directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0)continue;
                base_set.insert(get_base(nx * n + ny));
            }
            //如果有
            if (base_set.find(m * n) != base_set.end()) {
                for (int nb:base_set) {
                    if (nb != m * n) {
                        rst[i] += block[nb];
                        block[nb] = 0;
                        merge(m * n, nb);
                    }
                }
                block[m * n] += rst[i];
            } else {//如果没有
                int last_base = -1;
                for (int nb:base_set) {
                    if (last_base != -1) {
                        merge(last_base, nb);
                        block[get_base(last_base)] += block[nb];
                        block[nb] = 0;
                    }
                    last_base = nb;
                }
                block[get_base(last_base)] += 1;
            }
        }
        //输出
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> grid;
        std::vector<std::vector<int>> hits;


        grid = tools::string2matrixInt(
                "[[0,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1],[0,0,0,1,0,0,1,1,1],[0,0,1,1,0,1,1,1,0],[0,0,0,0,0,1,1,1,1],[0,0,0,0,0,0,0,1,0]]");
        hits = tools::string2matrixInt(
                "[[1,8],[2,1],[1,4],[3,0],[3,4],[0,7],[1,6],[0,8],[2,5],[3,2],[2,0],[0,2],[0,5],[0,1],[4,8],[3,7],[0,6],[5,7],[5,3],[2,6],[2,2],[5,8],[2,8],[4,0],[3,3],[1,1],[0,0],[4,7],[0,3],[2,4],[3,1],[1,0],[5,2],[3,8],[4,2],[5,0],[1,2],[1,7],[3,6],[4,1],[5,6],[0,4],[5,5],[5,4],[1,5],[4,4],[3,5],[4,6],[2,3],[2,7]]");
        tools::printVectorInt(hitBricks(grid, hits));
        grid = tools::string2matrixInt("[[1,0,0,0],[1,1,1,0]]");
        hits = tools::string2matrixInt("[[1,0]]");
        tools::printVectorInt(hitBricks(grid, hits));
        grid = tools::string2matrixInt("[[1,0,0,0],[1,1,0,0]]");
        hits = tools::string2matrixInt("[[1,1],[1,0]]");
        tools::printVectorInt(hitBricks(grid, hits));


//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};