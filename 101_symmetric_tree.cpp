#include <bits/stdc++.h>
#include "package.h"
using namespace std;

class Solution{
    public:
        bool isSymmetric(TreeNode* root){
            if(!root)
                return true;
            return self.isSymmetric(root->left, root->right);
        }
        bool isSymmetric(TreeNode* p, TreeNode* q){
            if(p && q)
                return p->val == q->val && isSymmetric(p->left, q->right) &&
                    isSymmetric(p->right, q->left);
            return p == q;
        }
};
