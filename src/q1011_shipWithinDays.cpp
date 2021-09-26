#include "tools.hpp"

using namespace std;

class Solution {
  public:
    vector<float> test(vector<float> &vec) {
        if (vec.empty())
            return {};
        int n = vec.size();
        int lp = -1, ln = -1;
        float po = 1, ng = -1;
        float maxp = vec[0];
        int rstl = 0, rstr = 0;
        for (int i = 0; i < n; ++i) {
            if (vec[i] >= 0) { //正
                if (po == 0) {
                    po = vec[i];
                    lp = i;
                    ng *= vec[i];
                    if (ln == -1)
                        ln = i;
                } else {
                    po *= vec[i];
                    if (lp == -1)
                        lp = i;
                    ng *= vec[i];
                    if (ln == -1)
                        ln = i;
                }
            } else { //负
                po *= vec[i];
                ng *= vec[i];
                if (lp == -1)
                    lp = i;
                if (ln == -1)
                    ln = i;        
                swap(po, ng);
                swap(lp, ln);
                if (ng == 0) {
                    ng = -1;
                    ln = -1;
                }
            }
            if (lp != -1) {
                if (po > maxp) {
                    rstl = lp;
                    rstr = i;
                }
            }
        }
        vector<float> rst;
        for (int i = rstl; i <= rstr; ++i) {
            rst.push_back(vec[i]);
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<float> vec, ret;
    vec = {-2.5, 4, 0, 3, 0.5, 8, -1, 1, 2, 3};
    ret = slt.test(vec);
    int a;
    return 0;
}
