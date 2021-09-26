#include"tools.hpp"

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, 
vector<int>& nums2) {
        //动态规划，存当前i,j位置的最大连线数量
        int n1 = nums1.size(),n2 = nums2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        for(int i=0;i<n1;++i){
            for(int j=0;j<n2;++j){
                int before = 0;
                if(i!=0&&j!=0){
                    before = dp[i-1][j-1];
                }
                if(nums1[i]==nums2[j]){
                    dp[i][j] = before+1;
                }else{
                    dp[i][j] = before;
                    if(i!=0){
                        dp[i][j] = max(dp[i][j],dp[i-1]
[j]);
                    }
                    if(j!=0){
                        dp[i][j] = max(dp[i][j],dp[i]
[j-1]);
                    }
                }
            }

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
