#include"tools.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right
(right) {}
 * };
 */
class BSTIterator {
    std::stack<TreeNode *> stk;//存非空节点

public:
    BSTIterator(TreeNode *root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        int rst = stk.top()->val;
        auto tmp_right_node = stk.top()->right;
        stk.pop();
        while (tmp_right_node){
            stk.push(tmp_right_node);
            tmp_right_node = tmp_right_node->left;
        }
        return rst;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */class Solution {
public:
    void test() {
        std::cout << "test start" << std::endl;
        auto root = tools::stringToTreeNode("[7, 3, 15, null, null, 9, 20]");
        BSTIterator *obj = new BSTIterator(root);
        std::cout << obj->next() << std::endl;
        std::cout << obj->next() << std::endl;
        std::cout << obj->hasNext() << std::endl;
        std::cout << obj->next() << std::endl;
        std::cout << obj->hasNext() << std::endl;
        std::cout << obj->next() << std::endl;
        std::cout << obj->hasNext() << std::endl;
        std::cout << obj->next() << std::endl;
        std::cout << obj->hasNext() << std::endl;

    }
};