#include <bits/stdc++.h>
#include "package.h"
using namespace std;
class Solution{
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> level;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int currentLevel = 0;
        while(!q.empty()){
            int size = q.size();
            auto p = q.front();
            q.pop();
            if(p.second == currentLevel){
                level.push_back(p.first->val);
            }
            else{
                ans.push_back(level);
                level.clear();
                level.push_back(p.first->val);
                currentLevel = p.second;
            }
            if(p.first->left)
                q.push(make_pair(p.first->left, currentLevel+1));
            if(p.first->right)
                q.push(make_pair(p.first->right, currentLevel+1));
        }
        ans.push(level);
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> nextQ;
            vector<int> level;
            for(size_t i=0; i<size; i++){
                level.push_back(q[i]->val);
                if(q[i]->left)
                    nextQ.push_back(q[i]->left);
                if(q[i]->right)
                    nextQ.push_back(q[i]->right);
            }
            q = nextQ;
            ans.push_back(level);
        }
        return ans;
    }
};

