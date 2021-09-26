//
// Created by ming on 2020/11/13.
//

#ifndef CMAKETEST_Q0328_ODDEVENLIST_HPP
#define CMAKETEST_Q0328_ODDEVENLIST_HPP

#endif //CMAKETEST_Q0328_ODDEVENLIST_HPP
#include"tools.hpp"
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)return head;
        ListNode *odd,*even,*last_even,*tmp,*last_odd;
        odd = head->next;
        last_even = head;
        last_odd = odd;
        if (head->next&&head->next->next)even = head->next->next;
        else return head;
        while (even){
            tmp = even;
            if (even->next)even = even->next->next;
            else even = nullptr;
            last_odd->next = tmp->next;
            tmp->next = odd;
            last_even->next = tmp;
            last_even = tmp;
            last_odd = last_odd->next;
        }
        return head;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        ListNode *head;
        head = tools::num2List(12345);
        tools::printList(head);
        tools::printList(oddEvenList(head));
        head = tools::num2List(2135647);
        tools::printList(head);
        tools::printList(oddEvenList(head));
        head = tools::num2List(2);
        tools::printList(head);
        tools::printList(oddEvenList(head));
        head = tools::num2List(21);
        tools::printList(head);
        tools::printList(oddEvenList(head));
        head = nullptr;
        tools::printList(head);
        tools::printList(oddEvenList(head));

    }
};