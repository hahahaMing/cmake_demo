//
// Created by ming on 2020/4/26.
//

#ifndef CMAKETEST_Q0023_MERGEKLISTS_HPP
#define CMAKETEST_Q0023_MERGEKLISTS_HPP

#endif //CMAKETEST_Q0023_MERGEKLISTS_HPP

#include "tools.hpp"

class Solution {
public:
    ListNode *merge2Lists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode *head, *tail = head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head->next;
    }


    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
//        int l = lists.size();
        ListNode *rst= nullptr;
        for(size_t i = 0;i<lists.size();i++){
            rst = merge2Lists(rst,lists[i]);
        }
        return rst;
        // todo 队列优先合并
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<ListNode *> ls;
        ls.push_back(tools::num2List(145));
        ls.push_back(tools::num2List(134));
        ls.push_back(tools::num2List(26));
        for (auto i :ls) {
            tools::printList(i);
        }
//        tools::printList(merge2Lists(ls[0], ls[1]));
        tools::printList(mergeKLists(ls));
    }
};