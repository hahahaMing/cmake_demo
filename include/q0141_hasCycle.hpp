//
// Created by ming on 2020/10/9.
//

#ifndef CMAKETEST_Q0141_HASCYCLE_HPP
#define CMAKETEST_Q0141_HASCYCLE_HPP

#endif //CMAKETEST_Q0141_HASCYCLE_HPP
#include"tools.hpp"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast,*low;
        fast = head;low = head;
        while (fast!= nullptr&&low!= nullptr){
            low = low->next;
            fast = fast->next;
            if (fast!= nullptr)fast = fast->next;
            else break;
            if (fast==low)return true;
        }
        return false;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};