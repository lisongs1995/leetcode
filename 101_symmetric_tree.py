from package import TreeNode
class Solution:
    def isSymmetric(self, root):
        if root is None:
            return True
        return self.helper(root.left, root.right)
    def helper(self, p, q):
        if p and q:
            return p.val == q.val and self.helper(p.left, q.right) and self.helper(p.right, q.left)
        return p is q


