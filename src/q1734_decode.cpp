#include"tools.hpp"

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size()+1;
        int x = 0;
        for(int i=0;i<n;++i)x^=i+1;
        for(int i=1;i<n-1;i+=2){
            x^=encoded[i];
        }
        vector<int> decoded(n);
        decoded[0] = x;
        for(int i=1;i<n;++i){
            decoded[i] = decoded[i-1]^encoded[i-1];
        }
        return decoded;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
