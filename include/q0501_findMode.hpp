//
// Created by ming on 2020/9/24.
//

#ifndef CMAKETEST_Q0501_FINDMODE_HPP
#define CMAKETEST_Q0501_FINDMODE_HPP

#endif //CMAKETEST_Q0501_FINDMODE_HPP
#include"tools.hpp"
class Solution {
    std::pair<std::vector<int>,int>dfs(TreeNode* root) {
        if (root== nullptr){
            return std::pair<std::vector<int>,int>({},0);
        }
        std::pair<std::vector<int>,int>l,r,rst;
        l = dfs(root->left);r = dfs(root->right);
        if (l.first.back()==root->val&&r.first.back()==root->val){
            
        }else if (l.first.back()==root->val){

        }else if (r.first.back()==root->val){

        }else{
            if (l.second>r.second){
                rst = l;
            }else if (l.second==r.second){
                rst.first = l.first;
                rst.first.insert(rst.first.end(),r.first.begin(),r.first.end());
                rst.second = l.second+.second;
            }else{
                rst = r;
            }
        }

    }


public:
    std::vector<int> findMode(TreeNode* root) {

    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};