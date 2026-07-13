/*
    [a, b, c]
    [1, a, ab]
    [bc, c, 1]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> prefix(s);
        vector<int> suffix(s);

        prefix[0] = 1;
        suffix[s - 1] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> res(s);
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = suffix[i] * prefix[i];
        }

        return res;
    }
};
