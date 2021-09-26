#include"tools.hpp"

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int rst = 0;
        for(int i=0;i<32;++i){
            int c0=0,c1=0;
            for(int x:nums){
                (x>>i)&1?c1++:c0++;
            }
            rst+=c0*c1;
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
