#include"tools.hpp"

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        //binary search
        int l = 1, r = n;
        while(l<r){
            int m = l+(r-l)/2;
            if(isBadVersion(m)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
