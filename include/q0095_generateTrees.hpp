//
// Created by ming on 2020/7/21.
//

#ifndef CMAKETEST_Q0095_GENERATETREES_HPP
#define CMAKETEST_Q0095_GENERATETREES_HPP

#endif //CMAKETEST_Q0095_GENERATETREES_HPP
#include"tools.hpp"
class Solution {
    std::vector<TreeNode*> subTree(std::vector<int> v){
        if (v.empty())return {nullptr};
        int len = v.size();
        std::vector<int> left, right;
        std::vector<TreeNode*> rst;
        for (auto i = v.begin(); i != v.end(); ++i) {
            if (i!=v.begin()) left.assign(v.begin(),i);
            else left = {};
            if (i!=v.end()-1)right.assign(i+1,v.end());
            else right = {};
            for(auto lr:subTree(left)){
                for(auto rr:subTree(right)){
                    TreeNode* root = new TreeNode(*i);
                    root->left = lr;
                    root->right = rr;
                    rst.push_back(root);
                }
            }
        }
        return rst;
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n==0)return {};
        std::vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        return subTree(v);
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        generateTrees(3);

    }
};