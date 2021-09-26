//
// Created by ming on 2020/10/24.
//

#ifndef CMAKETEST_Q1024_VIDEOSTITCHING_H
#define CMAKETEST_Q1024_VIDEOSTITCHING_H

#endif //CMAKETEST_Q1024_VIDEOSTITCHING_H

#include"tools.hpp"

class Solution {
public:
    int videoStitching(std::vector<std::vector<int>> &clips, int T) {
        //按clips[i][0]排序
        std::sort(clips.begin(), clips.end());
        //只留下clips[i][1]最大的
        std::vector<std::vector<int>> nc;
        for (auto &clip :clips) {
            if (nc.empty())nc.push_back(clip);
            else {
                if (nc.back()[0] == clip[0]) {
                    if (nc.back()[1] < clip[1])nc.back()[1] = clip[1];
                } else {
                    nc.push_back(clip);
                }
            }
        }
        //遍历新的数组，存从0到t时间的最小片段数
        std::vector<int> dp(T + 1, 0);
        int last_time = 0;
        for (auto &clip:nc) {
            if (clip[0] > last_time)return -1;
            for (int i = last_time + 1; i <= clip[1]; ++i) {
                dp[i] = dp[clip[0]] + 1;
                if (i == T)return dp[T];
            }
            if (clip[1] > last_time)last_time = clip[1];
        }
        return -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> c;
        int t;
        c = tools::string2matrixInt("[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]");
        t = 10;
        tools::print2DVector(c);
        std::cout << videoStitching(c, t) << std::endl;
        c = tools::string2matrixInt("[[0,1],[1,2]]");
        t = 5;
        tools::print2DVector(c);
        std::cout << videoStitching(c, t) << std::endl;
        c = tools::string2matrixInt(
                "[[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]]"
        );
        t = 9;
        tools::print2DVector(c);
        std::cout << videoStitching(c, t) << std::endl;
        c = tools::string2matrixInt("[[0,4],[2,8]]");
        t = 5;
        tools::print2DVector(c);
        std::cout << videoStitching(c, t) << std::endl;


    }
};