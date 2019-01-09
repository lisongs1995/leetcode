#include <algorithm>
static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(0); return 0;};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        //set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            // while(i<nums.size()-3 && nums[i] == nums[i+1]) i++;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k] == -nums[i]){
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                    //st.insert(tmp);
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k] > -nums[i])
                    k--;
                else
                    j++;
            }
            while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
        //for(auto it=st.begin(); it!=st.end(); it++)
        //    ans.push_back(*it);
        return ans;
        
    }
};
