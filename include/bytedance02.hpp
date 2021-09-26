//
// Created by ming on 2020/10/22.
//

#ifndef CMAKETEST_BYTEDANCE02_HPP
#define CMAKETEST_BYTEDANCE02_HPP

#endif //CMAKETEST_BYTEDANCE02_HPP

#include"tools.hpp"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        /*
         * 快慢指针找中间点
         * 慢指针倒序链表
         * 然后再比较
         */
        ListNode *fast = head, *slow = head,*pre_head = new ListNode(0),*tmp;
        while (fast&&fast->next){
            fast = fast->next->next;
            tmp = pre_head->next;
            pre_head->next = slow;
            slow = slow->next;
            pre_head->next->next = tmp;
        }
        if (fast->next){
            tmp = pre_head->next;
            pre_head->next = slow;
            slow = slow->next;
            pre_head->next->next = tmp;
        }
        pre_head = pre_head->next;
        while (pre_head&&slow){
            if (pre_head->val!=slow->val)return false;
            pre_head = pre_head->next;
            slow = slow->next;
        }
        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;
        ListNode *head;
        head = tools::num2List(1221);
        std::cout << isPalindrome(head) << std::endl;

    }
};