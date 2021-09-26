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
    vector<int> leafs(TreeNode *root) {
        if (root == nullptr)
            return {};
        if (root->left == nullptr && root->right == nullptr)
            return {root->val};
        vector<int> rst = leafs(root->left), tmp = leafs(root->right);
        rst.insert(rst.end(), tmp.begin(), tmp.end());
        return rst;
    }

  public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> v1 = leafs(root1), v2 = leafs(root2);
        int n = v1.size();
        if (v2.size() != n)
            return false;
        for (int i = 0; i < n; ++i) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
};
// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
