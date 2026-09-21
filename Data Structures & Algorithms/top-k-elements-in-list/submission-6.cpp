class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        size_t maxFreq = nums.size();
        unordered_map<int, int> frequencies;
        vector<vector<int>> freqCount(maxFreq + 1);

        for (int n : nums) {
            frequencies[n]++;
        }

        for (auto [n, frequency] : frequencies) {
            freqCount[frequency].push_back(n);
        }

        vector<int> res;
        for (int i = maxFreq; i >= 0; i--) {
            for (int n : freqCount[i]) {
                res.push_back(n);
                k--;
                if (k == 0) return res;
            }
        }

        return res;
    }
};
