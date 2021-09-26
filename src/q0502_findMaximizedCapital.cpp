/*
 * @Author: your name
 * @Date: 2021-09-08 15:06:10
 * @LastEditTime: 2021-09-08 15:43:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0502_findMaximizedCapital.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital) {
        //按利润排序，相同利润按成本排序，都是升序
        int n = profits.size();
        vector<pair<int,int>> rcd(n);
        for (int i = 0; i < n; ++i) {
            rcd[i] = {capital[i],profits[i]};
        }
        sort(rcd.begin(), rcd.end());
        // 从利润小的开始遍历，往后肯定不会再看利润更小的了，除非没更大的项目了
        // 记录当前能做的利润最大的位置，存一个优先队列，每停下来一步就去掉一个顶部
        priority_queue<int> pq;
        int j = 0;
        for (int i = 0; i < k; ++i) {
            while (j < n && rcd[j].first <= w) {
                pq.push(rcd[j].second);
                j++;
            }
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    cout << slt.findMaximizedCapital(2, 0, profits, capital) << endl;

    return 0;
}
