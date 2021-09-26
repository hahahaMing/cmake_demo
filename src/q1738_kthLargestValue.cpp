#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = i > 0 && j > 0 ? matrix[i - 1][j - 1] : 0,
                    b = i > 0 ? matrix[i - 1][j] : 0,
                    c = j > 0 ? matrix[i][j - 1] : 0;
                matrix[i][j] ^= a ^ b ^ c;
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<vector<int>> matrix;
    int k;
    matrix = tools::string2matrixInt("[[5,2],[1,6]]");
    k = 1;
    cout << slt.kthLargestValue(matrix,k) << endl;

    return 0;
}
