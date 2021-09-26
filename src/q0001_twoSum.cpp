#include"tools.hpp"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(hash.find(nums[i])!=hash.end()){
                return {hash[nums[i]],i};
            }
            hash[target-nums[i]] = i;
        }
        return {0,1};
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    return 0;
}
