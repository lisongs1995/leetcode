class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt = 1, x, y;
        ans.pus_back(matrix[x=0][y=0]);
        vis[x][y] = true;
        while (cnt < n * m) {
            while (y + 1 < m && !vis[x][y+1]) { vis[x][y+1] = true; ans.push_back(matrix[x][++y]); cnt++; }
            while (x + 1 < n && !vis[x+1][y]) { vis[x+1][y] = true; ans.push_back(matrix[x][++y]); cnt++; }
            while (y - 1 >= 0 && !vis[x][y-1]) { vis[x][y-1] = true; ans.push_back(matrix[x][--y]); cnt++; }
            while (x - 1 >= 0 && !vis[x-1][y]) {vis[x-1][y] = true; ans.push_back(matrix[x-1][y]); cnt++; }
        }
        return ans;
    }
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        //https://leetcode.com/problems/spiral-matrix/discuss/20719/0ms-Clear-C%2B%2B-Solution
        // best answer ever see
    }
};
