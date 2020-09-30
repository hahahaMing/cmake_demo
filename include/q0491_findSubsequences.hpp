//
// Created by ming on 2020/8/25.
//

#ifndef CMAKETEST_Q0491_FINDSUBSEQUENCES_HPP
#define CMAKETEST_Q0491_FINDSUBSEQUENCES_HPP

#endif //CMAKETEST_Q0491_FINDSUBSEQUENCES_HPP

#include"tools.hpp"

class Solution {
public:
    //这个代码的功能是先排序，然后找到所有递增子序列，然而题目不是这个意思。。。
/*    std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> rst,tmp ;
        int i = 0,count = 0;
        while (i<nums.size()){
            //find the duplicated times
            int tms = 1;
            int cur = nums[i];
            count++;
            while (++i<nums.size()&&nums[i]==cur)tms++;
            int len = rst.size();
            tmp = rst;
            for (int j = 0; j < tms; ++j) {
                for (std::vector<int> &v:rst) {
                    v.push_back(cur);
                }
                rst.insert(rst.end(),tmp.begin(),tmp.end());
                rst.push_back({cur});
            }
        }
        rst.erase(rst.end()-count,rst.end());
        return rst;
    }*/
    //下面是题解。。。
    std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
        std::vector<std::vector<int>> rst, tmp;
        std::vector<int> singles;

        for (int cur : nums) {
            tools::print2DVector(rst);
            tmp = {};
            for (std::vector<int> &i : rst) {
                if (cur >= i.back()) {
                    if (cur != i.back())tmp.push_back(i);
                    i.push_back(cur);
                }
            }
            bool new_sig = true;
            for (int i : singles) {
                if (cur >= i) {
                    if (cur == i)new_sig = false;
                    tmp.push_back({i,cur});
                }
            }
            if (new_sig)singles.push_back(cur);
            rst.insert(rst.end(), tmp.begin(), tmp.end());
        }
        return rst;
    };

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1        };
        tools::print2DVector(findSubsequences(nums));

    }
};