//
// Created by ming on 2020/9/16.
//

#ifndef CMAKETEST_Q0226_INVERTTREE_HPP
#define CMAKETEST_Q0226_INVERTTREE_HPP

#endif //CMAKETEST_Q0226_INVERTTREE_HPP
#include"tools.hpp"
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};