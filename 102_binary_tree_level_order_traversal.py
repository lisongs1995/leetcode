from package import TreeNode
class Solution:
    def levelOrder(self, root):
        if not root:
            return []
        ans = []
        q = [root]
        while q:
            nextQ = []
            level = []
            for ele in q:
                level.append(ele.val)
                if ele.left:
                    nextQ.append(ele.left)
                if ele.right:
                    nextQ.append(ele.right)
            q = nextQ
            ans.append(level)
        return ans
