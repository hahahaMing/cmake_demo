//
// Created by ming on 2020/4/28.
//

#ifndef CMAKETEST_Q0025_REVERSEKGROUP_HPP
#define CMAKETEST_Q0025_REVERSEKGROUP_HPP

#endif //CMAKETEST_Q0025_REVERSEKGROUP_HPP
#include "tools.hpp"

class Solution {
private:
    ListNode* reverse(ListNode* head,ListNode* before,int k){
        ListNode *pre_head = new ListNode(0),*r=before;
        for(int i = 0;i<k;i++){
            if (!r)return head;
            r = r->next;
        }
        pre_head->next=head;
        ListNode* after = r->next,*l=before->next;
        r->next = NULL;
        before->next = after;
        r = l->next;
        while (r){
            before->next = l;
            l->next = after;
            after=l;
            l=r,r=l->next;
        }
        return pre_head->next;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1||(!head)) return head;
        ListNode* pre_head = new ListNode(0);
        pre_head->next=head;
        ListNode *before = pre_head;
        int count = 0;
        while (before){
            before = before->next;
            count++;
            if (count==k){
                count = 0;
                pre_head->next = reverse(head,before,k);
            }
        }
        return pre_head->next;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

        ListNode *l;
        int k;

        l = tools::num2List(12345);
        k = 2;
        tools::printList(l);
        tools::printList(reverseKGroup(l,k));

    }
};