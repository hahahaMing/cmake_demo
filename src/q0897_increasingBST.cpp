#include"tools.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr)return nullptr;
        TreeNode* lt = increasingBST(root->left);
        if(lt!=nullptr){
            TreeNode*dum = new TreeNode(0);
            dum->right = lt;
            while(lt->right!=nullptr)lt = lt->right;
            root->left = nullptr;
            lt->right = root;
            lt->right->right = increasingBST(root->right);
            root = dum->right;
            delete dum;
        }else{
            root->right = increasingBST(root->right);
        }
        return root;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    return 0;
}
