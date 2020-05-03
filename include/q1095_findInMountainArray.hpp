//
// Created by ming on 2020/4/29.
//

#ifndef CMAKETEST_Q1095_FINDINMOUNTAINARRAY_HPP
#define CMAKETEST_Q1095_FINDINMOUNTAINARRAY_HPP

#endif //CMAKETEST_Q1095_FINDINMOUNTAINARRAY_HPP

#include "tools.hpp"

class MountainArray {
private:
    std::vector<int> array;
public:
    MountainArray(std::vector<int> arr) {
        array = arr;
    }

    int get(int index) {
        return array[index];
    }

    int length() {
        return array.size();
    }
};


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //二分法 先找峰值位置，然后左半边二分，再右半边二分
        int L = 0, R = mountainArr.length()-1, P = (L + R) / 2,M;
        if (target<mountainArr.get(L)&&target<mountainArr.get(R)) return -1;
        int l, r, p,m;
        // 找峰值
        while (L<R){
            p = mountainArr.get(P);
            if (p>mountainArr.get(P-1)&&p>mountainArr.get(P+1))break;
            if (p>mountainArr.get(P-1)){
                L = P,P = (L + R) / 2;
            }else{
                R = P,P = (L + R) / 2;
            }
        }
        if (target>p)return -1;
        // 左边查找
        L = 0, R = P;M = (L+R)/2;
        while (L<R){
            l = mountainArr.get(L);
            if (target==l) return L;
            m = mountainArr.get(M);
            if (target==m) return M;
            r = mountainArr.get(R);
            if (target==r) return R;
            if (R-L==1)break;

            if (target>l&&target<m) R = M,M = (L+R)/2;
            else if(target>m&&target<r)L = M,M = (L+R)/2;
            else break;
        }
        // 右边查找
        L = P, R = mountainArr.length()-1;M = (L+R)/2;
        while (L<R){
            l = mountainArr.get(L);
            if (target==l) return L;
            m = mountainArr.get(M);
            if (target==m) return M;
            r = mountainArr.get(R);
            if (target==r) return R;
            if (R-L==1)return -1;

            if (target<l&&target>m) R = M,M = (L+R)/2;
            else if(target<m&&target>r)L = M,M = (L+R)/2;
            else return -1;
        }
        return -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> v;
        int t;


//        {
//            v = {1, 2, 3, 4, 5, 3, 1};
//            t = 3;
//            MountainArray m(v);
//            std::cout << findInMountainArray(t, m) << std::endl;
//        }

        {
            v = {0,1,2,4,2,1};
            t = 3;
            MountainArray m(v);
            std::cout << findInMountainArray(t, m) << std::endl;
        }


    }
};