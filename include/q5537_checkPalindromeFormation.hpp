//
// Created by ming on 2020/10/11.
//

#ifndef CMAKETEST_Q5537_CHECKPALINDROMEFORMATION_HPP
#define CMAKETEST_Q5537_CHECKPALINDROMEFORMATION_HPP

#endif //CMAKETEST_Q5537_CHECKPALINDROMEFORMATION_HPP

#include"tools.hpp"

class Solution {
public:
    bool isp(std::string a) {
//        std::string ra=a;
//        std::reverse(ra.begin(), ra.end());
//        return ra==a;
        int n = a.size();
        for (int i = 0; i <= n / 2; ++i) {
            if (a[i] != a[n - i - 1])return false;
        }
        return true;
    }

//    bool checkPalindromeFormation(std::string a, std::string b) {
//        std::string al, ar, bl, br, na, nb, t1, t2, t3, t4;
//        if (isp(a) || isp(b))return true;
//        std::string ra = a, rb = b;
//        std::reverse(ra.begin(), ra.end());
//        std::reverse(rb.begin(), rb.end());
//
//
//        int n = a.size();
//
//        for (int i = 1; i < n; ++i) {//切割位置
//            /*al = a.substr(0, i);
//            ar = a.substr(i, n);
//            bl = b.substr(0, i);
//            br = b.substr(i, n);
//            na = al + br;
//            nb = bl + ar;
//            if (isp(na) || isp(nb)) {
//                std::cout << na << std::endl;
//                std::cout << nb << std::endl;
//                return true;
//            }*/
//            t1 = a;
//            t2 = rb;
//            t3 = b;
//            t4 = ra;
//            for (int j = 0; j < n; ++j) {
//                if (j>=i){
//                    t1 = b;t2
//                }
//            }
//
//        }
//        return false;
//    }
    bool checkPalindromeFormation(std::string a, std::string b) {
        int n = a.size();
        int as = n / 2 - 1, bs = n / 2 - 1;//中间回文开始位置
        while (as >= 0 && a[as] == a[n - as - 1]) {
            as--;
        }
        if (as == -1)return true;
        as++;
        while (bs >= 0 && b[bs] == b[n - bs - 1]) {
            bs--;
        }
        if (bs == -1)return true;
        bs++;


        std::string al, ar, bl, br;
        al = a.substr(0, as);
        ar = a.substr(n - as, as);
        bl = b.substr(0, bs);
        br = b.substr(n - bs, bs);

        std::string all, arr, bll, brr;
        all = b.substr(0, as);
        arr = b.substr(n - as, as);
        bll = a.substr(0, bs);
        brr = a.substr(n - bs, bs);

        std::reverse(al.begin(), al.end());
        std::reverse(ar.begin(), ar.end());
        std::reverse(bl.begin(), bl.end());
        std::reverse(br.begin(), br.end());

        return al == arr || bl == brr || ar == all || br == bll;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string a, b;
        a = "ulacfd";
        b = "jizalu";
//        std::cout << a.substr(0, 5) << std::endl;
        std::cout << checkPalindromeFormation(a, b) << std::endl;

    }
};