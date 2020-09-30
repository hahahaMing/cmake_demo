//
// Created by ming on 2020/8/3.
//

#ifndef CMAKETEST_Q0114_FLATTEN_HPP
#define CMAKETEST_Q0114_FLATTEN_HPP

#endif //CMAKETEST_Q0114_FLATTEN_HPP

#include"tools.hpp"

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *current = root;
        while (current != nullptr) {
            TreeNode *l = current->left, *r = current->right, *lend = l;
            if (l != nullptr) {
                while (lend->right != nullptr)lend = lend->right;//找到左节点的右末尾
                lend->right = r;//把current的右节点接在左节点右末尾
                current->right = l;//把current左节点接到右边
                current->left = nullptr;//清空current左节点
            }
            current = current->right;//指向下一个节点
        }
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};