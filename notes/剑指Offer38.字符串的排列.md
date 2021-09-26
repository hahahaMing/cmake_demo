# 剑指 Offer 38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

**示例:**

**输入：**s = "abc"
**输出：[**"abc","acb","bac","bca","cab","cba"**]**




**限制：**

`1 <= s 的长度 <= 8`

## 我的代码

```c++
class Solution {

  public:
    vector<string> permutation(string s) {
        len = s.size();
        rcd = vector<int>(26, 0);
        for (char c : s) {
            rcd[c - 'a']++;
        }
        rst = {};
        dfs("", -1);
        return rst;
    }

  private:
    vector<string> rst;
    vector<int> rcd;
    int len;
    void dfs(string ss, int noi) {
        if (ss.size() == len) {
            rst.push_back(ss);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (i == noi)
                continue;
            for (int j = 1; j <= rcd[i]; ++j) {
                rcd[i] -= j;
                string sss = ss;
                for (int k = 0; k < j; k++) {
                    sss += 'a' + i;
                }
                dfs(sss,i);
                rcd[i] += j;
            }
        }
    }
};
```
> 执行用时： 44 ms , 在所有 C++ 提交中击败了 74.48% 的用户
内存消耗： 19.8 MB , 在所有 C++ 提交中击败了 82.62% 的用户

## 题解

```c++
class Solution {
public:
    bool nextPermutation(string& s) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
        sort(s.begin(), s.end());
        do {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-hhvs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

## 标签
[0.典型题.md](0.典型题.md)
[剑指Offer38.字符串的排列.md](剑指Offer38.字符串的排列.md)

回溯

## 知识点
