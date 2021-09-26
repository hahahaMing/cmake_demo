//
// Created by ming on 2021/1/7.
//

#ifndef CMAKETEST_Q0547_FINDCIRCLENUM_HPP
#define CMAKETEST_Q0547_FINDCIRCLENUM_HPP

#endif //CMAKETEST_Q0547_FINDCIRCLENUM_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<std::vector<int>> c_map;
    std::vector<bool> rcd;
    int count;
    int len;

    /**
     * 深度搜索到所有联通的元素
     * @param index
     */
    void dfs(int index) {
        rcd[index] = false;
        for (int i = 0; i < len; ++i) {
            if (rcd[i] && c_map[index][i])dfs(i);
        }
    }

public:
    int findCircleNum(std::vector<std::vector<int>> &isConnected) {
        c_map = isConnected;
        len = isConnected.size();
        rcd = std::vector<bool>(len, true);
        count = 0;
        for (int i = 0; i < len; ++i) {
            if (rcd[i]) {
                dfs(i);
                count++;
            }
        }
        return count;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> isc;
        isc = tools::string2matrixInt("[[1,1,0],[1,1,0],[0,0,1]]");
        std::cout << findCircleNum(isc) << std::endl;
        isc = tools::string2matrixInt("[[1,1,1],[1,1,1],[1,1,1]]");
        std::cout << findCircleNum(isc) << std::endl;
        isc = tools::string2matrixInt("[[1,0,0],[0,1,0],[0,0,1]]");
        std::cout << findCircleNum(isc) << std::endl;


//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};