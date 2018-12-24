#include <bits/stdc++.h>
#include "package.h"

class Solution{
    public:
        static void flatten(TreeNode* root){
            if(!root)
                return ;
            TreeNode* prev = nullptr;
            TreeNode* runner = root->left;
            while(runner){
                prev = runner;
                while(runner->left && !runner->right){
                    runner = runner->left;
                    prev = runner;
                } // this while avoids left tree  such as 
                //             1
                //            /
                //           2
                //          /
                //         3
                runner = runner->right;
            }
            flatten(root->left);
            flatten(root->right);
            if(prev){
                prev->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
        }
        static void postOrderFlatten(TreeNode* root){
            if(!root)
                return;
            postOrderFlatten(root->right);
            postOrderFlatten(root->left);
            root->right = prev;
            root->left = nullptr;
            prev = root;
        }
    private:
        TreeNode* prev = nullptr;
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
    Solution::flatten(&a);
    TreeNode* runner = &a;
    while(runner){
        cout << runner->val << endl;
        runner = runner->right;
    }
}
