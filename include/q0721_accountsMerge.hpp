//
// Created by ming on 2021/1/18.
//

#ifndef CMAKETEST_Q0721_ACCOUNTSMERGE_HPP
#define CMAKETEST_Q0721_ACCOUNTSMERGE_HPP

#endif //CMAKETEST_Q0721_ACCOUNTSMERGE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */


class Solution {
    std::vector<int> root;

    int get_root(int x) {
        if (root[x] == x)return x;
        return root[x] = get_root(root[x]);
    }

    void merge(int a, int b) {
        root[get_root(b)] = get_root(a);
    }


public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts) {
        root = {};
        std::vector<std::string> names, emails;
        std::unordered_map<std::string, int> email_map;
        std::vector<std::vector<std::string>> rst;
        for (const auto &acc:accounts) {
            //遍历邮箱
            int n = acc.size();
            int last_email = -1, this_email = -1;
            for (int i = 1; i < n; ++i) {
                if (email_map.find(acc[i]) == email_map.end()) {
                    this_email = root.size();
                    email_map[acc[i]] = this_email;
                    root.push_back(this_email);
                    emails.push_back(acc[i]);
                    names.push_back(acc[0]);
                } else {
                    this_email = email_map[acc[i]];
                }
                if (last_email != -1)merge(last_email, this_email);
                last_email = this_email;
            }
        }
        std::unordered_map<int, std::vector<std::string>> rcd;
        int len = root.size();
        for (int i = 0; i < len; ++i) {
            rcd[get_root(i)].emplace_back(emails[i]);
        }
        for (auto &item:rcd) {
            rst.push_back({names[item.first]});
            std::sort(item.second.begin(), item.second.end());
            rst.back().insert(rst.back().end(), item.second.begin(), item.second.end());
        }
        tools::printVectorString(emails);
        tools::printVectorInt(root);
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<std::string>> acs;
        acs = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
               {"John", "johnsmith@mail.com", "john00@mail.com"},
               {"Mary", "mary@mail.com"},
               {"John", "johnnybravo@mail.com"}};
        tools::print2DvectorString(accountsMerge(acs));
        acs = {{"David", "David0@m.co", "David1@m.co"},
               {"David", "David3@m.co", "David4@m.co"},
               {"David", "David4@m.co", "David5@m.co"},
               {"David", "David2@m.co", "David3@m.co"},
               {"David", "David1@m.co", "David2@m.co"}};
        tools::print2DvectorString(accountsMerge(acs));
        acs = {{"David", "David0@m.co", "David4@m.co", "David3@m.co"},
               {"David", "David5@m.co", "David5@m.co", "David0@m.co"},
               {"David", "David1@m.co", "David4@m.co", "David0@m.co"},
               {"David", "David0@m.co", "David1@m.co", "David3@m.co"},
               {"David", "David4@m.co", "David1@m.co", "David3@m.co"}};
        tools::print2DvectorString(accountsMerge(acs));



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};