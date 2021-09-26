/*
 * @Author: your name
 * @Date: 2021-05-23 09:27:56
 * @LastEditTime: 2021-05-23 13:48:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1707_maximizeXor.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        // 建立一个树结构存nums，并且存当前节点后面的最小值
        sort(nums.begin(), nums.end());
        TreeNode *root = new TreeNode(0); // 32层
        for (int x : nums) {
            TreeNode *tmp = root;
            for (int i = 31; i >= 0; --i) {
                if (((x >> i) & 1) == 0) {
                    if (tmp->left == nullptr) {
                        tmp->left = new TreeNode(x);
                    }
                    tmp = tmp->left;
                } else {
                    if (tmp->right == nullptr) {
                        tmp->right = new TreeNode(x);
                    }
                    tmp = tmp->right;
                }
            }
        }
        // tools::printTree(root);
        //搜索
        int n = queries.size();
        vector<int> rst(n, -1);
        for (int i = 0; i < n; ++i) {
            TreeNode *tmp = root;
            int x = queries[i][0], m = queries[i][1];
            for (int j = 31; j >= 0; --j) {
                if (((x >> j) & 1) == 1) { // j位1
                    if (tmp->left != nullptr && tmp->left->val <= m) {
                        tmp = tmp->left;
                    } else if (tmp->right != nullptr && tmp->right->val <= m) {
                        x ^= (1 << j);
                        tmp = tmp->right;
                    } else {
                        x = -1;
                        break;
                    }
                } else { // j位0
                    if (tmp->right != nullptr && tmp->right->val <= m) {
                        x ^= (1 << j);
                        tmp = tmp->right;
                    } else if (tmp->left != nullptr && tmp->left->val <= m) {
                        tmp = tmp->left;
                    } else {
                        x = -1;
                        break;
                    }
                }
            }
            rst[i] = x;
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> nums;
    vector<vector<int>> queries;
    nums = tools::string2vectorInt("[0,1,2,3,4]");
    queries = tools::string2matrixInt("[[3,1],[1,3],[5,6]]");
    tools::printVectorInt(slt.maximizeXor(nums, queries));
    nums = tools::string2vectorInt("[5,2,4,6,6,3]");
    queries = tools::string2matrixInt("[[12,4],[8,1],[6,3]]");
    tools::printVectorInt(slt.maximizeXor(nums, queries));
    return 0;
}
