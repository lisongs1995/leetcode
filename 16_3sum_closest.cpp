static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(0); return 0;};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest=nums[0]+nums[1]+nums[2], curSum;
        for(int i=0; i<nums.size()-2; i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                curSum = nums[i]+nums[j]+nums[k];
                if(abs(target-curSum)<abs(target-closest)){
                    closest = nums[i] + nums[j] + nums[k];
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                }
                if(curSum > target)
                    k--;
                else if(curSum < target)
                    j++;
                else
                    return curSum; // 等于０的时候就是最小
                
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return closest;
    }
};
