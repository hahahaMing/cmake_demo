//
// Created by ming on 2020/11/14.
//

#ifndef CMAKETEST_Q1122_RELATIVESORTARRAY_HPP
#define CMAKETEST_Q1122_RELATIVESORTARRAY_HPP

#endif //CMAKETEST_Q1122_RELATIVESORTARRAY_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::map<int,int> hash;
        for (int i = 0; i < arr2.size(); ++i) {
            hash[arr2[i]]=i;
        }
        std::sort(arr1.begin(),arr1.end(),[&](int a,int b){
            if(hash.find(a)!=hash.end()){
                if (hash.find(b)!=hash.end())return hash[a]<hash[b];
                else return true;
            }else{
                if (hash.find(b)!=hash.end())return false;
                else return a<b;
            }
        });
        return arr1;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> arr1,arr2;
        arr1 = {2,3,1,3,2,4,6,7,9,2,19,7} ;
        arr2 = {2,1,4,3,9,6};
        tools::printVectorInt(relativeSortArray(arr1,arr2));
        arr1 = {} ;
        arr2 = {2,1,4,3,9,6};
        tools::printVectorInt(relativeSortArray(arr1,arr2));


    }
};