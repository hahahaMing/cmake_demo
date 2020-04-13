//
// Created by ming on 2020/4/3.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
//#include "q0151_reverseWords.hpp"
//#include "q0887_superEggDrop.hpp"
//#include "m1603_intersection.hpp"
#include "q0355_Twitter.hpp"
using namespace std;

int main() {
    std::cout << "hello cmake!" << std::endl;
    map<int, int> m1;
    map<int, int> m2;
    map<int, int> m3;
    map<int, int>::const_iterator it;

    m1.insert(make_pair(6, 11));
    m1.insert(make_pair(2, 12));
    m1.insert(make_pair(3, 13));

    m2.insert(make_pair(5, 15));
    m2.insert(make_pair(4, 14));
    m2.insert(make_pair(3, 13));

    m3[1]=7;


    merge(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m2, m2.begin()));
    merge(m3.begin(), m3.end(), m2.begin(), m2.end(), inserter(m2, m2.begin()));

    for (it = m2.begin(); it != m2.end(); ++it)
        cout << it->first << "=>" << it->second << endl;
//    Solution solution;
//    solution.test();
    return 0;
}