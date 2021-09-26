//
// Created by ming on 2021/1/19.
//

#ifndef CMAKETEST_Q1584_MINCOSTCONNECTPOINTS_HPP
#define CMAKETEST_Q1584_MINCOSTCONNECTPOINTS_HPP

#endif //CMAKETEST_Q1584_MINCOSTCONNECTPOINTS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> union_find;

    int get_root(int x) {
        if (union_find[x] == x)return x;
        return union_find[x] = get_root(union_find[x]);
    }

    void merge(int x, int y) {
        union_find[get_root(y)] = get_root(x);
    }

public:
    int minCostConnectPoints(std::vector<std::vector<int>> &points) {
        int rst = 0;
        //建图
        int n = points.size();
        std::vector<std::vector<int>> edges;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j, i});
            }
        }
        //排序
        std::sort(edges.begin(), edges.end());
        //并查
        union_find = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            union_find[i] = i;
        }
        int count = 0;
        for (const auto &edge:edges) {
            if (get_root(edge[1]) != get_root(edge[2])){
                rst+=edge[0];
                merge(edge[1],edge[2]);
                count++;
            }
            if (count==n-1)break;
        }
        //输出
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> points;


        points = tools::string2matrixInt("[[0,0],[2,2],[3,10],[5,2],[7,0]]");
        std::cout << minCostConnectPoints(points) << std::endl;
        points = tools::string2matrixInt("[[3,12],[-2,5],[-4,1]]");
        std::cout << minCostConnectPoints(points) << std::endl;
        points = tools::string2matrixInt("[[0,0],[1,1],[1,0],[-1,1]]");
        std::cout << minCostConnectPoints(points) << std::endl;
        points = tools::string2matrixInt("[[-1000000,-1000000],[1000000,1000000]]");
        std::cout << minCostConnectPoints(points) << std::endl;
        points = tools::string2matrixInt("[[0,0]]");
        std::cout << minCostConnectPoints(points) << std::endl;




//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};