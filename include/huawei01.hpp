//
// Created by ming on 2020/9/2.
//

#ifndef CMAKETEST_HUAWEI01_HPP
#define CMAKETEST_HUAWEI01_HPP

#endif //CMAKETEST_HUAWEI01_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> findThree(int N, std::vector<int> candys, std::vector<int> colors) {
        std::vector<int> blue_rst = {}, red_rst = {};
        int blue_sum = 0, red_sum = 0;
        int b_min = 1025, r_min = 1025;
        int b_min_lc = 0, r_min_lc = 0;
        int bc = 0, rc = 0;
        for (int i = 0; i < N; ++i) {
            //前三个先存入
            if (colors[i] == 1 && bc < 3) {
                bc++;
                if (candys[i] < b_min) {
                    b_min = candys[i];
                    b_min_lc = bc - 1;
                }
                blue_sum += candys[i];
                blue_rst.push_back(i);
                continue;
            }
            if (colors[i] == 2 && rc < 3) {
                rc++;
                if (candys[i] < r_min) {
                    r_min = candys[i];
                    r_min_lc = rc - 1;
                }
                red_sum += candys[i];
                red_rst.push_back(i);
                continue;
            }
            //开始动态规划
            if (bc > 2 && colors[i] == 1) {
                if (candys[i] > b_min) {
                    blue_sum += candys[i] - b_min;
                    blue_rst[b_min_lc] = i;
                    b_min = 1025;
                    // 重新算bmin
                    for (int j = 0; j < 3; ++j) {
                        if (blue_rst[j] < b_min) {
                            b_min = blue_rst[j];
                            b_min_lc = j;
                        }
                    }
                }
            }
            if (rc > 2 && colors[i] == 2) {
                if (candys[i] > r_min) {
                    red_sum += candys[i] - r_min;
                    red_rst[r_min_lc] = i;
                    r_min = 1025;
                    for (int j = 0; j < 3; ++j) {
                        if (red_rst[j] < r_min) {
                            r_min = red_rst[j];
                            r_min_lc = j;
                        }
                    }
                }
            }
        }
        if (bc < 3) {
            blue_rst = {};
            blue_sum = 0;
        } else blue_rst.push_back(blue_sum);

        if (rc < 3) {
            red_rst = {};
            red_sum = 0;
        } else red_rst.push_back(red_sum);
        if (blue_sum > red_sum)return blue_rst;
        if (red_sum > blue_sum)return red_rst;
        if (blue_sum != 0 && blue_sum == red_sum) {
            int b_idx_min = N, r_idx_min = N;
            for (int i = 0; i < 3; ++i) {
                if (blue_rst[i] < b_idx_min)b_idx_min = blue_rst[i];
                if (red_rst[i] < r_idx_min)r_idx_min = red_rst[i];
            }
            if (b_idx_min < r_idx_min)return blue_rst;
            else return red_rst;
        }


    }


    void test() {
        std::cout << "test start" << std::endl;
        int N, a, b;//小朋友数,..
        std::vector<int> candys, colors, rst, rsts;

//        std::cin >> N;
//        while (std::cin >> a >> b) {
//            candys.push_back(a);
//            colors.push_back(b);
//        }
        N = 6;
        candys = {2, 2, 3, 5, 3, 7};
        colors = {2, 1, 2, 2, 1, 2};


        rst = findThree(N, candys, colors);
        // output
        if (rst.empty())std::cout << "null" << std::endl;

        if (candys[rst[1]] > candys[rst[0]]) {
            rsts.push_back(rst[0]);
            rsts.push_back(rst[1]);
        } else {
            rsts.push_back(rst[1]);
            rsts.push_back(rst[0]);
        }
        if (candys[rst[2]] > candys[rsts[0]]){
            if (candys[rst[2]] > candys[rsts[1]])rsts.push_back(rst[2]);
            else{
                rsts.push_back(rsts[1]);
                rsts[1] = rst[2];
            }
        }else{

        }





        for (int i = 0; i < 3; ++i) {

            std::cout << rst[i] + 1;
            if (i != 2)std::cout << ' ';
        }
        std::cout << std::endl << colors[rst[0]] << std::endl << rst[3] << std::endl;


    }
};