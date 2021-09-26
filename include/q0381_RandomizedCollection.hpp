//
// Created by ming on 2020/10/31.
//

#ifndef CMAKETEST_Q0381_RANDOMIZEDCOLLECTION_HPP
#define CMAKETEST_Q0381_RANDOMIZEDCOLLECTION_HPP

#endif //CMAKETEST_Q0381_RANDOMIZEDCOLLECTION_HPP
#include"tools.hpp"

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        std::vector<int> v;
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        //二分法找位置插入
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {

    }

    /** Get a random element from the collection. */
    int getRandom() {

    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */