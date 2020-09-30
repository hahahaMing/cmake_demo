//
// Created by ming on 2020/8/31.
//

#ifndef CMAKETEST_Q0841_CANVISITALLROOMS_HPP
#define CMAKETEST_Q0841_CANVISITALLROOMS_HPP

#endif //CMAKETEST_Q0841_CANVISITALLROOMS_HPP
#include"tools.hpp"
class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int doors_opened = 0;
        int N = rooms.size();
        std::vector<bool> doors(N,false);
        std::queue<int> q;
        q.push(0);

        while (!q.empty()){
            int key = q.front();
            if (!doors[key]){
                doors[key] = true;
                doors_opened++;
//                if (doors_opened==N)return true;
            }
            for(int k:rooms[key]){
                if (!doors[k]){
                    q.push(k);
                }
            }
            q.pop();
        }
        if (doors_opened==N)return true;
        else return false;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};