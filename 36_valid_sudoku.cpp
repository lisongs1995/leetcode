class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis[10];
        //check each row is valid or not
        for (int i = 0; i < 9; i++) {
            memset(vis, 0, sizeof(int) * 10);
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int number = board[i][j] - '0';
                    if (!vis[number]) vis[number] = 1;
                    else 
                        return false;
                }
            }
        }
        //check each col is valid or not
        for (int i = 0; i < 9; i++) {
            memset(vis, 0, sizeof(int) * 10);
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[j][i])) {
                    int number = board[j][i] - '0';
                    if (!vis[number]) vis[number] = 1;
                    else
                        return false;
                }
            }
        }
        // check each sub-boxed is valid or not
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                // check boxes 
                memset(vis, 0, sizeof(int) * 10);
                for (int a = i; a < i + 3; a++) {
                    for (int b = j; b < j + 3; b++) {
                        if (isdigit(board[a][b])) {
                            int number = board[a][b] - '0';
                            if (!vis[number]) vis[number] = 1;
                            else
                                return false;
                        }
                    }
                }
                
            }
        }
        return true;
    }   
};
