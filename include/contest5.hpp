//
// Created by ming on 2021/4/5.
//

#ifndef MAIN_CPP_CONTEST5_HPP
#define MAIN_CPP_CONTEST5_HPP

#endif //MAIN_CPP_CONTEST5_HPP

#include"tools.hpp"

class Zoom {
    int task_time;

public:
    std::vector<int> sections;

    Zoom(std::vector<int> sec, int time) {
        sections = sec;
        task_time = time;
    }

    bool empty() {
        return task_time == 0;
    }

    int get_time() {
        return task_time;
    }


    void intersect(Zoom &z2) {
        std::vector<int> inters, others, sec2 = z2.sections;
        //相交
        int l1 = sections.size(), l2 = sec2.size();
        bool last_is_head = false;//上一个数是不是一个区间的开头
//        bool this_is_head = true;
        int i1 = 0,i2= 0,side1,side2;
        while (true){
            side1 = sections[i1];
            side2 = sec2[i2];
            if (l1<l2)
        }







        //取交集与之外的集合

        //交集内尽量填满

        //交集填满后还有工时剩余就放到另一个空间中

        //z1表示交集

        //z2表示余下空间
    }

};


class Solution {


    //取交集
    int processTasks(std::vector<std::vector<int>> &tasks) {
        std::vector<Zoom> rcd;
        rcd.push_back(Zoom({tasks[0][0], tasks[0][1]}, tasks[0][2]));


        int rst = 0;
        for (auto &it:rcd) {
            rst += it.get_time();
        }
        return rst;


    }


public:

    void test() {
        std::vector<std::vector<int>> tasks;
        tasks = tools::string2matrixInt("[[1,3,2],[2,5,3],[5,6,2]]");
        std::cout << processTasks(tasks) << std::endl;


    }
};