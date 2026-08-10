class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            if (count.find(nums[i]) != count.end()) {
                return {count[nums[i]], i};
            }
            count[target - nums[i]] = i;
        }
    }
};
