//
// Created by ming on 2020/10/20.
//

#ifndef CMAKETEST_Q0143_REORDERLIST_HPP
#define CMAKETEST_Q0143_REORDERLIST_HPP

#endif //CMAKETEST_Q0143_REORDERLIST_HPP

#include"tools.hpp"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)return;
        ListNode *dumb = new ListNode(0);
        std::vector<ListNode *> vec;
        dumb->next = head;
        int count = 0;
        while (head) {
            vec.push_back(head);
            head = head->next;
            count++;
        }
        int half = count/2;
        if (count%2==0)half--;
        for (int i = 0; i < half; ++i) {
            ListNode *temp = vec[i]->next;
            vec[count - i - 2]->next = nullptr;
            vec[i]->next = vec[count - i - 1];
            vec[count - i - 1]->next = temp;
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *head;
//        head = tools::num2List(12345);
//        reorderList(head);
//        tools::printList(head);
//        head = tools::num2List(1);
//        reorderList(head);
//        tools::printList(head);
        head = tools::num2List(123456);
        reorderList(head);
        tools::printList(head);

    }
};