//
// Created by ming on 2020/10/12.
//

#ifndef CMAKETEST_Q0530_GETMINIMUMDIFFERENCE_HPP
#define CMAKETEST_Q0530_GETMINIMUMDIFFERENCE_HPP

#endif //CMAKETEST_Q0530_GETMINIMUMDIFFERENCE_HPP

#include"tools.hpp"

class Solution {
    int rst;

    void dfs(TreeNode *root) {
        if (root->left){
            rst = std::min(rst, std::abs(root->val - root->left->val));
            dfs(root->left);
        }
        if (root->right){
            rst = std::min(rst, std::abs(root->val - root->right->val));
            dfs(root->right);
        }
    }
public:
    int getMinimumDifference(TreeNode *root) {
        std::stack<TreeNode*> stk;
        stk.emplace(root);
        std::vector<int> vec;
        while (!stk.empty()){
            root = stk.top();
            stk.pop();
            vec.push_back(root->val);
            if (root->left)stk.push(root->left);
            if (root->right)stk.push(root->right);
        }
        std::sort(vec.begin(),vec.end());
        int rst = vec[1]-vec[0],n=vec.size();
        for (int i = 2; i < n; ++i) {
            if (vec[i]-vec[i-1]<rst)rst = vec[i]-vec[i-1];
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode* root;
        std::string s;
        s = "[1,null,3,2]";
        root = tools::stringToTreeNode(s);
        std::cout << getMinimumDifference(root) << std::endl;
        s = "[236,104,701,null,227,null,911]";
        root = tools::stringToTreeNode(s);
        tools::printTree(root);
        std::cout << getMinimumDifference(root) << std::endl;
    }
};