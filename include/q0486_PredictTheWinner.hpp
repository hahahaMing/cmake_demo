//
// Created by ming on 2020/9/1.
//

#ifndef CMAKETEST_Q0486_PREDICTTHEWINNER_HPP
#define CMAKETEST_Q0486_PREDICTTHEWINNER_HPP

#endif //CMAKETEST_Q0486_PREDICTTHEWINNER_HPP

#include"tools.hpp"

class Solution {
public:
    bool PredictTheWinner(std::vector<int> &nums) {
        if (nums.size() % 2 == 0 || nums.size() == 1)return true;//偶数必胜
        /*
         * 总数为奇数的情况下，后手掌控比赛，只有到后手看到必胜才知道胜负，后手到最后一步都看不到胜局那就必输
         */
        int odd = 0, even = 0;
        bool is_odd = false;
        for (int num : nums) {
            if (is_odd)odd += num;
            else even += num;
            is_odd = !is_odd;
        }//求得奇数索引和，偶数索引和。
        int adv = 0;
        int tmp, N = nums.size();
        int f = 0, b = N - 1;
        is_odd = false;

        while (f + 1 < b) {
            /*
             * 先手先挑一个优势大的
             * 后手评估剩余和是否有胜手
             *  没有胜手就挑个优势大的
             *  所谓优势大就是下一轮评估开始前两人当前分相差adv尽量少
             */
            if (nums[f] - std::max(nums[f + 1], nums[b]) > nums[b] - std::max(nums[f], nums[b - 1])) {
                tmp = nums[f];
                f++;
            } else {
                tmp = nums[b];
                b--;
            }
            adv += tmp;
            if (is_odd)odd -= tmp;
            else even -= tmp;
            if (abs(odd - even) > adv)return false;
            if (f + 1 >= b)return true;
            if (nums[f] - std::max(nums[f + 1], nums[b]) > nums[b] - std::max(nums[f], nums[b - 1])) {
                tmp = nums[f];
                f++;
                is_odd = b % 2;
            } else {
                tmp = nums[b];
                b--;
                is_odd = f % 2;
            }
            adv -= tmp;
            if (is_odd)even -= tmp;
            else odd -= tmp;
        }
        if (abs(odd - even) > adv)return false;
        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> v;
//        v = {0,0,7,6,5,6,1};
//        std::cout << PredictTheWinner(v)<< std::endl;
//        v = {1,5,2};
//        std::cout << PredictTheWinner(v)<< std::endl;
//
//        v = {9337301, 0, 2, 2245036, 4, 1997658, 5, 2192224, 960000, 1261120, 8824737, 1, 1161367, 9479977, 7, 2356738,
//             5, 4, 9};
//        std::cout << PredictTheWinner(v) << std::endl;
        v = {1};
        std::cout << PredictTheWinner(v) << std::endl;
    }
};