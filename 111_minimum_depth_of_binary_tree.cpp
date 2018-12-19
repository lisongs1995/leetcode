#include <bits/stdc++.h>
#include "package.h"
class Solution{
public:
    int minDepth(TreeNode* root){
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* p = q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                if(!p->left && !p->right)
                    return depth;
            }
        }
        return -1;
    }
};
