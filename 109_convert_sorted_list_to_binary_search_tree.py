from package import ListNode, TreeNode

class Solution:
    def sortedListToBST(self, head):
        return self.helper(head, None)
    def helper(self, head, tail):
        if head is tail:
            return None
        fast = slow = head
        while fast is not tail and fast.next is not tail:
            fast = fast.next.next
            slow = slow.next
        mid = slow
        root = TreeNode(mid.val)
        root.left = self.helper(head, mid)
        root.right = self.helper(mid.next, None)
        return root

class Solution1:
    def sortedListToBST(self, head):
        if not head:
            return None
        size = 0
        runner = head
        while runner:
            size+=1
            runner = runner.next
        node = head
        def helper(start, end):
            nonlocal node
            if start >= end:
                return None
            mid = start + (end - start) // 2
            left = helper(start, mid)
            root = TreeNode(mid.val)
            node = node.next
            right = helper(mid+1, size)
            root.left = left
            root.right = right
            return root
        return helper(head, 0, size)
        
