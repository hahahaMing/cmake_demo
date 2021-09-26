//
// Created by ming on 2021/1/6.
//

#ifndef CMAKETEST_Q0399_CALCEQUATION_HPP
#define CMAKETEST_Q0399_CALCEQUATION_HPP

#endif //CMAKETEST_Q0399_CALCEQUATION_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations, std::vector<double> &values,
                                     std::vector<std::vector<std::string>> &queries) {
        std::unordered_map<std::string, int> rcd;
        int count = 0;
        for (const auto &v:equations) {
            for (const auto &s:v) {
                if (rcd.find(s) == rcd.end()) {
                    rcd[s] = count;
                    count++;
                }
            }
        }
        std::vector<std::vector<double>> map(count, std::vector<double>(count, 0));
        int n = values.size();
        for (int i = 0; i < n; ++i) {
            int a = rcd[equations[i][0]], b = rcd[equations[i][1]];
            for (int j = 0; j < count; ++j) {
                if (map[j][a]) {
                    map[j][b] = map[j][a] * values[i];
                    map[b][j] = 1.0 / map[j][b];
                }
                if (map[b][j]) {
                    map[a][j] = values[i] * map[b][j];
                    map[j][a] = 1.0 / map[a][j];
                }
                for (int k = 0; k < count; ++k) {
                    if (map[j][a] && map[b][k]) {
                        map[j][k] = map[j][a] * map[b][k] * values[i];
                        map[k][j] = 1.0 / map[j][k];
                    }
                }
            }
            map[a][b] = values[i];
            map[b][a] = 1.0 / values[i];
        }
        for (int i = 0; i < count; ++i) {
            map[i][i] = 1;
        }
        std::vector<double> rst;
        for (const auto &v:queries) {
            if (rcd.find(v[0]) != rcd.end() && rcd.find(v[1]) != rcd.end()) {
                if (map[rcd[v[0]]][rcd[v[1]]]) rst.push_back(map[rcd[v[0]]][rcd[v[1]]]);
                else rst.push_back(-1);
            } else {
                rst.push_back(-1);
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};