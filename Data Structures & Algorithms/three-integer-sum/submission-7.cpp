class Solution {
public:
    vector<pair<int, int>> twoSum(int upperLimit, int target, const vector<int>& nums) {
        int a = 0, b = upperLimit - 1; 
        vector<pair<int, int>> res;

        while (a < b) {
            int sum = nums[a] + nums[b];

            if (sum == target) {
                res.push_back({a, b});
                a++; b--;
                while (a < b && nums[a] == nums[a - 1]) a++;
                while (a < b && nums[b] == nums[b + 1]) b--;
            } else if (sum < target) {
                a++;
                while (a < b && nums[a] == nums[a - 1]) a++;
            } else {
                b--;
                while (a < b && nums[b] == nums[b + 1]) b--;
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t numN = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = numN - 1; i >= 0; --i) {
            if (i < numN - 1 && nums[i] == nums[i + 1]) continue;
            int target = -nums[i];
            vector<pair<int, int>> twoSumRes = twoSum(i, target, nums);
            for (auto p : twoSumRes) {
                res.push_back({
                    nums[p.first], 
                    nums[p.second], 
                    nums[i]
                });
            }
        }

        return res;
    }
};
