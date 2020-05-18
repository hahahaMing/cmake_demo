//
// Created by ming on 2020/5/5.
//

#ifndef CMAKETEST_Q0098_ISVALIDBST_HPP
#define CMAKETEST_Q0098_ISVALIDBST_HPP

#endif //CMAKETEST_Q0098_ISVALIDBST_HPP

#include"tools.hpp"

class Solution {
    int MIN = -2147483647, MAX = -MIN;

private:
    bool recursion(TreeNode *root, int max, int min, bool hmax=true, bool hmin=true) {
        if (!root)return true;
        if (root->left) {
            if (root->left->val >= root->val) return false;
            if (hmin){
                if (min>=root->left->val)return false;
                if (!recursion(root->left,root->val,min))return false;
            }else{
                if (!recursion(root->left,root->val,0,true,false))return false;
            }
        }
        if (root->right) {
            if (root->right->val<=root->val)return false;
            if (hmax){
                if (max<=root->right->val)return false;
                if (!recursion(root->right,max,root->val))return false;
            }else{
                if (!recursion(root->right,0,root->val, false,true))return false;
            }
        }
        return true;
    }

    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) return true;
        if (root -> val <= lower || root -> val >= upper) return false;
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }

public:
    bool isValidBST(TreeNode *root) {
//        return recursion(root,0,0,false,false);
        return helper(root, LONG_MIN, LONG_MAX);
    }


    void test() {
        std::cout << "test start" << std::endl;

        TreeNode *root;
//        root= tools::stringToTreeNode("[5,1,4,null,null,3,6]");
//        std::cout << isValidBST(root) << std::endl;
//
//        root = tools::stringToTreeNode("[0,null,1]");
//        std::cout << isValidBST(root) << std::endl;
//
        root = tools::stringToTreeNode("[1,-2147483648,2147483647]");
        std::cout << isValidBST(root) << std::endl;

//        root = tools::stringToTreeNode("[3,1,5,0,2,4,6,null,null,null,3]");
//        std::cout << (LONG_MIN>=-2147483648)<<(2147483647>= LONG_MAX)<< std::endl;
    }
};