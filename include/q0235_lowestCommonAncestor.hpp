//
// Created by ming on 2020/9/27.
//

#ifndef CMAKETEST_Q0235_LOWESTCOMMONANCESTOR_HPP
#define CMAKETEST_Q0235_LOWESTCOMMONANCESTOR_HPP

#endif //CMAKETEST_Q0235_LOWESTCOMMONANCESTOR_HPP
#include"tools.hpp"
class Solution {
    bool is_sub(TreeNode* root, TreeNode* t){
        if (root== nullptr)return false;
        if (root==t)return true;
        return is_sub(root->left,t)||is_sub(root->right,t);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = p->val,r = q->val;
        if (l>r) l = q->val,r = p->val;
        while (root!= nullptr){
            if (root->val>=l&&root->val<=r)return root;
            if (root->val<l)root = root->right;
            if (root->val>r)root = root->left;
        }
        return root;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};