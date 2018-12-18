#include <bits/stdc++.h>
#include "package.h"
class Solution{
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
            return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        }
        TreeNode* helper(vector<int>& preorder, int i, int j,
                vector<int>& inorder, int ii, int jj){
            if(i>=j && ii>=jj)
                return nullptr;
            TreeNode* root = new TreeNode(preorder[i]);
            auto iter = find(inorder.begin()+ii, inorder.end()+jj, preorder[ii]);
            int len=iter-inorder.begin()-ii;
            root->left=helper(preorder, i+1, i+1+len, inorder, ii, ii+len);
            root->right=helper(preorder, i+1+len, j, inorder, ii+len+1, jj);
            return root;
        }
};
