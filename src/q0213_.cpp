#include"tools.hpp"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        //分偷0和不偷0动态规划
        //偷0，从2开始取到倒数第2位
        int get_cur = nums[0],no_cur = nums[0];
        for(int i = 2;i<n-1;i++){
            int tmp = max(get_cur,no_cur);
            get_cur = no_cur+nums[i];
            no_cur = tmp;
        }
        int rst = max(get_cur,no_cur);
        //不偷0，从1取到最后
        get_cur = 0,no_cur = 0;
        for(int i=1;i<n;i++){
            int tmp = max(get_cur,no_cur);
            get_cur = no_cur+nums[i];
            no_cur = tmp;
        }
        rst = max(rst,max(get_cur,no_cur));
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution solution;
    vector<int> vec;
    vec = {1,2,1,3,100};
    cout << solution.rob(vec) << endl;
    return 0;
}
