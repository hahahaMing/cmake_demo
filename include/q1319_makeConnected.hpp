//
// Created by ming on 2021/1/23.
//

#ifndef CMAKETEST_Q1319_MAKECONNECTED_HPP
#define CMAKETEST_Q1319_MAKECONNECTED_HPP

#endif //CMAKETEST_Q1319_MAKECONNECTED_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> parents;

    void init(int n) {
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
    int makeConnected(int n, std::vector<std::vector<int>> &connections) {
        //判断线缆数量是否足够
        int len = connections.size();
        if (len + 1 < n)return -1;
        //合并并查集
        init(n);
        for (const auto &c:connections) {
            merge(c[0],c[1]);
        }
        //统计parent数量
        std::unordered_set<int> rcd;
        for(int x:parents){
            if (rcd.find(get_parent(x))==rcd.end())rcd.insert(get_parent(x));
        }
        //输出
        return rcd.size()-1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> con;
        int n;
        con = tools::string2matrixInt("[[0,1],[0,2],[1,2]]");
        std::cout << makeConnected(4,con) << std::endl;
        con = tools::string2matrixInt("[[0,1],[0,2],[0,3],[1,2],[1,3]]");
        std::cout << makeConnected(6,con) << std::endl;
        con = tools::string2matrixInt("[[0,1],[0,2],[0,3],[1,2]]");
        std::cout << makeConnected(6,con) << std::endl;
        con = tools::string2matrixInt("[[0,1],[0,2],[3,4],[2,3]]");
        std::cout << makeConnected(5,con) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};