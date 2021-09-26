//
// Created by ming on 2020/9/2.
//

#ifndef CMAKETEST_HUAWEI03_HPP
#define CMAKETEST_HUAWEI03_HPP

#endif //CMAKETEST_HUAWEI03_HPP
#include"tools.hpp"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* phead = new ListNode(0);
        phead->next = head;
        std::vector<ListNode*> list={phead,head};
        while(head){
            head = head->next;
            list.push_back(head);
        }
        ListNode* ptmp = list[list.size()-n-2];
        ptmp->next = ptmp->next->next;
        return phead->next;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        ListNode * head;
        head = tools::num2List(12345);
        tools::printList(head);
        tools::printList(removeNthFromEnd(head,2));

    }
};