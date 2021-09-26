#include"tools.hpp"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        int a = n & 0b01010101010101010101010101010101;
        if(a!=n)return false;
        if((a&(a-1))==0){
            return true;
        }
        return false;
    }
        if(n<=0)return false;
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
