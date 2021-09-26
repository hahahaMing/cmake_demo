#include"tools.hpp"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
