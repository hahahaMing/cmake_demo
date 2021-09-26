//
// Created by ming on 2020/10/10.
//

#ifndef CMAKETEST_Q0142_DETECTCYCLE_HPP
#define CMAKETEST_Q0142_DETECTCYCLE_HPP

#endif //CMAKETEST_Q0142_DETECTCYCLE_HPP
#include"tools.hpp"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> s;
        while (head){
            if (s.find(head)!=s.end())return head;
            s.emplace(head);
            head = head->next;
        }
        return nullptr;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};