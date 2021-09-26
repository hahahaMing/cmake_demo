#include"tools.hpp"

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> rcd;
        int last = 0,lastx = -1;
        for(int x:nums){
            last+=x;
            last%=k;
            if(x%k!=0&&(last==0||rcd.find(last)!=rcd.end()))return true;
            if(lastx!=-1&&(lastx+x)%k==0)return true;
            rcd.insert(last);
            lastx = x;
        }
        return false;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
