from package import TreeNode
from collections import deque
class Solution:
    def minDepth(self, root):
        if not root:
            return 0
        if not root.left:
            return self.minDepth(root.right) + 1
        if not root.right:
            return self.minDepth(root.left) + 1
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
    def BFS(self, root):
        if not root:
            return 0
        q = deque([root])
        depth = 0
        while q:
            size = len(q)
            depth += 1
            for _ in range(size):
                p = q.popleft()
                if  p.left:
                    q.append(p.left)
                if p.right:
                    q.append(p.right)
                if not p.left and not p.right:
                    return depth
        return -1
if __name__ == "__main__":
    s = Solution()
    a = TreeNode(1)
    a.right = TreeNode(2)
    print(s.minDepth(a))
