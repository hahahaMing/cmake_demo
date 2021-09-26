#include"tools.hpp"

class Solution {
    int find_min_between(std::vector<int> &nums, int l, int r) {
        if (l >= r)return nums[l];
        int m = l + (r - l) / 2;
        if (nums[m] > nums[r])return find_min_between(nums, m + 1, r);
        else if (nums[m] < nums[r])return find_min_between(nums, l, m);
        else if (nums[m] > nums[l]) return nums[l];
        else if (nums[m] < nums[l])return find_min_between(nums, l + 1, m);
        else return std::min(find_min_between(nums, l, m - 1), find_min_between(nums, m, r - 1));

    }

public:
    int findMin(std::vector<int> &nums) {
        return find_min_between(nums, 0, nums.size() - 1);
    }

    void test() {
        std::cout << "test start" << std::endl;
    }
};