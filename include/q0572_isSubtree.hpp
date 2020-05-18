//
// Created by ming on 2020/5/7.
//

#ifndef CMAKETEST_Q0572_ISSUBTREE_HPP
#define CMAKETEST_Q0572_ISSUBTREE_HPP

#endif //CMAKETEST_Q0572_ISSUBTREE_HPP

#include"tools.hpp"

class Solution {
private:
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (s != nullptr) {
            if (t != nullptr && s->val == t->val)return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        } else return t == nullptr;
        return false;
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == nullptr)return t == nullptr;
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *s, *t;
        s = tools::stringToTreeNode("[1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2]");
        t = tools::stringToTreeNode("[1,null,1,null,1,null,1,null,1,null,1,2]");
        std::cout << isSubtree(s,t)<< std::endl;

    }
};