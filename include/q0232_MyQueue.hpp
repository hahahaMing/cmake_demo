//
// Created by ming on 2021/3/5.
//

#ifndef CMAKETEST_Q0232_MYQUEUE_HPP
#define CMAKETEST_Q0232_MYQUEUE_HPP

#endif //CMAKETEST_Q0232_MYQUEUE_HPP

#include"tools.hpp"

class MyQueue {
    std::stack<int> stk1, stk2;

    void move() {
        int tmp;
        while (!stk1.empty()) {
            tmp = stk1.top();
            stk2.push(tmp);
            stk1.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int rst = peek();
        stk2.pop();
        return rst;
    }

    /** Get the front element. */
    int peek() {
        if (stk2.empty())move();
        if (stk2.empty())return 0;
        int rst = stk2.top();
        return rst;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */