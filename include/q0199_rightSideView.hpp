//
// Created by ming on 2020/4/22.
//

#ifndef CMAKETEST_Q0199_RIGHTSIDEVIEW_HPP
#define CMAKETEST_Q0199_RIGHTSIDEVIEW_HPP

#endif //CMAKETEST_Q0199_RIGHTSIDEVIEW_HPP

#include "tools.hpp"


class Solution {
private:
    //递归记录当前深度和vector
    /**
     *
     * @param pNode 当前节点指针
     * @param depth 当前节点深度
     * @param vec 当前记录的右视图vector
     * 初始为（root,1,{})
     */
    void myDFS(TreeNode *pNode, int depth, std::vector<int> &vec) {
        if (pNode == NULL) return;
        if (depth > vec.size()) vec.push_back(pNode->val);
        myDFS(pNode->right, depth + 1, vec);
        myDFS(pNode->left, depth + 1, vec);
    }

public:
    std::vector<int> rightSideView(TreeNode *root) {
        //从右向左DFS，时刻记录深度，当深度更新，把当前值push到vector中
        std::vector<int> rsv = {};
        myDFS(root, 1, rsv);
        return rsv;
    }

    void test() {
        std::cout << "test start" << std::endl;
        {
            std::string s = "[1,2,3,null,5,null,4]";
            auto root = tools::stringToTreeNode(s);
            tools::printVectorInt(rightSideView(root));
        }
        {
            std::string s = "[1,2,3,null,5]";
            auto root = tools::stringToTreeNode(s);
            tools::printVectorInt(rightSideView(root));
        }
        {
            std::string s = "[]";
            auto root = tools::stringToTreeNode(s);
            tools::printVectorInt(rightSideView(root));
        }


    }
};