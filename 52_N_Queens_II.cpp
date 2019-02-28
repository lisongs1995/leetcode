class Solution {
    void generate(vector<vector<int>>& C, int row, int& cnt) {
        if (row == C.size()) {
            cnt++;
        }
        else {
            for (int i = 0; i < C.size(); i++) {
                int ok = 1;
                C[row] = i;
                for (int j = 0; j < row; j++) {
                    if (C[row] == C[i] || C[row] + row == C[i] + i || 
                            C[row] - row == C[i] - i) {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                    generate(C, row + 1, cnt);
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> C(n, 0);
        int cnt = 0;
        generate(C, 0, cnt);
        return cnt;
    }
};
