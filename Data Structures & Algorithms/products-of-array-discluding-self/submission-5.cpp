

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> v1(size, 1), v2(size, 1);

        for (int i = 1; i < size; i++) {
            v1[i] = v1[i - 1] * nums[i - 1];
        }

        for (int i = size - 2; i >= 0; i--) {
            v2[i] = v2[i + 1] * nums[i + 1];
        }

        vector<int> res;
        for (int i = 0; i < size; i++) {
            res.push_back(v1[i] * v2[i]);
        }

        return res;
    }
};
