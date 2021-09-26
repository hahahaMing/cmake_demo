# [剑指 Offer 20. 表示数值的字符串](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

```c++
class Solution {
public:
    bool isNumber(std::string s) {
        bool e_lg = true, dot_lg = true, has_num = false;
        int ep=-2, st = 0, ed = s.length() - 1;
        for (int i = 0; i <= ed; ++i) {
            if (s[i] == ' ')st++;
            else break;
        }
        for (int i = ed; i >= 0; --i) {
            if (s[i] == ' ')ed--;
            else break;
        }
        for (int i = st; i <= ed; ++i) {
            if (!isdigit(s[i])) {
                if (s[i] == '+' || s[i] == '-') {
                    if ((i == st || i == ep + 1) && i != ed) {//开头e后正负号
                        continue;
                    } else return false;
                } else if (s[i] == '.') {
                    if (!dot_lg) return false;
                    dot_lg = false;
                } else if (s[i] == 'e' || s[i] == 'E') {
                    if (!e_lg || i == st || i ==ed ||!has_num || s[i + 1] == ' ')return false;
                    e_lg = false;
                    dot_lg = false;
                    ep = i;
                } else return false;
            } else has_num = true;
        }
        return has_num;
    }
};
```

> 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
>
> 内存消耗：6 MB, 在所有 C++ 提交中击败了93.22% 的用户

题解肯定状态机无疑，，，然而还是不会画

先列举状态

然后描述转移

再学习吧。。。。

![fig1](assets/jianzhi_20_fig1.png)
