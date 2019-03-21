class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
private:
    void dfs(int s, int k, int n) {
        if (nums.size() == k) res.push_back(nums), return;
        if (s == n + 1) return ;
        else {
            for (int i = s; i <= n; i++) {
                nums.push_back(i);
                dfs(s + 1, k, n);
                nums.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 0) return res;
        dfs(1, k, n);
        return res;
    }

};
