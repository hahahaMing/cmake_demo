#include "iostream"
#include "vector"
#include "tools.hpp"

class Solution {
public:
    // 判断 (xk, yk) 是否在「线段」(x1, y1)~(x2, y2) 上
    // 这里的前提是 (xk, yk) 一定在「直线」(x1, y1)~(x2, y2) 上
    static bool inside(int x1, int y1, int x2, int y2, int xk, int yk) {
        // 若与 x 轴平行，只需要判断 x 的部分
        // 若与 y 轴平行，只需要判断 y 的部分
        // 若为普通线段，则都要判断
        return (x1 == x2 || (std::min(x1, x2) <= xk && xk <= std::max(x1, x2))) &&
               (y1 == y2 || (std::min(y1, y2) <= yk && yk <= std::max(y1, y2)));
    }

    static void update(std::vector<double> &ans, double xk, double yk) {
        // 将一个交点与当前 ans 中的结果进行比较
        // 若更优则替换
        if (ans.empty() || xk < ans[0] || (xk == ans[0] && yk < ans[1])) {
            std::vector<double> temp;
            temp.push_back(xk);
            temp.push_back(yk);
            ans = temp;
//            ans = {xk, yk};
        }
    }

    static std::vector<double>
    intersection(std::vector<int> &start1, std::vector<int> &end1, std::vector<int> &start2, std::vector<int> &end2) {
        int x1 = start1[0], y1 = start1[1];
        int x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1];
        int x4 = end2[0], y4 = end2[1];

        std::vector<double> ans;
        // 判断 (x1, y1)~(x2, y2) 和 (x3, y3)~(x4, y3) 是否平行
        if ((y4 - y3) * (x2 - x1) == (y2 - y1) * (x4 - x3)) {
            // 若平行，则判断 (x3, y3) 是否在「直线」(x1, y1)~(x2, y2) 上
            if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                // 判断 (x3, y3) 是否在「线段」(x1, y1)~(x2, y2) 上
                if (inside(x1, y1, x2, y2, x3, y3)) {
                    update(ans, (double) x3, (double) y3);
                }
                // 判断 (x4, y4) 是否在「线段」(x1, y1)~(x2, y2) 上
                if (inside(x1, y1, x2, y2, x4, y4)) {
                    update(ans, (double) x4, (double) y4);
                }
                // 判断 (x1, y1) 是否在「线段」(x3, y3)~(x4, y4) 上
                if (inside(x3, y3, x4, y4, x1, y1)) {
                    update(ans, (double) x1, (double) y1);
                }
                // 判断 (x2, y2) 是否在「线段」(x3, y3)~(x4, y4) 上
                if (inside(x3, y3, x4, y4, x2, y2)) {
                    update(ans, (double) x2, (double) y2);
                }
            }
            // 在平行时，其余的所有情况都不会有交点
        } else {
            // 联立方程得到 t1 和 t2 的值
            double t1 = (double) (x3 * (y4 - y3) + y1 * (x4 - x3) - y3 * (x4 - x3) - x1 * (y4 - y3)) /
                        ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
            double t2 = (double) (x1 * (y2 - y1) + y3 * (x2 - x1) - y1 * (x2 - x1) - x3 * (y2 - y1)) /
                        ((x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3));
            // 判断 t1 和 t2 是否均在 [0, 1] 之间
            if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0) {
                std::vector<double> temp;
                temp.push_back(x1 + t1 * (x2 - x1));
                temp.push_back(y1 + t1 * (y2 - y1));
                ans = temp;
//                ans = {x1 + t1 * (x2 - x1), y1 + t1 * (y2 - y1)};
            }
        }
        return ans;
    }


    static void test() {
        std::cout << "test start" << std::endl;
        int s1[2] = {0, 0};
        int e1[2] = {4, 2};
        int s2[2] = {-2, -1};
        int e2[2] = {2, 1};
        std::vector<int> st1(tools::array2vector(s1));
        std::vector<int> ed1(tools::array2vector(e1));
        std::vector<int> st2(tools::array2vector(s2));
        std::vector<int> ed2(tools::array2vector(e2));
        std::vector<double> rst(intersection(st1,ed1,st2,ed2));
        tools::printVector(rst);


    }
};