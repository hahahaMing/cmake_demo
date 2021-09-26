#include "tools.hpp"

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c;
        for (int i = 1; i <= n; ++i) {
            c = 0;
            if (s[i - 1] != '0') {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                c += a;
            }
            tie(a, b) = {b, c};
        }
        return c;
    }
};
// class Solution {
//   public:
//     int numDecodings(string s) {
//         if (s[0] == '0')
//             return 0;
//         int last = 1, cur = 1, n = s.size();
//         for (int i = 0; i < n; i++) {
//             int tmp = cur;
//             if (i > 0) {
//                 if (s[i] == '0') {
//                     if (s[i - 1] != '1' && s[i - 1] != '2')
//                         return 0;
//                     else
//                         cur = last;
//                 }
//                 else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
//                     cur += last;
//             }
//             last = tmp;
//         }
//         return cur;
//     }
// };

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution sl;
    vector<string> v;
    v = {"12", "11106", "226", "004", "10011", "230"};
    for(auto&s:v){
        cout<<sl.numDecodings(s)<<endl;
    }
    return 0;
}
