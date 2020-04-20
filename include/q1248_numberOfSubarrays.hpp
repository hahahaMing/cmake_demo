//
// Created by ming on 2020/4/21.
//

#ifndef CMAKETEST_Q1248_NUMBEROFSUBARRAYS_HPP
#define CMAKETEST_Q1248_NUMBEROFSUBARRAYS_HPP

#endif //CMAKETEST_Q1248_NUMBEROFSUBARRAYS_HPP

#include "tools.hpp"

class Solution {
public:
    int numberOfSubarrays(std::vector<int> &nums, int k) {
        //一次遍历搞定
        //记录每个奇数前后偶数的个数
        //这里可以用双指针，减少操作次数，不过可能更慢。。。
        //比如前k-1个奇数不用记录尾部有多少偶数，后k-1个奇数不用记录前端有多少个偶数。
        //这里用两个vector存放，该奇数前与上一个奇数之间的偶数个数+1，。。。与后一个。。。+1
        //先不用前后遍历，感觉有点难

        //只存前缀，每看到一个偶数，rst+=此奇数前缀
        std::vector<int> even_before, even_after;
        int count = 1,odd=0,rst=0;
        for (int &num : nums) {
            if (num & 1) {
                even_before.push_back(count);
                if (odd) even_after.push_back(count);
                count=1;
                odd++;
            } else {
                count++;
            }
        }
        even_after.push_back(count);
        for(int i= 0;i<=odd-k;i++){
            rst+=even_before[i]*even_after[i+k-1];
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        int k;

        nums = {1,1,2,1,1};
        k = 3;
        std::cout << numberOfSubarrays(nums,k) << std::endl;

        nums = {2,4,6};
        k = 1;
        std::cout << numberOfSubarrays(nums,k) << std::endl;

        nums = {2,2,2,1,2,2,1,2,2,2};
        k = 2;
        std::cout << numberOfSubarrays(nums,k) << std::endl;




    }
};