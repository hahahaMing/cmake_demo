#include"tools.hpp"

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1;i<n;++i){
            arr[i]^=arr[i-1];
        }
        int m = queries.size();
        vector<int> rst(m);
        for(int i=0;i<m;i++){
            rst[i] = queries[i][0]==0?arr[queries[i][1]]:arr[queries[i][1]]^arr[queries[i][0]-1];
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
