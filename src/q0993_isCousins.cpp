#include "tools.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    bool isCousins(TreeNode *root, int x, int y) {
        /**
         * 广度优先搜索
         * 到某节点发现xy同父亲，返回false
         * 否则一轮搜索非同时发现xy返回false
         * 同时发现返回true
         * */
        if (root == nullptr)
            return false;
        queue<TreeNode *> que;
        que.push(root);
        bool findx = false;
        bool findy = false;
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; ++i) {
                auto tmp = que.front();
                if (tmp->val == x)
                    findx = true;
                if (tmp->val == y)
                    findy = true;
                if (tmp->left != nullptr)
                    que.push(tmp->left);
                if (tmp->right != nullptr)
                    que.push(tmp->right);
                if (tmp->left != nullptr && tmp->right != nullptr) {
                    if (tmp->left->val == x && tmp->right->val == y)
                        return false;
                    if (tmp->left->val == y && tmp->right->val == x)
                        return false;
                }
                que.pop();
            }
            if (findx != findy)
                return false;
            if (findx && findy)
                return true;
        }
        return false;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
