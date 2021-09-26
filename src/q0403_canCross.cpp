#include "tools.hpp"

using namespace std;

class Solution {
  public:
    bool canCross(vector<int> &stones) {
        int n = stones.size();
        vector<unordered_set<int>> rcd(n); //存能到这个点需要的所有步数
        rcd[0].insert(0);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (rcd[j].find(i - j - 1) != rcd[j].end() ||
                    rcd[j].find(i - j) != rcd[j].end() ||
                    rcd[j].find(i - j + 1) != rcd[j].end()) {
                    rcd[i].insert(i - j);
                }
            }
        }
        return rcd.back().empty();
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    vector<int> st;
    st = {0,1,3,5,6,8}
    return 0;
}
