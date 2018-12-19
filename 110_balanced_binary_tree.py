from package import TreeNode
class Solution:
    def isBalanced(self, root):
        if not root:
            return True
        else:
            return abs(self.getDepth(root.left)-self.getDepth(root.right)) <= 1 \
                    and self.isBalanced(root.left) and self.isBalanced(root.right)

    def getDepth(self, root):
        if not root:
            return 0
        else:
            return max(self.getDepth(root.left), self.getDepth(root.right)) + 1

