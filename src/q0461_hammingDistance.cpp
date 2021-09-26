/*
 * @Author: your name
 * @Date: 2021-05-27 14:26:37
 * @LastEditTime: 2021-05-27 14:26:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0461_hammingDistance.cpp
 */
#include"tools.hpp"

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int rst = 0;
        x^=y;
        while(x>0){
            if(x&1)rst++;
            x = x>>1;
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
