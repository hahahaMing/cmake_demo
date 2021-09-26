//
// Created by ming on 2020/10/29.
//

#ifndef CMAKETEST_Q0129_SUMNUMBERS_HPP
#define CMAKETEST_Q0129_SUMNUMBERS_HPP

#endif //CMAKETEST_Q0129_SUMNUMBERS_HPP

#include"tools.hpp"

class Solution {
    int rst = 0;

    void travel(TreeNode *root, int up) {
        up = up * 10 + root->val;
        if (root->left) {
            travel(root->left, up);
        }
        if (root->right) {
            travel(root->right, up);
        }
        if (!root->left && !root->right) {
            rst += up;
        }
    }

public:
    int sumNumbers(TreeNode *root) {
        if(!root)return 0;
        rst = 0;
        travel(root, 0);
        return rst;
    }


    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
        root = tools::stringToTreeNode("[4,9,0,5,1]");
        std::cout << sumNumbers(root) << std::endl;
        root = tools::stringToTreeNode("[1,2,3]");
        std::cout << sumNumbers(root) << std::endl;
    }

};