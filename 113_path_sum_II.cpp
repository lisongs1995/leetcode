#include "package.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreenNode* root, int sum){
        vector<int> path;
        vector<vector<int>> ans;
        dfs(root, sum, path, ans);
        return ans;
private:
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>> ans){
        if(!root)
            return;
        path.push_back(root->val);
        if(root->val == sum && !root->left && !root->right){
            ans.push_back(path);
            return;
        }
        dfs(root->left, sum-root->val, path, ans);
        dfs(root->right, sum-root->val, path, ans);
        path.pop_back();
    }
};
