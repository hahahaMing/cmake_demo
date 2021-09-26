#include "tools.hpp"

using namespace std;

class Solution {

    int my_sum(vector<vector<int>> &rcd, int a, int b, int c, int d) {
        return rcd[b + 1][d + 1] + rcd[a][c] - (rcd[b + 1][c] + rcd[a][d + 1]);
    }

  public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int m = matrix[0].size(), n = matrix.size();
        vector<vector<int>> rcd(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rcd[i + 1][j + 1] =
                    rcd[i + 1][j] + rcd[i][j + 1] + matrix[i][j] - rcd[i][j];
            }
        }

        int rst = 0;
        return 0;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution sl;
    vector<vector<int>> mtr(100,vector<int>(100,1));
    // tools::print2DVector(mtr);
    cout << sl.maxSumSubmatrix(mtr,2) << endl;
    return 0;
}
