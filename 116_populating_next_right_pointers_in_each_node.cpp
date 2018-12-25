#include <bits/stdc++.h>
#include "package.h"
using namespace std;
struct TreeLinkNode{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x):
        val(x),
        left(nullptr),
        right(nullptr),
        next(nullptr) {}
};
static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
};
class Solution{
public:
    static void connect(TreeLinkNode* root){
        if(!root)
            return;
        TreeLinkNode* last = root;
        while(last){
            while(!last->left && !last->right){
                last = last->next;
                if(!last)
                    return;
            }
            if(!last->left)
                last = last->right;
            if(!last->right)
                last = last->left;
            TreeLinkNode* runner = last;
            while(runner){
                runner->left->next = runner->right;
                if(runner->next)
                    runner->right->next = runner->next->left;
                runner = runner->next;
            }
        
            last = last->left;
        }
    }
    static void recursive(TreeLinkNode* root){
        if(!root)
            return ;
        if(root->left){
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
        }
        recursive(root->left);
        recursive(root->right);
    }
};

int main(){
    TreeLinkNode* a = new TreeLinkNode(0);
    Solution::connect(a);

}
