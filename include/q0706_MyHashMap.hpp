//
// Created by ming on 2021/3/14.
//

#ifndef CMAKETEST_Q0706_MYHASHMAP_HPP
#define CMAKETEST_Q0706_MYHASHMAP_HPP

#endif //CMAKETEST_Q0706_MYHASHMAP_HPP

#include"tools.hpp"

class MyHashMap {
private:
    const int n = 769;
    std::vector<std::list<std::pair<int, int>>> hash;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hash = std::vector<std::list<std::pair<int, int>>>(769);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash_key = key % n;
        for (auto &p:hash[hash_key]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        hash[hash_key].push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash_key = key % n;
        for (auto &p:hash[hash_key]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash_key = key % n;
        for (auto it = hash[hash_key].begin(); it != hash[hash_key].end(); it++) {
            if (it->first == key) {
                hash[hash_key].remove(*it);
                return;
            }
        }
    }
};

class Solution {
public:

    void test() {
        std::cout << "test start" << std::endl;
        MyHashMap *obj = new MyHashMap();
        obj->put(1, 2);
        int param_2 = obj->get(1);
        obj->remove(1);
        std::cout << "test start" << std::endl;
    }
};