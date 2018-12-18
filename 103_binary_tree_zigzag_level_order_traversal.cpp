#include <bits/stdc++.h>
#include "package.h"
using namespace std;
class Solution{
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root){
            if(!root)
                return {};
            vector<vector<int>> ans;
            vector<TreeNode*> q;
            q.push(root);
            bool leftToRight=true;
            while(!q.empty()){
                int size = q.size();
                vector<TreeNode*> nextQ;
                vector<int> level(size, 0);
                for(size_t i=0; i<size; i++){
                    if(leftToRight)
                        level[size-1-i] = q[i]->val;
                    if(q[i]->left)
                        nextQ.push_back(q[i]->left);
                    if(q[i]->right)
                        nextQ.push_back(q[i]->right);
                }
                leftToRight = !leftToRight;
                ans.push_back(level);
                q = nextQ;
            }
            return ans;
        }
        vector<vector<int>> zigzagLevelOrderStd(TreeNode* root){
            if(!root)
                return {};
            queue<TreeNode*> q;
            vector<vector<int>> ans;
            bool leftToRight = true;
            while(!q.empty()){
                int size = q.size();
                vector<int> level(size, -1);
                for(size_t i=0; i<size; i++){
                    auto p = q.front();
                    q.pop();
                    if(leftToRight)
                        level[i] = p->val;
                    else
                        level[size-1-i] = p->val;
                    if(p->left)
                        q.push_back(p->left);
                    if(p->right)
                        q.push_back(p->right);
                }
                ans.push_back(level);
                leftToRight=!leftToRight;
            }
            return ans;
        ｝
};
