/*
 * @Author: your name
 * @Date: 2021-06-23 09:04:14
 * @LastEditTime: 2021-06-25 15:08:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\offer0015_hammingWeight.cpp
 */
/*
 * @Author: your name
 * @Date: 2021-06-23 09:04:14
 * @LastEditTime: 2021-06-23 09:08:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\offer0015_hammingWeight.cpp
 */
#include"tools.hpp"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rst = 0;
        while(n!=0){
            n = n&(n-1);
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    uint32_t n = 0b00000000000000000000000000001011;
    cout<<slt.hammingWeight(n)<<endl;
    
    return 0;
}
