/*
    a, ab, abc
    d, cd, bcd
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t s = nums.size();
        vector<int> prefix(s, 1), suffix(s, 1);

        for (int i = 1; i < s; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[i] = suffix[i - 1] * nums[s - i];
        }

        vector<int> res(s);
        for (int i = 0; i < s; i++) {
            res[i] = prefix[i] * suffix[s - i - 1];
        }

        return res;
    }
};
