//
// Created by ming on 2020/9/25.
//

#ifndef CMAKETEST_Q0106_BUILDTREE_HPP
#define CMAKETEST_Q0106_BUILDTREE_HPP

#endif //CMAKETEST_Q0106_BUILDTREE_HPP
#include"tools.hpp"
class Solution {
public:
    TreeNode* buildTree(std::vector<int> inorder, std::vector<int> postorder) {
        if (inorder.empty())return nullptr;
        auto* root = new TreeNode(postorder.back());
        std::vector<int> lin,lpost,rin,rpost;
        int len = inorder.size(),llen=0,rlen=0;

        for (int i = 0; i < len; ++i) {
            if (inorder[i]==root->val){
                llen = i;
                rlen = len-1-i;
                break;
            }
        }
        if(llen!=0){
            lin.insert(lin.end(),inorder.begin(),inorder.begin()+llen);
            lpost.insert(lpost.end(),postorder.begin(),postorder.begin()+llen);
        }
        if (rlen!=0){
            rin.insert(rin.end(),inorder.begin()+llen+1,inorder.end());
            rpost.insert(rpost.end(),postorder.begin()+llen,postorder.end()-1);
        }
        root->left = buildTree(lin,lpost);
        root->right = buildTree(rin,rpost);
        return root;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int>  in ,po;
        in = {9,3,15,20,7};
        po = {9,15,7,20,3};
        tools::printTree(buildTree(in,po));

    }
};