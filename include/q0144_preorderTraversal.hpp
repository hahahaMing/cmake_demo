//
// Created by ming on 2020/10/27.
//

#ifndef CMAKETEST_Q0144_PREORDERTRAVERSAL_HPP
#define CMAKETEST_Q0144_PREORDERTRAVERSAL_HPP

#endif //CMAKETEST_Q0144_PREORDERTRAVERSAL_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)return {};
        std::stack<TreeNode*> stk;
        std::vector<int> rst;
        stk.push(root);
        while (!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            rst.push_back(cur->val);
            if (cur->right)stk.push(cur->right);
            if (cur->left)stk.push(cur->left);
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        TreeNode* root;
        root = tools::stringToTreeNode("[1,2,3,4,5,6,7,89,4,31,5,71,64,321,54313,432,135321,5132,15]");
        tools::printTree(root);
        tools::printVectorInt(preorderTraversal(root));

    }
};