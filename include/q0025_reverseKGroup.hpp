//
// Created by ming on 2020/4/28.
//

#ifndef CMAKETEST_Q0025_REVERSEKGROUP_HPP
#define CMAKETEST_Q0025_REVERSEKGROUP_HPP

#endif //CMAKETEST_Q0025_REVERSEKGROUP_HPP
#include "tools.hpp"

class Solution {
private:
    ListNode* reverseBefore(ListNode* head,ListNode* before){
        //反转before前的节点
        ListNode *prev = before,*curr = head;
        while (curr!=before){
            ListNode *next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
    ListNode* reverseKafter(ListNode* start,int k){
        //反转start后k个节点
        //如果不够k个，不反转
        auto end = start->next;
        for(int i = 0;i<k;i++){
            if (!end)return start;
            end = end->next;
        }
        start->next = reverseBefore(start->next,end);
        return start;

    }


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1||(!head)) return head;
        auto* pre_head = new ListNode(0);
        pre_head->next=head;
        ListNode *before = pre_head;
        int count = 0;
        while (before){
            if (count==0)before =reverseKafter(before,k);
            before = before->next;
            count++;
            if (count==k) count = 0;
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
//        tools::printList(reverseBefore(l,l->next->next->next->next));

//        tools::printList(reverseKafter(l,l,5));
        tools::printList(reverseKGroup(l,k));
        l = tools::num2List(12345);
        tools::printList(l);
        tools::printList(reverseKGroup(l,3));
        l = tools::num2List(12345);
        tools::printList(l);
        tools::printList(reverseKGroup(l,4));

    }
};