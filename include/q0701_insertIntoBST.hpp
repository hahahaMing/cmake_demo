//
// Created by ming on 2020/9/30.
//

#ifndef CMAKETEST_Q0701_INSERTINTOBST_HPP
#define CMAKETEST_Q0701_INSERTINTOBST_HPP

#endif //CMAKETEST_Q0701_INSERTINTOBST_HPP

#include"tools.hpp"

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        /*
         * 先往右边插，不行就往左边插
         */
        if (root == nullptr)return new TreeNode(val);
        TreeNode *rst = root;
        TreeNode *tmp;
        while (root != nullptr) {
            tmp = root;
            if (val > root->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        if (tmp->val < val) {
            tmp->right = new TreeNode(val);
            return rst;
        }
        root = rst;
        while (root != nullptr) {
            tmp = root;
            if (val > root->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        tmp->left = new TreeNode(val);
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
//        root= tools::stringToTreeNode("[5,2,7,1,4]");
//        tools::printTree(insertIntoBST(root,3));
////        root= tools::stringToTreeNode("[8,null,55,39,null,11,null,null,23,null,null]");
////        tools::printTree(root);
//        tools::printTree(insertIntoBST(root,17));
        root = tools::stringToTreeNode("[]");
        tools::printTree(insertIntoBST(root, 3));

    }
};