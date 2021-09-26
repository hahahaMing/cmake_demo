//
// Created by ming on 2020/11/30.
//

#ifndef CMAKETEST_Q0767_REORGANIZESTRING_HPP
#define CMAKETEST_Q0767_REORGANIZESTRING_HPP

#endif //CMAKETEST_Q0767_REORGANIZESTRING_HPP

#include"tools.hpp"

class Solution {
public:
    std::string reorganizeString(std::string S) {
        if (S.size() <= 1)return S;
        std::vector<std::pair<char, int>> statistics(26, std::make_pair('a', 0));
        for (char c:S) {
            statistics[c - 'a'].second++;
            statistics[c - 'a'].first = c;
        }
        typedef std::pair<char, int> pci;
        // 按出现次数排序
        std::sort(statistics.begin(), statistics.end(), [](pci a, pci b) { return a.second > b.second; });
        // 只有剩余字母数量总和不足以填补出现次数最多字母序列的空时会发生无法重构
        if (statistics[1].second == 0 || statistics[0].second * 2 - 1 > S.size())return "";
        std::vector<std::string> rcd;
        int len = statistics[0].second, cur = 0;
        // 按出现次数最多的次数为长度建立vector<string>然后蛇形填入排序后的字母
        while (true) {
            std::string tmp_s;
            for (int i = 0; i < len; ++i) {
                if (cur > 25 || statistics[cur].second == 0)tmp_s.push_back(0);
                else {
                    tmp_s.push_back(statistics[cur].first);
                    statistics[cur].second--;
                    if (statistics[cur].second == 0)cur++;
                }

            }
            rcd.push_back(tmp_s);
            if (cur > 25 || statistics[cur].second == 0)break;
        }
        std::string rst;
        int vlen = rcd.size();
        //从rcd中的每个string逐个填入rst，答案相同字母必然被隔开
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < vlen; ++j) {
                if (rcd[j][i])rst.push_back(rcd[j][i]);
            }
        }

        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "abbabbaaab";
        std::cout << reorganizeString(s) << std::endl;
        s = "ogccckcwmbmxtsbmozli";
        std::cout << reorganizeString(s) << std::endl;
        s = "aab";
        std::cout << reorganizeString(s) << std::endl;
        s = "aaab";
        std::cout << reorganizeString(s) << std::endl;
    }
};