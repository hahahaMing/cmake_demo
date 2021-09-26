//
// Created by ming on 2021/1/3.
//

#ifndef CMAKETEST_Q0086_PARTITION_HPP
#define CMAKETEST_Q0086_PARTITION_HPP

#endif //CMAKETEST_Q0086_PARTITION_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *pre_small = new ListNode(0), *pre_big = new ListNode(0), *small = pre_small, *big = pre_big;
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
                head = head->next;
                small->next = nullptr;
            } else {
                big->next = head;
                big = big->next;
                head = head->next;
                big->next = nullptr;
            }
        }
        small->next = pre_big->next;
        ListNode *rst = pre_small->next;
        delete pre_small;
        delete pre_big;
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *head;
        head = tools::stringToListNode("[1,4,3,2,5,2]");
        tools::printList(partition(head, 3));



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};