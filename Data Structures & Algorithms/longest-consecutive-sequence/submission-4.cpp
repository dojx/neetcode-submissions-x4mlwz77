class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for (const int& n : nums) {
            if (!numSet.count(n - 1)) {
                int length = 1;
                while (numSet.count(n + length)) {
                    length++;
                }
                res = max(res, length);
            }
        }

        return res;
    }
};
