#include "tools.hpp"
using namespace std;

class Solution {
    struct cmp {
        bool operator()(vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return (a[1] > b[1]);
            return a[0] > b[0]; //小的放左边,即less
        }
    };

  public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, cmp>
            pq; //存所需时间与id
        int cur = 0, end = 0;
        int n = tasks.size();
        vector<int> rst;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (i < n)
                cur = tasks[i][0];
            else
                cur = end + 1;
            // 上一个任务结束了
            if (cur > end)
                end = 0;
            // 当前时间进入的任务
            while (i < n && tasks[i][0] == cur) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            //当前开始的任务
            if (end == 0) {
                rst.push_back(pq.top()[1]);
                end = cur + pq.top()[0] - 1;
                pq.pop();
            }
        }
        return rst;
    }
};
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<vector<int>> tasks;
    tasks = tools::string2matrixInt("[[19,13],[16,9],[21,10],[32,25],[37,4],[49,24],[2,15],[38,41],[37,34],[33,6],[45,4],[18,18],[46,39],[12,24]]");
    tools::printVectorInt(slt.getOrder(tasks));
    tasks = tools::string2matrixInt("[[1,2],[2,4],[3,2],[4,1]]");
    tools::printVectorInt(slt.getOrder(tasks));
    tasks = tools::string2matrixInt("[[7,10],[7,12],[7,5],[7,4],[7,2]]");
    tools::printVectorInt(slt.getOrder(tasks));

    clock_t t;
    t = clock(); //调用前时间

    // cout << slt.combinationSum4(v, 5); //调用函数A

    t = clock() - t;                                     //计算函数耗时
    printf("time=%lf s\n", ((float)t) / CLOCKS_PER_SEC); //转化为秒
    return 0;
}