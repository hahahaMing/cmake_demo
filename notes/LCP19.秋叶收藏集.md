# [LCP 19. 秋叶收藏集](https://leetcode-cn.com/problems/UlBDOe/)

小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 `leaves`， 字符串 `leaves` 仅包含小写字符 `r` 和 `y`， 其中字符 `r` 表示一片红叶，字符 `y` 表示一片黄叶。
 出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。

**示例 1：**

> 输入：`leaves = "rrryyyrryyyrr"`
>
> 输出：`2`
>
> 解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"

**示例 2：**

> 输入：`leaves = "ryr"`
>
> 输出：`0`
>
> 解释：已符合要求，不需要额外操作

**提示：**

- `3 <= leaves.length <= 10^5`
- `leaves` 中只包含字符 `'r'` 和字符 `'y'`

```c++
class Solution {
public:
    int minimumOperations(std::string leaves) {
        /*
         * 动态规划
         * 存成为ryr,ry,r的形式所需最小步骤
         */
        int ryr=0,ry=0,r=0,i=3,len = leaves.size();
        r = leaves[0]=='r'?0:1;
        //初始化
        if (leaves[1]=='y'){
            ry = r++;
        }else{
            ry = r+1;
        }
        if (leaves[2]=='r'){
            ryr = ry;
            ry = std::min(ry+1,r+1);
        }else{//y
            ryr = ry+1;
            ry = std::min(ry,r);
            r++;
        }
        //开始迭代
        while (i<len){
            if (leaves[i]=='r'){
                ryr = std::min(ryr,ry);
                ry = std::min(ry+1,r+1);
            }else{////y
                ryr = std::min(ryr+1,ry+1);
                ry = std::min(ry,r);
                r++;
            }
            i++;
        }
        return ryr;
    }
};
```

> 执行用时：140 ms, 在所有 C++ 提交中击败了81.64% 的用户
>
> 内存消耗：12.8 MB, 在所有 C++ 提交中击败了98.89% 的用户

和题解动态规划一样，它后面有个推导，没心情看


