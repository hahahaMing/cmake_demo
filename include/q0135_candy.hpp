//
// Created by ming on 2020/12/24.
//

#ifndef CMAKETEST_Q0135_CANDY_HPP
#define CMAKETEST_Q0135_CANDY_HPP

#endif //CMAKETEST_Q0135_CANDY_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int candy(std::vector<int> &ratings) {
        int n = ratings.size();
        std::vector<int> rcd(n, 0), rst(n, 1);
        std::vector<bool> fixed(n, false);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i] > ratings[i - 1])rcd[i] = 1;//1表示我比前面的数大
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                if (rcd[i] == 1) {
                    rcd[i] = 3;//3表示我比前后都大
                } else rcd[i] = 2;//2表示我比后面的数大
            }
            if (rcd[i] == 0) {//0表示我不比前后大，只需1个糖果
                fixed[i] = true;
                // 向前找还没确定的数（rcd=2或3）把他定下来
                // 不需要改变fixed值，因为以后用不到
                int j = i - 1;
                while (j >= 0 && rcd[j] == 2) {
                    rst[j] = rst[j + 1] + 1;
//                    fixed[j] = true;
                    j--;
                }
                //只有向前找能找到rcd==3的情况
                if (j >= 0 && rcd[j] == 3) {
                    //这里既然rcd==3,j-1,j+1必在定义范围内。
                    rst[j] = std::max(rst[j - 1], rst[j + 1]) + 1;
//                    fixed[j] = true;
                }
            } else if (rcd[i] == 1 && fixed[i - 1]) {//向后确定值
                fixed[i] = true;
                rst[i] = rst[i - 1] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += rst[i];
        }
//        tools::printVectorInt(rst);
        return sum;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> rating;
        rating = {1, 2, 3, 2, 2, 3, 2, 1, 0, 1};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {1, 0, 2};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {1, 2, 2};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {1, 2, 3, 4, 5};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {5, 4, 3, 2, 1};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {1, 2, 3, 2, 1};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {1, 2, 3, 2, 2};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;
        rating = {41};
        tools::printVectorInt(rating);
        std::cout << candy(rating) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};