#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int minimumTimeRequired(vector<int> &jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);//x表示i后面有几个零，y表示第x位工作不做的情况
            sum[i] = sum[y] + jobs[x];//表示 i状态工作总量为 y状态工作总量 + 第 x位工作量
        }

        vector<vector<int>> dp(k, vector<int>(1 << n));
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }//只有 1位工人，最小个人工时为总工时

        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) {//x = (x - 1) & j 迭代结果为 j 中位上为 1的不同组合，挺巧的
                    //表示x状态工作量给一个人，剩下i-1个人完成j-x工作量，最后得到一个i个人j情况的最小个人工时
                    minn = min(minn, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = minn;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> jobs;
    jobs = {1, 2, 4, 7, 8};
    cout << slt.minimumTimeRequired(jobs, 2) << endl;
    return 0;
}
