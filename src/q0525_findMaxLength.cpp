#include"tools.hpp"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>ps(n+1,0);
        unordered_map<int,int> mp;
        mp[1] = -1;
        int rst = 0;
        for(int i=0;i<n;++i){
            ps[i+1] = ps[i]+nums[i]; 
            int tmp = 2*ps[i+1]-i;
            if(mp.find(tmp)!=mp.end()){
                rst = max(rst,i-mp[tmp]);
            }else{
                mp[tmp] = i;
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
