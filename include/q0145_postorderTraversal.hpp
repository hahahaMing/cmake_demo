//
// Created by ming on 2020/9/29.
//

#ifndef CMAKETEST_Q0145_POSTORDERTRAVERSAL_HPP
#define CMAKETEST_Q0145_POSTORDERTRAVERSAL_HPP

#endif //CMAKETEST_Q0145_POSTORDERTRAVERSAL_HPP

#include"tools.hpp"

class Solution {
public:
    //递归
/*    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root== nullptr)return {};
        std::vector<int>  rst, tmp;
        rst = postorderTraversal(root->left);
        tmp = postorderTraversal(root->right);
        rst.insert(rst.end(),tmp.begin(),tmp.end());
        rst.push_back(root->val);
        return rst;
    }*/
    //迭代
    std::vector<int> postorderTraversal(TreeNode *root) {
        /*
         * 先存root.val然后先左后右入栈
         */
        if (root == nullptr)return {};
        std::stack<TreeNode *> stk;
        std::vector<int> rst;
        stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            rst.push_back(root->val);
            stk.pop();
            if (root->left != nullptr)stk.push(root->left);
            if (root->right != nullptr)stk.push(root->right);

        }
        std::reverse(rst.begin(), rst.end());
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
        root = tools::stringToTreeNode("[1,null,2,3]");
        tools::printVectorInt(postorderTraversal(root));

    }
};