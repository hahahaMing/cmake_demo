#include"tools.hpp"

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        // 二分法
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[l] <= nums[r])return nums[l];//l是答案
            //l不是答案
            if (nums[mid] > nums[l]) {//向右缩小
                l = mid + 1;
            } else {//向左缩小
                l++;
                r = mid;
            }
        }
        return nums[l];
    }

    void test() {
        std::cout << "test start" << std::endl;
    }
};