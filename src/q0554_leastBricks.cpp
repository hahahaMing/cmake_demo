#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        //记录缝的位置与个数，取出除了两端外的最多缝
        unordered_map<int, int> rcd;
        int width = 0;
        for (int x : wall[0])
            width += x;
        int max_gap = 0;
        for (auto &v : wall) {
            int last = 0;
            for (int &x : v) {
                x += last;
                last = x;
                if (rcd.find(x) == rcd.end())
                    rcd[x] = 1;
                else
                    rcd[x]++;
                if (rcd[x] > max_gap && x != width)
                    max_gap = rcd[x];
            }
        }
        return wall.size() - max_gap;
    }
};

// Start testing!
int main() {
    Solution slt;
    cout << "hello cmake!" << endl;
    auto walls = tools::string2matrixInt("[[1,1],[2],[1,1]]");
    tools::print2DVector(walls);
    cout << slt.leastBricks(walls) << endl;

    return 0;
}
