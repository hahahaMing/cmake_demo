#include"tools.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * 
 */
class Solution {
    int rst;
    pair<int,int> mid(TreeNode* root){
        int l = root->val, r = root->val;
        if(root->left!=nullptr){
            auto pl = mid(root->left);
            rst = min(rst,root->val-pl.second);
            l = pl.first;
        }
        if(root->right!=nullptr){
            auto pr = mid(root->right);
            rst = min(rst,pr.first-root->val);
            r = pr.second;
        }
        cout<<l<<r<<endl;
        return {l,r
    }
public:
    int minDiffInBST(TreeNode* root) {
        rst = 100000;
    void test(){
        std::cout<<"test start"<<std::endl;
    }
};