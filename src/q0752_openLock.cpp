#include "tools.hpp"

using namespace std;

class Solution {
    vector<int> rcd;
    vector<int> get_nears(int start_point) {
        int a, b, c, d;
        a = start_point / 1000;
        b = start_point / 100 - a * 10;
        c = start_point / 10 - a * 100 - b * 10;
        d = start_point - a * 1000 - b * 100 - c * 10;
        return {
            a = 0 ? start_point + 9000 : start_point - 1000,
            a = 0 ? start_point + 9000 : start_point - 1000,
        };
    }

    void dfs(int start_point) {
        if (rcd[start_point] == -1)
            return;
    }

  public:
    int openLock(vector<string> &deadends, string target) {
        rcd = vector<int>(10000, -2); // -2 means waiting for input
        rcd[0] == 0;
        for (auto s : deadends) {
            rcd[stoi(s)] = -1; // -1 means dead
        }
        dfs(0);
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
