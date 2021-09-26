#include "tools.hpp"

using namespace std;

class Solution {

  public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<pair<int, int>> rcd; //存和为first，数量为second的组合
        int rst = 0;
        for (int x : nums) {
            int len = rcd.size();
            for (int i = 1; i * x <= target; i++) {
                //在前面基础上加入
                for (int j = 0; j < len; j++) {
                    if (rcd[j].first + i * x == target) {
                        rst += pow(rcd[j].second + 1, i);
                    } else if (rcd[j].first + i * x < target) {
                        rcd.push_back(
                            {rcd[j].first + i * x, rcd[j].second + i});
                    }
                }
                //单独加入
                if (i * x == target)
                    rst++;
                else
                    rcd.push_back({i * x, i});
            }

        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> v;

    v = {1, 2, 3};

    clock_t t;
    t = clock(); //调用前时间

    cout << slt.combinationSum4(v, 5); //调用函数A

    t = clock() - t;                                     //计算函数耗时
    printf("time=%lf s\n", ((float)t) / CLOCKS_PER_SEC); //转化为秒
    return 0;
}
