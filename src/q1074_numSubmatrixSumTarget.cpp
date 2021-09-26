/*
 * @Author: your name
 * @Date: 2021-05-29 15:37:00
 * @LastEditTime: 2021-05-29 16:05:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1074_numSubmatrixSumTarget.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> rcd(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rcd[i + 1][j + 1] =
                    rcd[i][j + 1] + rcd[i + 1][j] - rcd[i][j] + matrix[i][j];
            }
        }
        int rst = 0;
        for (int x2 = 0; x2 < n; x2++) {
            for (int x1 = 0; x1 <= x2; x1++) {
                for (int y2 = 0; y2 < m; y2++) {
                    for (int y1 = 0; y1 <= y2; y1++) {
                        if (rcd[x2 + 1][y2 + 1] + rcd[x1][y1] -
                                rcd[x2 + 1][y1] - rcd[x1][y2 + 1] ==
                            target) {
                            rst++;
                        }
                    }
                }
            }
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<vector<int>> matrix;
    matrix = tools::string2matrixInt("[[0,1,0],[1,1,1],[0,1,0]]");
    cout << slt.numSubmatrixSumTarget(matrix, 0) << endl;

    return 0;
}
