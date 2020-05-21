//
// Created by ming on 2020/5/21.
//

#ifndef CMAKETEST_Q0005_LONGESTPALINDROME_HPP
#define CMAKETEST_Q0005_LONGESTPALINDROME_HPP

#endif //CMAKETEST_Q0005_LONGESTPALINDROME_HPP

#include"tools.hpp"

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::cout << s << std::endl;
        //动态规划：
        // 1 添加分隔符
        std::string ss = "#";
        for (auto i:s) {
            ss += i;
            ss += "#";
        }
//        std::cout << ss << std::endl;
        // 2 动态规划辅助数组p
        int max_r=0, center=0;//当前向右扩展的最远边界，和最远边界的最长回文中心
        int len = ss.size();
        std::vector<int> p(len);
//        tools::printVectorInt(p);
        int l, r;
        int mirror;
        for (int j = 0; j < len; ++j) {
            if (j >= max_r) {
                //重心扩散法 扫描
                l = j - 1;
                r = j + 1;
                while (l >= 0 && r < len && ss[l] == ss[r]) {
                    l--;
                    r++;
                    p[j]++;
                }
                max_r = j+p[j];
                center = j;
            } else {
                //根据p数组 更新p数组
                mirror = 2*center-j;
                if (p[mirror]<max_r-j){
                    p[j] = p[mirror];
                } else if (p[mirror]==max_r-j){
                    p[j] = p[mirror];
                    l = j-p[mirror]-1;
                    r = j+p[mirror]+1;
                    while (l >= 0 && r < len && ss[l] == ss[r]) {
                        l--;
                        r++;
                        p[j]++;
                    }
                    max_r = j+p[j];
                    center = j;
                }else{
                    p[j] = max_r-j;
                }
            }
        }
//        tools::printVectorInt(p);
        auto ml = max_element(p.begin(), p.end());
        int step = *ml,location = (ml-p.begin()-step)>>1;

        return s.substr(location,step);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;

        s = "abababa";
        std::cout << longestPalindrome(s) << std::endl;
        s = "cbbb";
        std::cout << longestPalindrome(s) << std::endl;
        s = "";
        std::cout << longestPalindrome(s) << std::endl;
        s = "babad";
        std::cout << longestPalindrome(s) << std::endl;
        s = "cbbd";
        std::cout << longestPalindrome(s) << std::endl;


    }
};