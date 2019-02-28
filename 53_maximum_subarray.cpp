class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, 0) + nums[i];
            res = max(ans, res);
        }
        return res;
    }
};
