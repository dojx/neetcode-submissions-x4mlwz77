class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        helper(candidates, res, subset, target, 0);
        return res;
    }

    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& subset, int target, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (i >= candidates.size() || target < 0) return;
        subset.push_back(candidates[i]);
        helper(candidates, res, subset, target - candidates[i], i + 1);
        subset.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) ++i;
        helper(candidates, res, subset, target, i + 1);
    }
};
