//
// Created by ming on 2020/11/4.
//

#ifndef CMAKETEST_Q0057_INSERT_HPP
#define CMAKETEST_Q0057_INSERT_HPP

#endif //CMAKETEST_Q0057_INSERT_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
        if (intervals.empty())return {newInterval};
        auto it = intervals.begin();
        std::vector<std::vector<int>> rst;
        while (it != intervals.end()) {
            if ((*it)[1] >= newInterval[0])break;
            it++;
        }
        rst.insert(rst.end(), intervals.begin(), it);
        if (it==intervals.end()){
            rst.push_back(newInterval);
            return rst;
        }
        if ((*it)[0] < newInterval[0] && newInterval[0] <= (*it)[1])newInterval[0] = (*it)[0];
        auto last_it = it;
        while (it != intervals.end()) {
            if ((*it)[0] > newInterval[1])break;
            last_it = it;
            it++;
        }
        if ((*last_it)[1] > newInterval[1] && newInterval[1] >= (*last_it)[0])newInterval[1] = (*last_it)[1];
        rst.push_back(newInterval);
        rst.insert(rst.end(), it, intervals.end());
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> intervals;
        std::vector<int> newInterval;
//        intervals = tools::string2matrixInt("[[1,2],[3,5],[6,7],[8,10],[12,16]]");
//        newInterval = {4, 8};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {2, 3};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {6, 8};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {2, 8};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {8, 13};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {2, 13};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {-2, -1};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {50, 100};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {2, 28};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {2, 23};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {8, 23};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[0,5],[10,15],[20,25],[30,35],[40,45]]");
//        newInterval = {8, 18};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[[1,5],[6,8]]");
//        newInterval = {5, 6};
//        tools::print_matrix(insert(intervals, newInterval));
//        intervals = tools::string2matrixInt("[]");
//        newInterval = {5, 7};
//        tools::print_matrix(insert(intervals, newInterval));
        intervals = tools::string2matrixInt("[[1,5]]");
        newInterval = {6,8};
        tools::print_matrix(insert(intervals, newInterval));
    }
};