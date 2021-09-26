//
// Created by ming on 2020/10/7.
//

#ifndef CMAKETEST_Q0075_SORTCOLORS_HPP
#define CMAKETEST_Q0075_SORTCOLORS_HPP

#endif //CMAKETEST_Q0075_SORTCOLORS_HPP

#include"tools.hpp"

class Solution {
public:
    void sortColors(std::vector<int> &nums) {
        /*
         * 一次遍历
         * 记录第一个1的位置和第一个2的位置
         * 如果看到0：
         *  把第一个2赋值1，第一个1赋值0，当前位置赋值2；
         *  两个位置后移
         * 如果看到1：
         *  把第一个2赋值1，当前位置赋值2；
         *  第一个2位置后移
         * 如果看到2：
         *  不变
         */
        int fst1 = -1, fst2 = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (fst1 != -1) {
                    nums[fst1++] = 0;
                    if (fst2 != -1) {
                        nums[fst2++] = 1;
                        nums[i] = 2;
                    } else {
                        nums[i] = 1;
                    }
                }else{
                    if (fst2!=-1){
                        nums[fst2++]=0;
                        nums[i]=2;
                    }
                }
            } else if (nums[i] == 1) {
                if (fst1 == -1) {
                    if (fst2 == -1) {
                        fst1 = i;
                    } else {
                        fst1 = fst2++;
                        nums[fst1] = 1;
                        nums[i] = 2;
                    }
                } else {
                    if (fst2 != -1) {
                        nums[fst2++] = 1;
                        nums[i] = 2;
                    }
                }
            } else {
                if (fst2==-1){
                    fst2 = i;
                }
            }
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {2,0,2,1,1,0};
        sortColors(nums);
        tools::printVectorInt(nums);

    }
};