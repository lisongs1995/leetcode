class Solution {
private:
    int lower_bound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    
    int upper_bound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (nums[mid] <= target)  lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = lower_bound(nums, target);
        int right = upper_bound(nums, target);
        if (left == nums.size() || nums[left] != target) return {-1, -1};
        return {left, right - 1};
    }
};
