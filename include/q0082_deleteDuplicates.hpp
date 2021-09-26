//
// Created by ming on 2021/3/25.
//

#ifndef CMAKETEST_Q0082_DELETEDUPLICATES_HPP
#define CMAKETEST_Q0082_DELETEDUPLICATES_HPP

#endif //CMAKETEST_Q0082_DELETEDUPLICATES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr)return head;
        ListNode *dum = new ListNode(0);
        dum->next = head;
        ListNode *fst,*scd,*cur;
        fst = dum, scd = head, cur = head->next;
        while (cur!= nullptr){
            if (cur->val==scd->val){
                while (cur!= nullptr&&cur->val==scd->val)cur = cur->next;
                fst->next = cur;
                if (cur== nullptr)break;
                scd = cur;
                cur = cur->next;
            }else{
                fst = fst->next;
                scd = scd->next;
                cur = cur->next;
            }
        }
        head = dum->next;
        delete dum;
        return head;
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *head;
        std::vector<int> v;
        v = {1,2,3,3,4,4,5};
        head = tools::vector2list(v);
        tools::printList(deleteDuplicates(head));

    }
};