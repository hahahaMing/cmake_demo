#include"tools.hpp"

class Solution {
    int n, m;

    int flat(std::vector<std::vector<int>> &matrix, int x) {
        return matrix[x / m][x % m];
    }

public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        if (matrix.empty() || target < matrix[0][0] || target > matrix.back().back())return false;
        //二分
        n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (flat(matrix,mid)==target)return true;
            if (flat(matrix, mid) > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;
    }
};