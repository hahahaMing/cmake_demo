# 剑指 Offer 15. 二进制中1的个数
请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

 

**示例 1：**

**输入：**00000000000000000000000000001011
**输出：**3
**解释：**输入的二进制串 `**00000000000000000000000000001011** 中，共有三位为 '1'。`


**示例 2：**

**输入：**00000000000000000000000010000000
**输出：**1
**解释：**输入的二进制串 **00000000000000000000000010000000** 中，共有一位为 '1'。


**示例 3：**

**输入：**11111111111111111111111111111101
**输出：**31
**解释：**输入的二进制串 **11111111111111111111111111111101** 中，共有 31 位为 '1'。

 

**提示：**


- 输入必须是长度为 `32` 的 **二进制串** 。




注意：本题与主站 191 题相同：<a href="https://leetcode-cn.com/problems/number-of-1-bits/">https://leetcode-cn.com/problems/number-of-1-bits/</a>

## 我的代码

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rst = 0;
        while(n!=0){
            n = n&(n-1);
            rst++;
        }
        return rst;
    }
};
```
> 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
>
> 内存消耗：5.9 MB, 在所有 C++ 提交中击败了22.99%的用户

## 题解

一样

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/er-jin-zhi-zhong-1de-ge-shu-by-leetcode-50bb1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

## 标签
[0.典型题.md](0.典型题.md)
[剑指Offer15.二进制中1的个数.md](剑指Offer15.二进制中1的个数.md)

位运算

## 知识点
