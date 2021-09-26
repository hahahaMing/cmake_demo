//
// Created by ming on 2020/10/18.
//

#ifndef CMAKETEST_Q0019_REMOVENTHFROMEND_HPP
#define CMAKETEST_Q0019_REMOVENTHFROMEND_HPP

#endif //CMAKETEST_Q0019_REMOVENTHFROMEND_HPP

#include"tools.hpp"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre_head = new ListNode(0),*cur;
        pre_head->next = head;
        cur = pre_head;
        for (int i = 0; i < n-1; ++i) {
            head = head->next;
        }
        while (head->next){
            cur = cur->next;
            head = head->next;
        }
        cur->next = cur->next->next;
        return pre_head->next;
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *head;
//        head = tools::num2List(12345);
//        tools::printList(head);
        for (int i = 1; i <= 5; ++i) {
            head = tools::num2List(12345);
            tools::printList(removeNthFromEnd(head, i));
        }
//        tools::printList(removeNthFromEnd(nullptr, 0));
    }
};