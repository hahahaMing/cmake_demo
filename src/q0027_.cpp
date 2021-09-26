#include"tools.hpp"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                while(n-1>=0&&n-2>i&&nums[n-1]==val)n--;
                swap(nums[i],nums[n-1]);
            }
        }
        while(n-1>=0 && nums[n-1]==val)n--;
        return n;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    return 0;
}
