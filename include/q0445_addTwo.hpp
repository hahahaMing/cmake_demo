//
// Created by ming on 2020/4/14.
//

#ifndef CMAKETEST_Q445_ADDTWO_HPP
#define CMAKETEST_Q445_ADDTWO_HPP

#endif //CMAKETEST_Q445_ADDTWO_HPP

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *num2List(int num) {
        if (num == 0) {
            ListNode *temp = new ListNode(0);
            return temp;
        }
        ListNode *head = NULL;
        while (num > 0) {
            ListNode *temp = new ListNode(num % 10);
            temp->next = head;
            head = temp;
            num /= 10;
        }
        return head;
    }

    int List2num(ListNode *head) {
        if (head == nullptr) return 0;
        ListNode *temp = head;
        int rst = 0;
        while (temp != nullptr) {
            rst = rst * 10 + temp->val;
            temp = temp->next;
        }
        return rst;
    }

    void printList(ListNode *head) {
        if (head == nullptr) return;
        std::cout << head->val; //顺序输出
        printList(head->next);
//        std::cout << head->val; //逆序输出

    }

    ListNode *ReverseList(ListNode *pHead) {
        // 反转指针
        ListNode *pNode = pHead;  // 当前节点
        ListNode *pPrev = nullptr;// 当前节点的上一个节点
        ListNode *pNext = nullptr;// 当前节点的下一个节点
        ListNode *pReverseHead = nullptr;//新链表的头指针

        // 反转链表
        while (pNode != nullptr) {
            pNext = pNode->next; // 建立链接
            if (pNext == NULL)    // 判断pNode是否是最后一个节点
                pReverseHead = pNode;

            pNode->next = pPrev; // 指针反转
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *r1 = ReverseList(l1);
        ListNode *r2 = ReverseList(l2);
        ListNode *r = NULL;
        int carry = 0, n = 0;
        while (r1 != nullptr || r2 != nullptr) {
            // 计算本位值
            if (r1 == nullptr) {
                n = carry + r2->val;
                r2 = r2->next;
            } else if (r2 == nullptr) {
                n = carry + r1->val;
                r1 = r1->next;
            } else {
                n = carry + r1->val + r2->val;
                r1 = r1->next;
                r2 = r2->next;
            }
            if (n > 9) {
                n = n % 10;
                carry = 1;
            } else carry=0;
            // 填入新链表
            ListNode *temp = new ListNode(n);
            temp->next = r;
            r = temp;
        }
        if(carry){
            ListNode *temp = new ListNode(1);
            temp->next = r;
            r = temp;
        }
        return r;
    }

    void test() {
        std::cout << "test start" << std::endl;
//        ListNode t=ListNode(3);
//        std::cout<<(t.val);
//        std::cout<<2;
        ListNode *a = num2List(3999999999);
        ListNode *b = num2List(7);
//        printList(a);
//        std::cout<<List2num(a)<<std::endl;
//        printList(a);
        printList(addTwoNumbers(a, b));
    }

};