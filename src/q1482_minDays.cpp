#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        //遍历一遍，建立{时间，位置}表
        //按时间排序
        //按时间遍历，更新区域数组
        int n = bloomDay.size();
        if (n < m * k)
            return -1;
        vector<vector<int>> rcd(n);
        for (int i = 0; i < n; i++) {
            rcd[i] = {bloomDay[i], i};
        }
        sort(rcd.begin(), rcd.end());
        int time = 0;
        vector<int> region(n, -1);
        for (auto &v : rcd) {
            if (time < v[0]) {
                //看能不能装好
                int st = 0, mm = m;
                while (st < n) {
                    while (st < n && region[st] == -1) {
                        st++;
                    }
                    mm -= (region[st] - st + 1) / k;
                    if (mm <= 0)
                        return time;
                    st = region[st] + 1;
                }

                time = v[0];
            }
            if (v[1] - 1 < 0 || region[v[1] - 1] == -1) {
                if (v[1] + 1 >= n || region[v[1] + 1] == -1) {
                    region[v[1]] = v[1]; //左右不相连
                } else {
                    region[v[1]] = region[v[1] + 1]; //右边相连
                    region[region[v[1]]] = v[1];
                }
            } else {
                if (v[1] + 1 >= n || region[v[1] + 1] == -1) {
                    region[v[1]] = region[v[1] - 1]; //左边相连
                    region[region[v[1]]] = v[1];
                } else {
                    region[region[v[1] - 1]] = region[v[1] + 1]; //左右相连
                    region[region[v[1] + 1]] = region[v[1] - 1];
                }
            }
        }
        int st = 0, mm = m;
        while (st < n) {
            while (st < n && region[st] == -1) {
                st++;
            }
            mm -= (region[st] - st + 1) / k;
            if (mm <= 0)
                return time;
            st = region[st] + 1;
        }
        return -1;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
