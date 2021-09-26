//
// Created by ming on 2021/3/27.
//

#ifndef CMAKETEST_Q0061_ROTATERIGHT_HPP
#define CMAKETEST_Q0061_ROTATERIGHT_HPP

#endif //CMAKETEST_Q0061_ROTATERIGHT_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)return head;
        ListNode *l = head;
        int count = 0;
        while(l!=nullptr){
            l = l->next;
            count++;
        }
        l = head;//表示移动后的开头的前一个
        ListNode*r = head->next;//表示最后一个
        k %= count;
        if (k==0)return head;
        for(int i=1;i<k;i++){
            r = r->next;
        }
        while(r->next!=nullptr){
            l = l->next;
            r = r->next;
        }
        r->next = head;
        head = l->next;
        l->next = nullptr;
        return head;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        ListNode* head;
        head = tools::vector2list({1});
        tools::printList(rotateRight(head,2));
        head = tools::vector2list({1,2,3,4,5});
        tools::printList(rotateRight(head,2));

    }
};