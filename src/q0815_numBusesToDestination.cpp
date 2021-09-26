/*
 * @Author: your name
 * @Date: 2021-06-28 16:16:57
 * @LastEditTime: 2021-06-28 20:24:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0815_numBusesToDestination.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
    int n;
    vector<int> rcd;           // 记录到达线路i需要公交数量
    vector<vector<bool>> grid; // map for routes

  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source,
                              int target) {
        // 1，建图，只关心线路是否联通
        n = routes.size();
        grid = vector<vector<bool>>(
            n, vector<bool>(n, false)); // route_i and route_j is connected?
        unordered_map<int, vector<int>> sites;// 记录每站对应线路
        rcd = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            grid[i][i] = true;
            for (int x : routes[i]) {
                if (sites.find(x) != sites.end()) {
                    for (int r : sites[x]) {
                        grid[i][r] = true;
                        grid[r][i] = true;
                    }
                }
                sites[x].emplace_back(i);
            }
        }
        // 2. bfs ，通过起终点所在线路进行搜索，填充rcd数组
        queue<int> que;
        int count = 1;
        for (int x : sites[source]) {
            que.push(x);
        }
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; ++i) {
                int tmp = que.front();
                que.pop();
                if (rcd[tmp] == 0) {
                    rcd[tmp] = count;
                    for (int j = 0; j < n; ++j) {
                        if (grid[tmp][j] && rcd[j] == 0) {
                            que.push(j);
                        }
                    }
                }
            }
            count++;
        }
        //

        int rst = 501;
        for (int x : sites[target]) {
            if(rcd[x]!=0)
                rst = min(rst, rcd[x]);
        }
        return rst == 501 ? -1 : rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<vector<int>> routes;
    int source;
    int target;
    routes = {{1, 2, 7}, {3, 6, 7}};
    cout << slt.numBusesToDestination(routes, 1, 6) << endl;

    return 0;
}
