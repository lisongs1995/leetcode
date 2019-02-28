class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int ans = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (maxLeft < height[right]) maxLeft = height[left];
                else {
                    ans += maxLeft - height[left];
                    left++;
                }
            }
            else {
                if (maxRight < height[right]) maxRight = height[right];
                else {
                    ans += maxRight - height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};
