//
// Created by ming on 2020/11/24.
//

#ifndef CMAKETEST_Q0222_COUNTNODES_HPP
#define CMAKETEST_Q0222_COUNTNODES_HPP

#endif //CMAKETEST_Q0222_COUNTNODES_HPP

#include"tools.hpp"

class Solution {
    /**
     *
     * @param root
     * @param dl -1表示没有输入
     * @param dr -1表示没有输入
     * @return
     */
    int dfs(TreeNode *root, int dl, int dr) {
        if (root == nullptr)return 0;
        if (dl == -1) {
            auto tmp = root;
            dl = 0;
            while (tmp) {
                dl++;
                tmp = tmp->left;
            }
        }
        if (dr == -1) {
            auto tmp = root;
            dr = 0;
            while (tmp) {
                dr++;
                tmp = tmp->right;
            }
        }
        if (dl == 1)return 1;
        if (dl == dr)return (1 << dr) - 1;
        else return 1 + dfs(root->left, dl - 1, -1) + dfs(root->right, -1, dr - 1);
    }

public:
    int countNodes(TreeNode *root) {
        /*
         * 二分法
         * 对每个树
         * 先找到左下深度dl
         * 再找右下深度dr
         * if dl==dr return 2^dr-1
         * else return 1+ dfs(左孩子）+dfs(右孩子)
         */
        return dfs(root, -1, -1);
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
        root = tools::stringToTreeNode("[1,2,3,4,5,6]");
        tools::printTree(root);
        std::cout << countNodes(root) << std::endl;
        root = tools::stringToTreeNode("[1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6]");
        tools::printTree(root);
        std::cout << countNodes(root) << std::endl;
        root = tools::stringToTreeNode("[1]");
        tools::printTree(root);
        std::cout << countNodes(root) << std::endl;
        root = tools::stringToTreeNode("[]");
        tools::printTree(root);
        std::cout << countNodes(root) << std::endl;
    }
};