#prama once
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    LinkNode* next;
    LinkNode(int x):
        val(x),
        next(nullptr)
    {};
};
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):
        val(x),
        left(nullptr),
        right(nullptr) {}
};
