//
// Created by ming on 2021/1/12.
//

#ifndef CMAKETEST_Q1203_SORTITEMS_HPP
#define CMAKETEST_Q1203_SORTITEMS_HPP

#endif //CMAKETEST_Q1203_SORTITEMS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    int len;
    std::vector<int> G;
    std::vector<std::vector<int>> B;
    std::vector<int> rcd;
    std::vector<int> rst;
    bool contradiction;
    std::unordered_map<int, std::vector<int>> vec_g;
    std::unordered_map<int, std::vector<int>> g_rst;

    void group_total_handle(int g_id) {
//        std::cout << "group_total_handle"<< g_id << std::endl;
        g_rst[g_id] = {};
        for (const int x:vec_g[g_id]) {
            group_handle(g_id, x);
        }
        rst.insert(rst.end(),g_rst[g_id].begin(),g_rst[g_id].end());
//        std::cout << "group_total_handle_end"<< g_id << std::endl;
    }

    void group_handle(int g_id, int x) {
//        std::cout << "group_handle"<<g_id<<"," <<x << std::endl;
        if (rcd[x] == 2) {
            contradiction = true;
            return;
        }
        if (rcd[x] == 1)return;
        rcd[x] = 2;
        for (int b:B[x]) {
            if (G[b] == g_id)group_handle(g_id, b);
            else handle(b);
        }
        g_rst[g_id].emplace_back(x);
        rcd[x] = 1;

    }

    void handle(int x) {
//        std::cout << "handle"<< x << std::endl;


        if (rcd[x] == 2) {
            contradiction = true;
            return;
        }
        if (rcd[x] == 1)return;

        if (G[x] == -1) {
            rcd[x] = 2;
            for (int b:B[x]) {
                handle(b);
            }
            rst.push_back(x);
            rcd[x] = 1;
        } else {//处理有所属小组的
            group_total_handle(G[x]);
        }
    }


public:
    std::vector<int> sortItems(int n, int m, std::vector<int> &group, std::vector<std::vector<int>> &beforeItems) {
        len = n;
        G = group;
        B = beforeItems;
        rcd = std::vector<int>(len, 0);
        contradiction = false;
        rst = {};
        for (int i = 0; i < n; ++i) {
            if (G[i] != -1)vec_g[G[i]].emplace_back(i);
        }
        for (int i = 0; i < n; ++i) {
            handle(i);
            if (contradiction)return {};
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        int n,m;
        std::vector<int>group;
        std::vector<std::vector<int>> beforeItems;
        n = 8, m = 2, group = {-1,-1,1,0,0,1,0,-1}, beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
        tools::printVectorInt(sortItems(n,m,group,beforeItems));
        n = 8, m = 2, group = {-1,-1,1,0,0,1,0,-1}, beforeItems = {{},{6},{5},{6},{3},{},{4},{}};
        tools::printVectorInt(sortItems(n,m,group,beforeItems));
        n = 8, m = 2, group = {-1,-1,1,0,0,1,0,-1}, beforeItems = {{},{6},{5},{6},{3,6},{},{5},{}};
        tools::printVectorInt(sortItems(n,m,group,beforeItems));

//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};