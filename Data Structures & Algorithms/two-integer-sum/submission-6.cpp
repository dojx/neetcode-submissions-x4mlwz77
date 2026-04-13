class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = target - nums[i];
            if (m.find(nums[i]) != m.end()) 
                return {m[nums[i]], i};
            m[temp] = i;
        }
        return {};
    }
};
