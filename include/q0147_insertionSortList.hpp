//
// Created by ming on 2020/11/20.
//

#ifndef CMAKETEST_Q0147_INSERTIONSORTLIST_HPP
#define CMAKETEST_Q0147_INSERTIONSORTLIST_HPP

#endif //CMAKETEST_Q0147_INSERTIONSORTLIST_HPP

#include"tools.hpp"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dum = new ListNode(0), *pre_head = dum;
        dum->next = head;
        while (head) {
            auto next_head = head->next, ins_loc = dum;
            while (ins_loc->next && ins_loc->next != head) {
                if (ins_loc->next->val < head->val)ins_loc = ins_loc->next;
                else break;
            }
            //insert
            if (ins_loc == pre_head)pre_head = head;
            else {
                pre_head->next = next_head;
                head->next = ins_loc->next;
                ins_loc->next = head;
            }
            head = next_head;
        }
        head = dum->next;
        delete dum;
        return head;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string input_str;
        std::mt19937 rng(std::random_device{}());
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec = tools::random_vector(rng, 0, 9, -99, 99);
            tools::printVectorInt(vec);
            std::cout << tools::listNodeToString(insertionSortList(tools::vector2list(vec))) << std::endl;
        }


//        input_str = "[]";
//        std::cout << tools::listNodeToString(insertionSortList(tools::stringToListNode(input_str))) << std::endl;
//        input_str = "[4,2,1,3]";
//        std::cout << tools::listNodeToString(insertionSortList(tools::stringToListNode(input_str))) << std::endl;
//        input_str = "[-1,5,3,4,0]";
//        std::cout << tools::listNodeToString(insertionSortList(tools::stringToListNode(input_str))) << std::endl;
//        input_str = "[6,5,3,1,8,7,2,4]";
//        std::cout << tools::listNodeToString(insertionSortList(tools::stringToListNode(input_str))) << std::endl;


    }
};