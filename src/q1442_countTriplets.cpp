#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        int rst = 0;
        for (int k = 1; k < n; k++) {
            arr[k] ^= arr[k - 1];
            for (int j = 1; j <= k; ++j) {
                for (int i = 0; i < j; ++i) {
                    if (i == 0) {
                        if (arr[j - 1] == (arr[j - 1] ^ arr[k]))
                            rst++;
                    } else {
                        if ((arr[j - 1] ^ arr[i - 1]) == (arr[j - 1] ^ arr[k]))
                            rst++;
                    }
                }
            }
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
