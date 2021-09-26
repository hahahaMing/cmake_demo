//
// Created by ming on 2021/3/18.
//

#ifndef CMAKETEST_Q0092_REVERSEBETWEEN_HPP
#define CMAKETEST_Q0092_REVERSEBETWEEN_HPP

#endif //CMAKETEST_Q0092_REVERSEBETWEEN_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 0;
        ListNode* dum = new ListNode(0),*p = new ListNode(0);
        dum->next = head;
        auto before = dum;
        auto l = dum;
        while (head!= nullptr){
            count++;
            //这里head和count对应
            //取出before
            if(count==left-1)before = head;
            //处理left-right
            //标记l
            if (count==left)l = head;
            //倒序放到p后
            if (count>=left&&count<=right){
                auto cur = head;
                head = head->next;
                //插入p首
                cur->next = p->next;
                p->next = cur;
            }else{
                head = head->next;
            }
            //都放完break，保证head是right+1
            if(count==right)break;
        }
        l->next = head;
        before->next = p->next;
        head = dum->next;
        delete dum,p;
        return head;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        ListNode* head;
        head = tools::vector2list({1,2,3,4,5});
        tools::printList(reverseBetween(head,2,4));
        head = tools::vector2list({1,2,3,4,5});
        tools::printList(reverseBetween(head,1,4));
        head = tools::vector2list({1,2,3,4,5});
        tools::printList(reverseBetween(head,1,1));
        head = tools::vector2list({1,2,3,4,5});
        tools::printList(reverseBetween(head,1,5));

    }
};