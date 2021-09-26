#include"tools.hpp"

using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len = group.size();
        vector<vector<vector<int>>> dp(len,vector<int>(minProfit+1));//存前i个工作可以获得j利润的方案个数
        // dp[i][j] = dp[i-1][j]+dp[i-1][j-]

    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
