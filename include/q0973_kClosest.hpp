//
// Created by ming on 2020/11/9.
//

#ifndef CMAKETEST_Q0973_KCLOSEST_HPP
#define CMAKETEST_Q0973_KCLOSEST_HPP

#endif //CMAKETEST_Q0973_KCLOSEST_HPP

#include"tools.hpp"

class Solution {
    bool myCmp(std::vector<std::vector<int>> &points, int i, int j) {
        return points[i][0] * points[i][0] + points[i][1] * points[i][1] >=
               points[j][0] * points[j][0] + points[j][1] * points[j][1];
    }

    /**
     * 取出start，让start到end中比start小的都放到start左边，其余的放右边
     * 直到 排序后的start或者他前面的id为K-1，返回前面的东西。
     * @param points
     * @param K
     * @param start
     * @param end
     */
    void mysort(std::vector<std::vector<int>> &points, int K, int start, int end) {
        std::vector<std::vector<int>> sp, lp, rst;
        int i = start;
        for (int j = start + 1; j < end; ++j) {
            if (myCmp(points, i, j))sp.push_back(points[j]);
            else lp.push_back(points[j]);
        }
        i = sp.size();
        rst.insert(rst.end(),points.begin(),points.begin()+start);
        rst.insert(rst.end(),sp.begin(),sp.end());
        rst.push_back(points[start]);
        rst.insert(rst.end(),lp.begin(),lp.end());
        rst.insert(rst.end(),points.begin()+end,points.end());
        points = rst;
        if (i == K || i == K - 1)return;
        if (i > K)mysort(points, K, start, i);
        else mysort(points, K, i + 1, end);
    }

public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int K) {
        mysort(points, K, 0, points.size());
        std::vector<std::vector<int>> rst = {};
        for (int i = 0; i < K; ++i) {
            rst.push_back(points[i]);
        }
        return rst;

    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> p;
        int K;
//        p = tools::string2matrixInt("[[1,3],[-2,2]]");
//        K = 1;
//        tools::print2DVector(kClosest(p,K));
//        p = tools::string2matrixInt("[[3,3],[5,-1],[-2,4]]");
//        K = 2;
//        tools::print2DVector(kClosest(p, K));
        p = tools::string2matrixInt("[[3,2],[7,7],[9,-9],[4,-6],[-3,-6]]");
        K = 4;
        tools::print2DVector(kClosest(p, K));
    }
};