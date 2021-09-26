//
// Created by ming on 2020/10/4.
//

#ifndef CMAKETEST_Q0002_ADDTWONUMBERS_HPP
#define CMAKETEST_Q0002_ADDTWONUMBERS_HPP

#endif //CMAKETEST_Q0002_ADDTWONUMBERS_HPP

#include"tools.hpp"

class Solution {
    ListNode *reverseList(ListNode *l) {
        if (l == nullptr || l->next == nullptr)return l;
        ListNode *l2 = nullptr, *tmp;
        while (l != nullptr) {
            tmp = l;
            l = l->next;
            tmp->next = l2;
            l2 = tmp;
        }
        return l2;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto nl1 = l1, nl2 = l2;
        ListNode *rst,*rst_cur = rst;
        int n1, n2, carry = 0, cur;
        while (nl1 != nullptr || nl2 != nullptr) {
            if (nl1) {
                n1 = nl1->val;
                nl1 = nl1->next;
            } else {
                n1 = 0;
            }
            if (nl2) {
                n2 = nl2->val;
                nl2 = nl2->next;
            } else {
                n2 = 0;
            }
            cur = n1 + n2 + carry;
            if (cur > 9) {
                cur -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            rst_cur->next = new ListNode(cur);
            rst_cur = rst_cur->next;

        }
        if (carry==1){
            rst_cur->next = new ListNode(1);
        }
        return rst->next;
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *l1, *l2;
        l1 = tools::num2List(243);
        l2 = tools::num2List(564);
        tools::printList(addTwoNumbers(l1, l2));

    }
};