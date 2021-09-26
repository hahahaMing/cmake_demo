#include"tools.hpp"

using namespace std;

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
            find = true;
            return;
        }
            board[y][x] != str[it] || rcd[y][x] == 1)
            return; //走出去、走过、不匹配
        if (it == str.size() - 1 && rcd[y][x] == 0 && str[it] == board[y][x]) {
            rst.push_back(str);
            return;
        }
        if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size() ||
    void dfs(vector<vector<char>> &board, vector<vector<int>> &rcd, string str,
             int x, int y, int it) {
        if(!rst.empty()&&rst.back()==str){
            find = true;
class Solution {
    vector<string> rst;
    bool find;

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    // Solution slt;
    
    return 0;
}
