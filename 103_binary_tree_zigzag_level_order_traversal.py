from package import TreeNode
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root):
        if not root:
            return []
        q = deque([root])
        leftToRight = True
        while q:
            size = len(q)
            level = [0] * size
            for i in range(size):
                p = q.popleft()
                if leftToRight:
                    level[i] = p.val
                else:
                    level[size-1-i] = p.val
                if p.left:
                    q.append(p.left)
                if p.right:
                    q.append(p.right)
            leftToRight = not leftToRight
            ans.append(level)
        return ans


