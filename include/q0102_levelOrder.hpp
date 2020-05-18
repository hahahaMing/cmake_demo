//
// Created by ming on 2020/5/13.
//

#ifndef CMAKETEST_Q0102_LEVELORDER_HPP
#define CMAKETEST_Q0102_LEVELORDER_HPP

#endif //CMAKETEST_Q0102_LEVELORDER_HPP

#include "tools.hpp"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root== nullptr)return {{}};
        //建两个队列，一个记录层序遍历，另一个记录节点层数
        std::queue<TreeNode *> q;
        std::queue<int> d;
        std::vector<std::vector<int>> rst={};
        q.push(root);
        d.push(0);
        while (!q.empty()){
            if (q.front()->left){
                q.push(q.front()->left);
                d.push(d.front()+1);
            }
            if (q.front()->right){
                q.push(q.front()->right);
                d.push(d.front()+1);
            }
            if (d.front()>=rst.size()){
                rst.push_back({q.front()->val});
            } else{
                rst[d.front()].push_back(q.front()->val);
            }
            q.pop();
            d.pop();
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        TreeNode *t;

//        std::vector<std::vector<int>> test = {{1,2},{2}};
//        tools::print2DVector(test);
        t = tools::stringToTreeNode("[3,9,20,null,null,15,7]");
        tools::print2DVector(levelOrder(t));
    }

};