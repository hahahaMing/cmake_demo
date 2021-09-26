#include"tools.hpp"

class Solution {
public:
    int trap(std::vector<int> &height) {
        int rst = 0, n = height.size();
        int left = 0, right = n - 1;//当前的左右指针位置
        int wl = 0, wr = 0;//左右墙的高度
//        只有较矮的墙可以向内移动
        while (left <= right) {
            if (wl<wr){
                //左墙向内移动
                if(height[left]<=wl){
                    rst+=wl-height[left++];
                }else{
                    wl = height[left++];
                }
            }else{
                if (height[right]<=wr){
                    rst+=wr-height[right--];
                }else {
                    wr = height[right--];
                }
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> height;
        height = {0,1,0,2,1,0,1,3,2,1,2,1};
        std::cout << trap(height) << std::endl;
    }
};