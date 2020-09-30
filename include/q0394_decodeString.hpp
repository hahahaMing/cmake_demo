//
// Created by ming on 2020/5/28.
//

#ifndef CMAKETEST_Q0394_DECODESTRING_HPP
#define CMAKETEST_Q0394_DECODESTRING_HPP

#endif //CMAKETEST_Q0394_DECODESTRING_HPP
#include"tools.hpp"
class Solution {
    /*
     * 子功能
     * 1. 判断数字，把多位数字字符转换为int
     * 2. 判断括号有效并把括号内的字符串取出来
     * 3. 递归 看到数字和括号把括号内的东西返回出来×数字再返回。。。。
     *
     */

public:
    std::string decodeString(std::string s) {
        int i = 0,l ,r;
        int len = s.size();
        while (i<len){
            if (isdigit(s[i])){
                //从i开始继续遍历到[
                l=i;
                while (s[l]!='['){l++;}
                // 将数字字符串转为int
                int n = std::atoi(s.substr(i,l-i).c_str());
                int cover = 1;
                l++;//左括号位置
                r = l+1;
                while (cover!=0){
                    if (r=='[')cover++;
                    if (r==']')cover--;
                    r++;
                }//退出循环找到右括号
                //将中间的东西传入递归函数
                std::string front = s.substr(0,l),back = s.substr(r+1);
                std::string temp = s.substr(l+1,r-l-1);
                std::string temp_mul;
                temp = decodeString(temp);
                for (int j = 0; j <n ; ++j) {
                    temp
                }
                //将数字×之前结果的结果插入到s中
                int tmp_len = temp.size();
                s = front+temp+back;
                //更新i


            }
            i++;
        }
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};