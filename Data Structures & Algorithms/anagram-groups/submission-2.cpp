class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        vector<vector<string>> ans;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            res[key].push_back(s);
        }
        for (auto const& [key, val] : res) {
            ans.push_back(val);
        }
        return ans;
    }
};
