//
// Created by ming on 2020/6/30.
//

#ifndef CMAKETEST_OFFER09_CQUEUE_HPP
#define CMAKETEST_OFFER09_CQUEUE_HPP

#endif //CMAKETEST_OFFER09_CQUEUE_HPP
#include"tools.hpp"

class CQueue {
    std::stack<int> s1,s2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }
    int deleteHead() {
        int rst=-1;
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        if (!s2.empty()){
            rst = s2.top();
            s2.pop();
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        return rst;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
class Solution {
public:

    void test(){
        std::cout<<"test start"<<std::endl;

    }
};