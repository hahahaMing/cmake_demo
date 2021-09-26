/*
 * @Author: your name
 * @Date: 2021-09-16 11:04:15
 * @LastEditTime: 2021-09-16 14:34:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cmake_demo\src\q0212_findWords.cpp
 */
#include "tools.hpp"

using namespace std;

class Solution {

    struct TrieNode {
        string word;
        unordered_map<char, TrieNode *> children;
        TrieNode() { this->word = ""; }
    };

    void insertTrie(TrieNode *root, const string &word) {
        TrieNode *node = root;
        for (auto c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }
    vector<string> rst;
    bool find;
    void dfs(vector<vector<char>> &board, vector<vector<int>> &rcd, string str,
             int x, int y, int it) {
        if (!rst.empty() && rst.back() == str) {
            find = true;
            return;
        }
        if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size() ||
            board[y][x] != str[it] || rcd[y][x] == 1)
            return; //走出去、走过、不匹配
        if (it == str.size() - 1 && rcd[y][x] == 0 && str[it] == board[y][x]) {
            rst.push_back(str);
            find = true;
            return;
        }
        //走这一步
        it++;
        rcd[y][x] = 1;
        //继续
        dfs(board, rcd, str, x + 1, y, it);
        dfs(board, rcd, str, x - 1, y, it);
        dfs(board, rcd, str, x, y + 1, it);
        dfs(board, rcd, str, x, y - 1, it);
        // back
        rcd[y][x] = 0;
    }

  public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        rst = {};
        vector<vector<int>> rcd(board.size(), vector<int>(board[0].size(), 0));
        //建立字典树

        for (string s : words) {
            find = false;
            for (int y = 0; y < board.size(); y++) {
                if (find)
                    break;
                for (int x = 0; x < board[0].size(); x++) {
                    if (find)
                        break;
                    dfs(board, rcd, s, x, y, 0);
                }
                if (find)
                    break;
            }
        }
        return rst;
    }
};

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    Solution slt;
    vector<vector<char>> board;
    vector<string> words;
    board = tools::string2matrix(
        "[[\"o\",\"a\",\"a\",\"n\"],[\"e\",\"t\",\"a\",\"e\"],[\"i\",\"h\","
        "\"k\",\"r\"],[\"i\",\"f\",\"l\",\"v\"]]");
    words = tools::string2Vector("[\"oath\",\"pea\",\"eat\",\"rain\"]");
    slt.findWords(board, words);
    return 0;
}
