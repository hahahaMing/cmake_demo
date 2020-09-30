//
// Created by ming on 2020/5/31.
//

#ifndef CMAKETEST_Q0101_ISSYMMETRIC_HPP
#define CMAKETEST_Q0101_ISSYMMETRIC_HPP

#endif //CMAKETEST_Q0101_ISSYMMETRIC_HPP

#include"tools.hpp"

class Solution {
    bool is_reverse(TreeNode *r1, TreeNode *r2) {
        if (r1 == nullptr ^ r2 == nullptr)return false;
        if (r1 == nullptr && r2 == nullptr)return true;
        if (r1->val != r2->val)return false;
        return is_reverse(r1->left, r2->right) && is_reverse(r1->right, r2->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)return true;
        return is_reverse(root->left, root->right);
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
        std::string s;

        s = "[1,2,2,3,4,4,4]";
        root = tools::stringToTreeNode(s);
        std::cout << isSymmetric(root) << std::endl;

    }
};