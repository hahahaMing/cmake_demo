//
// Created by ming on 2020/4/28.
//

#ifndef CMAKETEST_Q0021_MERGETWOLISTS_HPP
#define CMAKETEST_Q0021_MERGETWOLISTS_HPP

#endif //CMAKETEST_Q0021_MERGETWOLISTS_HPP

#include "tools.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if((!l1)||(!l2))return l1?l1:l2;
        ListNode *head=new ListNode(0),*tail=head,*p1=l1,*p2=l2;
        while (p1&&p2){
            if (p1->val<p2->val){
                tail->next = p1;
                p1 = p1->next;
            } else{
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        tail->next = (p1?p1:p2);
        return head->next;
    }

    ListNode *merge2Lists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode *head=new ListNode(0), *tail = head, *aPtr = a, *bPtr = b;
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
    void test(){
        std::cout<<"test start"<<std::endl;
        {
            auto l1 = tools::num2List(124);
            auto l2 = tools::num2List(134);
            tools::printList(l1);
            tools::printList(l2);

            tools::printList(mergeTwoLists(l1,l2));
        }

    }
};