//
// Created by ming on 2020/5/8.
//

#ifndef CMAKETEST_Q0221_MAXIMALSQUARE_HPP
#define CMAKETEST_Q0221_MAXIMALSQUARE_HPP

#endif //CMAKETEST_Q0221_MAXIMALSQUARE_HPP
#include"tools.hpp"
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        //todo 太晚了，没做完。。
        //动态规划
        //以该点为左上角的最大正方形边长为 min（向上到0，向左到0，左上点的（以该点为右下角的最大正方形边长））
        // 所以遍历，记录，以该点为左上角的最大正方形边长，该点左到0，该点上到0
        if (matrix.empty())return 0;
        int raws = matrix.size(),cols = matrix[0].size();
        std::vector<std::vector<int> > max_l(raws, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> left=max_l,up=left;
        int longest;
        for (int y = 0; y <raws ; ++y) {
            for (int x = 0; x <cols ; ++x) {
                if (x==0&&y==0){
                    max_l[y][x] = matrix[y][x];
                }else if (x==0){
                    left[y][x]=0;
                }

                if (y==0){
                    up[y][x]=0;
                }

            }
        }


    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::string a;
//        a = "[\"1\",\"2\"]";
//        tools::printVectorString(tools::string2Vector(a));

        a = "[[\"1\",\"0\",\"1\",\"0\",\"0\"],[\"1\",\"0\",\"1\",\"1\",\"1\"],[\"1\",\"1\",\"1\",\"1\",\"1\"],[\"1\",\"0\",\"0\",\"1\",\"0\"]]";
        auto m = tools::string2matrix(a);
        tools::print_matrix(m);
        std::cout<<"test start"<<std::endl;





    }
};