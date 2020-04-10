//
// Created by ming on 2020/4/10.
//

#include "iostream"
#include "string"
#include "algorithm"

class Solution {
public:
    std::string reverseWords_1(std::string &s) {
        int head, lw;
        bool space = true, first = true;
        int l = s.length();
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                if (!space) { space = true; }
                s.erase(i, 1);
            } else {
                if (space) { head = i; }
                if (i + 1 == s.length() || s[i + 1] == ' ') {
                    lw = i - head + 1;
                    //todo 挪到最前
                    if (first) {
                        s = (s.substr(head, lw) + s).erase(head + lw, lw);
                        first = false;
                    } else {
                        s = (s.substr(head, lw) + " " + s).erase(head + lw + 1, lw);
                        i++;
                    }
                }
                space = false;
                i++;
            }
        }
        return s;
    }
    std::string reverseWords(std::string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end()); //需要include "algorithm"

        int n = s.size();
        int idx = 0;// 表示更新后的单词尾部，最后以此结尾删除多余空格
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];//s[idx++] = s[end++]是为了填之前多余的空格

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }

    void test() {
/*        std::string s, a;
        a = "asdfsa";
        s = "";
        std::cout << s << std::endl;
        s.assign(a);
        std::cout << s << std::endl;
        s.assign("a");
        std::cout << s << std::endl;*///string.assign() test ok!

        std::string str, rst;
        // test start ,change str
//        str.assign("the sky is blue");
//        std::cout << '\"' << str << '\"' << std::endl;
//        std::cout << '\"' << reverseWords(str) << '\"' << std::endl;


        str.assign("  a good   example   ");
        std::cout << '\"' << str << '\"' << std::endl;
        std::cout << '\"' << reverseWords(str) << '\"' << std::endl;


    }
};