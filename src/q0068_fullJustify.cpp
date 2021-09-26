/*
 * @Author: your name
 * @Date: 2021-09-09 09:52:24
 * @LastEditTime: 2021-09-09 15:22:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0068_fullJustify.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {

        int i = 0;
        vector<string> rst;
        while (i < words.size()) {
            int start = i;
            int totalWordLenth = 0;
            int wordCount = 0;
            while (i < words.size()) {
                if (totalWordLenth + wordCount + words[i].size() > maxWidth)
                    break;
                totalWordLenth += words[i].size();
                wordCount++;
                i++;
            }
            string str;
            for (int j = start; j < i; ++j) {
                str += words[j];
                int space;
                if (i == words.size()) {
                    if (j == i - 1) {
                        space = maxWidth - totalWordLenth - wordCount + 1;
                    } else {
                        space = 1;
                    }
                } else if (wordCount != 1) {
                    space =
                        (maxWidth - totalWordLenth) % (wordCount - 1) >
                                j - start
                            ? (maxWidth - totalWordLenth) / (wordCount - 1) + 1
                            : (maxWidth - totalWordLenth) / (wordCount - 1);
                } else {
                    space = maxWidth - totalWordLenth;
                }
                if (wordCount == 1 || j != i - 1 || i == words.size())
                    str += string(space, ' ');
            }
            rst.push_back(str);
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<string> input;
    input = {"This", "is", "an", "example", "of", "text", "justification."};
    input = {"What","must","be","acknowledgment","shall","be"};
    tools::printVectorString(slt.fullJustify(input, 16));

    return 0;
}
