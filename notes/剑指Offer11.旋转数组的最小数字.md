# [剑指 Offer 11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 `[3,4,5,1,2]` 为 `[1,2,3,4,5]` 的一个旋转，该数组的最小值为1。 

**示例 1：**

```
输入：[3,4,5,1,2]
输出：1
```

**示例 2：**

```
输入：[2,2,2,0,1]
输出：0
```

注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

```c++
class Solution {
public:
    int minArray(std::vector<int> &numbers) {
        int l = 0, r = numbers.size() - 1, m = (l + r) / 2;
        int L, R, M;
        while (l < m) {
            R = numbers[r], L = numbers[l], M = numbers[m];
            if (L == R & L == M) {
                l++;
                m = (l + r) / 2;
            } else if (R <= L && L <= M) {
                l = m;
                m = (l + r) / 2;
            } else if (M <= R && R <= L) {
                r = m;
                m = (l + r) / 2;
            } else if (L <= M && M <= R) {
                return L;
            }
        }
        return std::min(numbers[l], numbers[r]);
    }
};
```

> 执行用时：8 ms, 在所有 C++ 提交中击败了94.13% 的用户
>
> 内存消耗：12.2 MB, 在所有 C++ 提交中击败了100.00% 的用户

题解思路一样，我这个还是有逻辑重复，顺便学到了以后写二分写`low+(high-low)/2`代替`(high+low)/2`防止整形溢出。
