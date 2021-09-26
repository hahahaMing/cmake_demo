/*
 * @Author: your name
 * @Date: 2021-04-18 10:05:53
 * @LastEditTime: 2021-09-12 20:39:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\contest.cpp
 */
#include "iostream"
#include "unordered_map"
#include "vector"
#include <algorithm>
using namespace std;
#include "tools.hpp"

typedef long long ll;

int main() {
    vector<vector<int>> properties;
    properties = tools::string2matrixInt("[[4,8],[3,6],[10,20],[15,30]]");
    vector<int> nextVisit;
    vector<int> vp,vn;
    vp = {-1,0,0,2};
    vn = {1,2,3,4};
    
    // Solution solution;
    unordered_map<ll,pair<ll,ll>>un;
    // un.insert(1,2,3);
    // un.insert(1,make_pair(2,3));
    un.insert(make_pair(1,std::make_pair(2,3)));
    // un.emplace(2,2,3);
    un.emplace(3,make_pair(2,3));
    un.emplace(make_pair(4,std::make_pair(2,3)));

    
    return 0;
}
