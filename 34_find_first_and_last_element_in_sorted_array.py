class Solution:
    def lower_bound(nums, target):
        lo = 0, hi = len(nums)
        while lo < hi:
            mid = (lo + hi) >> 1
            if nums[mid] >= target: hi = mid
            else: lo = mid + 1
        return lo

    def upper_bound(nums, target):
        lo = 0, hi = len(nums)
        while lo < hi:
            mid = (lo + hi) >> 1
            if nums[mid] <= target: lo = mid + 1
            else hi = mid
        return lo

    def searchRange(nums, target):
        if len(nums) == 0: return [-1, -1]
        left = self.lower_bound(nums, target)
        right = self.upper_bound(nums, target)
        if left == len(nums) or nums[left] != target:
            return [-1, -1]
        return [left, right - 1]
