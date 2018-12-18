#include <bits/stdc++.h>
#include "package.h"
class Solution{
    public:
        int maxDepth(TreeNode* root){
            if(!root)
                return 0;
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
        }
};
