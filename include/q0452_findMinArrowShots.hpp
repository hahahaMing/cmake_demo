//
// Created by ming on 2020/11/23.
//

#ifndef CMAKETEST_Q0452_FINDMINARROWSHOTS_HPP
#define CMAKETEST_Q0452_FINDMINARROWSHOTS_HPP

#endif //CMAKETEST_Q0452_FINDMINARROWSHOTS_HPP

#include"tools.hpp"

class Solution {
    std::vector<int> used;

    int dfs(std::vector<std::vector<int>> &points) {
//        if (last==1)return 1;
        int n = points.size(), rst = 0;
        std::vector<int> rcd;
        for (int i = 0; i < n; ++i) {
            if (used[i])continue;
            for (int j = 0; j < n; ++j) {
                if (points[j][0] > points[i][1] || points[j][1] < points[i][0] || used[j])continue;
                used[j] = 1;
                rcd.push_back(j);
            }
            rst = std::max(rst, 1 + dfs(points));
            for (int id:rcd)used[id] = 0;
        }
        return rst;
    }

public:
    int findMinArrowShots(std::vector<std::vector<int>> &points) {
        int n = points.size();
        used = std::vector<int>(n, 0);
        return dfs(points);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> points;
        points = tools::string2matrixInt("[[10,16],[2,8],[1,6],[7,12]]");
        std::cout << findMinArrowShots(points) << std::endl;
        points = tools::string2matrixInt("[[1,2],[3,4],[5,6],[7,8]]");
        std::cout << findMinArrowShots(points) << std::endl;
        points = tools::string2matrixInt("[[1,2],[2,3],[3,4],[4,5]]");
        std::cout << findMinArrowShots(points) << std::endl;
        points = tools::string2matrixInt("[[1,2]]");
        std::cout << findMinArrowShots(points) << std::endl;
        points = tools::string2matrixInt("[[2,3],[2,3]]");
        std::cout << findMinArrowShots(points) << std::endl;
        points = tools::string2matrixInt("[]");
        std::cout << findMinArrowShots(points) << std::endl;
    }
};