/*
 * @Author: your name
 * @Date: 2021-06-14 09:13:07
 * @LastEditTime: 2021-06-14 09:13:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0374_guessNumber.cpp
 */
#include"tools.hpp"

using namespace std;

 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
        int l = 1,r = n;
        while(l<r){
            int m = l + (r-l)/2;
            int res = guess(m);
            if(res==1){
                l = m+1;
            }else if(res==-1){
                r = m-1;
            }else{
                return m;
            }
        }
        return l;
        
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
