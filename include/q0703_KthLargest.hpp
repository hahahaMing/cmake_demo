//
// Created by ming on 2021/2/11.
//

#ifndef CMAKETEST_Q0703_KTHLARGEST_HPP
#define CMAKETEST_Q0703_KTHLARGEST_HPP

#endif //CMAKETEST_Q0703_KTHLARGEST_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class KthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<>> q;

public:
    KthLargest(int k, std::vector<int> &nums) {
        this->k = k;
        for (int i:nums)add(i);
    }

    int add(int val) {
        q.push(val);
        if (q.size() > k)q.pop();

        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums = {4, 5, 8, 2};
        KthLargest kthLargest = *new KthLargest(3, nums);
        kthLargest.add(3);   // return 4
        kthLargest.add(5);   // return 5
        kthLargest.add(10);  // return 5
        kthLargest.add(9);   // return 8
        kthLargest.add(4);   // return 8

    }
};