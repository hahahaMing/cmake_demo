//
// Created by ming on 2020/12/22.
//

#ifndef CMAKETEST_Q0103_ZIGZAGLEVELORDER_HPP
#define CMAKETEST_Q0103_ZIGZAGLEVELORDER_HPP

#endif //CMAKETEST_Q0103_ZIGZAGLEVELORDER_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)return {};
        bool normal_order = true;
        std::stack<TreeNode *> stk1, stk2;
        std::vector<std::vector<int>> rst;
        stk1.push(root);
        while (!stk1.empty() || !stk2.empty()) {
            int len = stk1.empty() ? stk2.size() : stk1.size();
            std::vector<int> tmp_vec(len, 0);
            if (normal_order) {
                for (int i = 0; i < len; ++i) {
                    TreeNode *tmp_root = stk1.top();
                    stk1.pop();
                    tmp_vec[i] = tmp_root->val;
                    if (tmp_root->left)stk2.push(tmp_root->left);
                    if (tmp_root->right)stk2.push(tmp_root->right);
                }
            } else {
                for (int i = 0; i < len; ++i) {
                    TreeNode *tmp_root = stk2.top();
                    stk2.pop();
                    tmp_vec[i] = tmp_root->val;
                    if (tmp_root->right)stk1.push(tmp_root->right);
                    if (tmp_root->left)stk1.push(tmp_root->left);
                }
            }
            normal_order = !normal_order;
            rst.push_back(tmp_vec);
        }
        return rst;
    }


    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
        root = tools::stringToTreeNode("[3,9,20,null,null,15,7]");
        tools::printTree(root);
        tools::print2DVector(zigzagLevelOrder(root));
        root = tools::stringToTreeNode("[1,2,3,4,null,null,5]");
        tools::printTree(root);
        tools::print2DVector(zigzagLevelOrder(root));



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }

};