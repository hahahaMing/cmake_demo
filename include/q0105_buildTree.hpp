//
// Created by ming on 2020/5/22.
//

#ifndef CMAKETEST_Q0105_BUILDTREE_HPP
#define CMAKETEST_Q0105_BUILDTREE_HPP

#endif //CMAKETEST_Q0105_BUILDTREE_HPP

#include"tools.hpp"

class Solution {
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        //通过寻找父节点在两个数组的位置来递归
        //前序父节点在第一个位置
        //搜索中序父节点位置，父节点左为左子树的中序遍历，右边为右子树的中序遍历，同时得到左子树元素个数
        //故前序分布为 父节点+左子树前序遍历（左子树元素个数）+右子树前序遍历
        if (preorder.empty())return nullptr;
        int father = preorder[0];
        TreeNode *root = new TreeNode(father);
        auto iter = std::find(inorder.begin(), inorder.end(), father);
        int left_length = iter - inorder.begin();
        std::vector<int> left_p(preorder.begin() + 1, preorder.begin() + left_length + 1);
        std::vector<int> left_i(inorder.begin(), inorder.begin() + left_length);
        std::vector<int> right_p(preorder.begin() + left_length + 1, preorder.end());
        std::vector<int> right_i(inorder.begin() + left_length + 1, inorder.end());


        root->left = buildTree(left_p, left_i);
        root->right = buildTree(right_p, right_i);

        return root;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> p, i;
        //前序遍历 preorder = [3,9,20,15,7]
        //中序遍历 inorder = [9,3,15,20,7]
        p = {3, 9, 20, 15, 7};
        i = {9, 3, 15, 20, 7};
        tools::printTree(buildTree(p, i));


    }
};