#include <bits/stdc++.h>
#include "package.h"
using namespace std;
class Solution{
    public:
        bool isSameTree(TreeNode* p, TreeNode* q){
            if(!p && !q)
                return true;
            if(!p || !q)
                return false;
            if(p->val != q->val)
                return false;
            if(isSameTree(p->left, q->left) && (isSameTree(p->right, q->right))
                    return true;
            return false;
        }
};
