#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int i, int j, string& word, int s, vector<vector<char>>& board) {
        if (s == word.size()) return true;
        if (board[i][j] != word[s]) return false;
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, -1};
        for (int k = 0; k < 4; k++) {
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            if (0 <= new_x && new_x < board.size() && 0 <= new_y && new_y < board[0].size())
                if (dfs(new_x, new_y, word, s + 1, board))
                    return true;
        }
        return false;
     }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                if(dfs(i, j, word, 0, board))
                    return true;
            }
        return false;
    }
};
int main() {
    vector<vector<char>> board= {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    bool ans = Solution().exist(board, "ABCCED");
    cout << ans << endl;
}
