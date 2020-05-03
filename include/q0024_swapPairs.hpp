//
// Created by ming on 2020/4/28.
//

#ifndef CMAKETEST_Q0024_SWAPPAIRS_HPP
#define CMAKETEST_Q0024_SWAPPAIRS_HPP

#endif //CMAKETEST_Q0024_SWAPPAIRS_HPP

#include "tools.hpp"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if ((!head) || (!head->next))return head;
        // 存前方已交换好的尾节点past， 最后输出的首节点前一个节点pre_head， 待交换奇偶节点sig，dbl,;
        ListNode *past = new ListNode(0), *pre_head = past, *sig, *dbl;
        pre_head->next = head;
        while (past&&past->next&&past->next->next) {
            sig = past->next;
            dbl = sig->next;

            past->next = dbl;
            past = dbl->next;
            dbl->next = sig;
            sig->next = past;
            past = sig;
        }
        return pre_head->next;
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *head;

        head = tools::num2List(1234);
        tools::printList(head);
        tools::printList(swapPairs(head));

        head = tools::num2List(123);
        tools::printList(head);
        tools::printList(swapPairs(head));


    }
};