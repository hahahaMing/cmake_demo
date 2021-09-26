//
// Created by ming on 2021/3/23.
//

#ifndef CMAKETEST_Q0341_NESTEDITERATOR_HPP
#define CMAKETEST_Q0341_NESTEDITERATOR_HPP

#endif //CMAKETEST_Q0341_NESTEDITERATOR_HPP

#include"tools.hpp"


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation


class NestedInteger {
    std::vector<NestedInteger> vec;
    int val{};
    bool is_int;

public:
    explicit NestedInteger(int x) {
        is_int = true;
        val = x;
    }

    explicit NestedInteger(std::vector<NestedInteger> v) {
        is_int = false;
        vec = std::move(v);
    }


    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() {
        return is_int;
    }


    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() {
        return val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    std::vector<NestedInteger> &getList() {
        return vec;
    }
};


class NestedIterator {
    //栈，存当前层的指针和入口位置

public:
    std::stack<std::pair<std::vector<NestedInteger> *, int>> stk;
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        std::vector<NestedInteger> *p;
        p = &nestedList;
        stk.push({p, 0});
    }

    int next() {
        hasNext();
        int rst = (*stk.top().first)[stk.top().second].getInteger();
        stk.top().second++;
        if (stk.top().second >= stk.top().first->size())stk.pop();
        return rst;
    }

    bool hasNext() {
        if (stk.empty())return false;
        if (stk.top().second >= stk.top().first->size()) {
            stk.pop();
            return hasNext();
        }
        if ((*stk.top().first)[stk.top().second].isInteger())return true;
        std::vector<NestedInteger> *p;
        p = &(*stk.top().first)[stk.top().second].getList();
        stk.top().second+=1;
        stk.push({p, 0});
        return hasNext();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:

    void test() {
        std::cout << "test start" << std::endl;

        std::vector<NestedInteger> vec;
        NestedInteger a(1), b(4), c(6);
        vec = {c};
        NestedInteger d(vec), e({b, d}), f({a, e});
        vec = f.getList();
        NestedIterator it(vec);

        while (it.hasNext())
            std::cout << it.next() <<','<<it.stk.size()<< std::endl;

//        it.next();
//        it.next();
//        it.next();
//        it.hasNext();


        NestedInteger g({a, a});
        vec = {g, b, g};
        NestedIterator it2(vec);
        std::cout << "test start" << std::endl;
        while (it2.hasNext())
            std::cout << it2.next() << std::endl;
        vec = {};
        NestedInteger h(vec);
        vec = {h};
        NestedIterator it3(vec);
        std::cout << "test start" << std::endl;
        while (it3.hasNext())
            std::cout << it3.next() << std::endl;
    }
};