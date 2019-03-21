#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
};

class Solution {
private:
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (prev && prev->val >= root->val) return false;
        return isValidBST(root->right);
    }
};
