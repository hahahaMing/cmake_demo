#include"tools.hpp"

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int l1 = text1.size();
        std::vector<int> rcd;//存长度为i的公共子串在text1中最前结尾位置
        for (char c:text2) {
            //从后往前更新rcd
            int len = rcd.size();
            for (int i = rcd.empty() ? 0 : rcd.back() + 1; i < l1; ++i) {
                if (text1[i] == c) {
                    rcd.push_back(i);
                    break;
                }
            }
            for (int i = len - 1; i >= 0; --i) {
                for (int j = i > 0 ? rcd[i - 1] + 1 : 0; j < rcd[i]; ++j) {
                    if (text1[j] == c) {
                        rcd[i] = j;
                        break;
                    }
                }
            }
        }
        return rcd.size();
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string text1, text2;
        text1 = "abcba", text2 = "abcbcba";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;


        text1 = "bsbininm", text2 = "jmjkbkjkv";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;


        text1 = "oxcpqrsvwf", text2 = "shmtulqrypy";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;


        text1 = "abcde", text2 = "ace";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;
        text1 = "abc", text2 = "abc";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;
        text1 = "abc", text2 = "def";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;


        text1 = "abbbcddd", text2 = "adddcbbb";
        std::cout << longestCommonSubsequence(text1, text2) << std::endl;
    }
};