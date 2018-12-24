#include <bits/stdc++.h>
#include "package.h"
using namespace std;
class Solution {
    public:
        static bool hasPathSum(TreeNode* root, int sum){
            if(!root)
                return false;
            int tmp = sum - root->val;
            if(tmp == 0)
                return true;
            if(hasPathSum(root->left, tmp) || hasPathSum(root->right, tmp)){
                return true;
            }
        }

};
int main(){
    TreeNode a(0);
    TreeNode b(1);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    int sum = 999999999;
    if(Solution::hasPathSum(&a, sum))
        cout << "has path .." << endl;
    else
        cout << "No path found" << endl;

}
