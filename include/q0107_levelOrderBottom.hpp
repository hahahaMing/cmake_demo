//
// Created by ming on 2020/9/6.
//

#ifndef CMAKETEST_Q0107_LEVELORDERBOTTOM_HPP
#define CMAKETEST_Q0107_LEVELORDERBOTTOM_HPP

#endif //CMAKETEST_Q0107_LEVELORDERBOTTOM_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        if (root == nullptr)return {};
        std::vector<std::vector<int>> v = {{}}, rst;
        std::queue<TreeNode *> q;
        std::queue<int> depth;
        TreeNode *temp;
        int td;
        q.push(root);
        depth.push(0);

        while (!q.empty()) {
            temp = q.front();
            td = depth.front();
            if (temp != nullptr) {
                q.push(temp->left);
                q.push(temp->right);
                depth.push(td + 1);
                depth.push(td + 1);
                v[td].push_back(temp->val);
            }
            q.pop();
            depth.pop();
            if (td < depth.front())
                v.emplace_back();
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            if (!v[i].empty())rst.emplace_back(v[i]);
        }


        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string tree;
        tree = "[3,9,20,null,null,15,7]";
        TreeNode *root;
        root = tools::stringToTreeNode(tree);
        tools::printTree(root);
//        std::vector<std::vector<int>> v = levelOrderBottom(root);
//        for (int i = 0; i < v.size(); ++i) {
//            for (int j = 0; j < v[0].size(); ++j) {
//                std::cout << v[i][j]<<'\t';
//            }
//            std::cout<<std::endl;
//        }


        tools::print2DVector(levelOrderBottom(root));

    }
};