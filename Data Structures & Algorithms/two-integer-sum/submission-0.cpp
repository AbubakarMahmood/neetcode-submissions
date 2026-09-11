#include<vector>
#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        seen.reserve(nums.size());

        for(int i = 0; i < nums.size(); ++i)
        {
            if(seen.contains(target - nums[i]))
            {
                return {seen[target - nums[i]], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};