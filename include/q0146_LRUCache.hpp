//
// Created by ming on 2020/5/24.
//

#ifndef CMAKETEST_Q0146_LRUCACHE_HPP
#define CMAKETEST_Q0146_LRUCACHE_HPP

#endif //CMAKETEST_Q0146_LRUCACHE_HPP

#include"tools.hpp"

class LRUCache {
    int cpt;
    std::map<int,int> map;
    std::vector<int> order;
    void vector_delete(std::vector<int> &v,int k){
        for(std::vector<int>::iterator iter=v.begin();iter!=v.end();iter++){        //从vector中删除指定的某一个元素
            if(*iter==k){
                v.erase(iter);
                break;
            }
        }

    }
public:
    LRUCache(int capacity) {
        cpt = capacity;
    }

    int get(int key) {
        if (map.find(key)!=map.end()){
            //把这个key挪到最近使用
            vector_delete(order,key);
            order.push_back(key);
            return map[key];
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        /*
         * 如果不存在
         * 判断是否超缓存
         * 如果超了
         * 先删除最远的那个
         * 然后填入新的
         *
         * 其他情况直接改
         */
        if (map.find(key)!=map.end()){
            //填入
            map[key] = value;
            //更新
            vector_delete(order,key);
            order.push_back(key);
        }else{
            if (map.size()==cpt) {
                map.erase(order[0]);
                //先删除最远的那个
                order.erase(order.begin());

            }
            //然后填入新的
            map[key]=value;
            order.push_back(key);
        }
    }
};

class Solution {
public:

    void test() {
        std::cout << "test start" << std::endl;
        LRUCache cache = *new LRUCache( 2 /* 缓存容量 */ );

        cache.put(1, 1);
        cache.put(2, 2);
        cache.get(1);       // 返回  1
        cache.put(3, 3);    // 该操作会使得密钥 2 作废
        cache.get(2);       // 返回 -1 (未找到)
        cache.put(4, 4);    // 该操作会使得密钥 1 作废
        cache.get(1);       // 返回 -1 (未找到)
        cache.get(3);       // 返回  3
        cache.get(4);       // 返回  4

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */