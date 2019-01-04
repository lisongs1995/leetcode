#include <bits/stdc++.h>
#include "package.h"

using namespace std;
struct TreeLinkNode{
    int val;
    TreeLinkNode* left, *right, *next;
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
        queue<TreeLinkNode* > q;
        q.push(root);
        TreeLinkNode tmp(0), *tail=&tmp;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeLinkNode* p = q.front();
                q.pop();
                tail->next = p;
                tail = p;
            
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            tmp.next = nullptr;
            tail = &tmp;
        }
    }
};

int main(){
    TreeLinkNode a(1), b(2), c(2);
    a.left = &b;
    a.right = &c;
    Solution::connect(&a);
    printf("%d\n", (a.next)->val);
    printf("%d\n", (b.next)->val);
    printf("%d\n", (c.next)->val);
}
