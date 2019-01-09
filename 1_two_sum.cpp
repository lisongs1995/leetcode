#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;  // hash best than rbtree
        for(size_t i=0; i<nums.size(); i++){
            int to_find = target - nums[i];
            //auto it = hash.find(to_find);  //拖慢速度
            if(hash.find(to_find)!=hash.end())
                return {hash[to_find], i};
            else
                hash[nums[i]] = i;
        }
    }
};
