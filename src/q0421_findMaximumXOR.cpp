#include "tools.hpp"

using namespace std;

class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        vector<ListNode *> rcd(32, nullptr);
        int rst = 0;
        for (int x : nums) {
            ListNode *get_pair = nullptr;
            for (int i = 31; i >= 0; --i) {
                if (get_pair == nullptr) {
                    if (x & (1 << i) == 0) {
                        if (rcd[i] == nullptr) {
                            continue;
                        } else {
                            get_pair = rcd[i];
                            x ^= (get_pair->val << i);
                        }
                    }
                } else {
                    if (x & (1 << i) == 0) {
                        if (get_pair->right == nullptr) {
                            get_pair = get_pair->left;
                            x ^= (get_pair->val << i);
                        } else {
                            get_pair = get_pair
                        }
                    } else {
                    }
                }
            }
        }
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;

    return 0;
}
