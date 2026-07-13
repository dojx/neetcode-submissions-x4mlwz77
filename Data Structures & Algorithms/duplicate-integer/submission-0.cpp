class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums)
        {
            if (count.find(n) != count.end())
            {
                return true;
            }
            count[n] = 1;
        }
        return false;
    }
};