//
// Created by ming on 2020/4/19.
//

#ifndef CMAKETEST_Q0466_GETMAXREPETITIONS_HPP
#define CMAKETEST_Q0466_GETMAXREPETITIONS_HPP

#endif //CMAKETEST_Q0466_GETMAXREPETITIONS_HPP

#include "tools.hpp"

class Solution {
public:
    int getMaxRepetitions(std::string s1, int n1, std::string s2, int n2) {
        std::map<int, int> next_index, pre_s1s;
        std::vector<int> s2s;
        int head,loop,rest,s2_in_head,s2_in_loop;
        // calculate loop
        int ptr1 = 0, ptr2 = 0,temp_head,count_s1=0,count_s2=0;
        int l1 = s1.size(), l2 = s2.size();
        while (1) {
            ptr2 = 0;
            temp_head = ptr1;
            while (ptr2 < l2) {
                if (s2[ptr2] == s1[ptr1]) {
                    ptr2++;
                }
                ptr1++;
                if (ptr1 == l1) {
                    ptr1 = 0;
                    // todo 记录s2s
                    if(ptr2==l2) s2s.push_back(count_s2+1);
                    else s2s.push_back(count_s2);
                    count_s1++;
                }
            }
            next_index[temp_head]=ptr1;
            count_s2++;
            // 记录pre_s1s
            pre_s1s[temp_head]=count_s1;//todo +1?
            if(next_index.find(ptr1)!=next_index.end()){
                //todo loop找到了
                head = pre_s1s[ptr1];
                loop = pre_s1s[temp_head]-pre_s1s[ptr1];
                s2_in_head = head>0?s2s[head-1]:0;
                s2_in_loop = s2s[loop+head-1];
                break;
            }
        }
        rest = (n1-head)%loop;
        int s2_in_S1=s2_in_head+s2_in_loop+s2s[head+rest-1];
        return s2_in_S1/n2;
        // matching
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s1;
        int n1;
        std::string s2;
        int n2;
//
//        s1 = "acb", n1 = 4;
//        s2 = "ab", n2 = 2;
//        std::cout << getMaxRepetitions(s1, n1, s2, n2) << std::endl;
//
//        s1 = "acb", n1 = 4;
//        s2 = "ab", n2 = 3;
//        std::cout << getMaxRepetitions(s1, n1, s2, n2) << std::endl;
//
//        s1 = "ac", n1 = 4;
//        s2 = "ab", n2 = 2;
//        std::cout << getMaxRepetitions(s1, n1, s2, n2) << std::endl;

//        s1 = "aaa", n1 = 3;
//        s2 = "aa", n2 = 1;
//        std::cout << getMaxRepetitions(s1, n1, s2, n2) << std::endl;

        s1 = "abba", n1 = 3;
        s2 = "baab", n2 = 1;
        std::cout << getMaxRepetitions(s1, n1, s2, n2) << std::endl;

    }
};