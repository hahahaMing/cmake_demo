/*
 * @Author: your name
 * @Date: 2021-09-10 13:51:13
 * @LastEditTime: 2021-09-12 10:13:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q1894_chalkReplacer.cpp
 */
#include"tools.hpp"

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        for(int i =1;i<chalk.size();++i){
            chalk[i]+=chalk[i-1]; 
        }
        k%=chalk.back();
        int l = 0,r = chalk.size()-1;
        while(l<=r){
            int m = (r-l)/2+l;
            if(chalk[m]>k){
                r = m-1;
            }else if(chalk[m]==k){
                return m+1==chalk.size()?0:m+1;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<int> chalk;
    chalk = {5,1,5};
    cout<<slt.chalkReplacer(chalk,22);
    
    return 0;
}
