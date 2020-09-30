//
// Created by ming on 2020/9/14.
//

#ifndef CMAKETEST_Q0094_INORDERTRAVERSAL_HPP
#define CMAKETEST_Q0094_INORDERTRAVERSAL_HPP

#endif //CMAKETEST_Q0094_INORDERTRAVERSAL_HPP

#include"tools.hpp"

class Solution {
public:
//    std::vector<int> inorderTraversal(TreeNode* root) {
//        if (root == nullptr)return {};
//        std::vector<int> left,right;
//        left = inorderTraversal(root->left);
//        right = inorderTraversal(root->right);
//        left.push_back(root->val);
//        left.insert(left.end(),right.begin(),right.end());
//        return left;
//    }
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::stack<TreeNode*> stk;
        std::vector<int> rst;
        stk.push(root);
        bool back = false;
        while (!stk.empty()){
            TreeNode *tmp = stk.top();
            if (tmp == nullptr){
                stk.pop();
            }else if(tmp->left== nullptr||back){
                rst.push_back(tmp->val);
                stk.pop();
                back = true;
                if (tmp->right!= nullptr){
                    stk.push(tmp->right);
                    back = false;
                }
            }else{
                stk.push(tmp->left);
                back = false;

            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        TreeNode *root;
        root = tools::stringToTreeNode("[1,null,2,3]");
        tools::printVectorInt(inorderTraversal(root));


    }
};