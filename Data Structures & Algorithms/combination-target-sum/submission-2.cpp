class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(nums, subset, res, target, 0);
        return res;
    }

    void helper(const vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int target, int i) {
        if (i >= nums.size() || target < 0) return;
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(nums, subset, res, target - nums[i], i);
        subset.pop_back();
        helper(nums, subset, res, target, i + 1);
    }
};
