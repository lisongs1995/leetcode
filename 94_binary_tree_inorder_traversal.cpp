#include <bits/stdc++> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};
class Solution {
private:
    vector<int> ans;
public:
    vector<int> inorder(TreeNode* root) {
        if (!root) return ans;
        stack<TreeNode* > sk;
        while (root || sk.empty()) {
            while (root) {
                sk.push(root);
                root = root->left;
            }
            if (!sk.empty()) {
                root = sk.top();
                ans.push_back(root->val);
                sk.pop();
            }
            root = root->right;
        }
    
    }
};
