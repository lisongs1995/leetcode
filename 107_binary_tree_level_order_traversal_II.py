from package import TreeNode
from collections import deque
class Solution:
    def levelOrderBottom(self, root):
        if not root:
            return []
        q = deque([root])
        ans = []
        while q:
            level = []
            size = len(q)
            for _ in range(q):
                p = q.popleft()
                level.append(q.val)
                if p.left:
                    q.append(p.left)
                if p.right:
                    q.append(p.right)
            ans.append(level)
        ans.reverse()
        return ans
