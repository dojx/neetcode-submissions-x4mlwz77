/*
    store pairs as [count;value]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            if (count.find(num) != count.end()) {
                count[num]++;
            } else {
                count[num] = 1;
            }
        }

        unordered_map<int, vector<int>> groups;
        for (const auto& [key, value] : count) {
            if (groups.find(value) == groups.end()) {
                groups[value] = {key};
            } else {
                groups[value].push_back(key);
            }
        }

        vector<int> res;
        for (int i = nums.size(); i > 0; --i) {
            while (groups[i].size() && k > 0) {
                res.push_back(groups[i].back());
                groups[i].pop_back();
                k--;
            }
        }
        return res;
    }
};
