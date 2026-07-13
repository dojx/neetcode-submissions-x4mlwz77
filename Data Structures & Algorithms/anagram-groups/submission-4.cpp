class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (string s : strs) {
            vector<int> cCount(26, 0);
            for (char c : s) {
                cCount[c - 'a']++;
            }

            string key = "";
            for (int n : cCount) {
                key += to_string(n);
                key += ',';
            }

            if (m.find(key) == m.end()) {
                m[key] = {s};
            } else {
                m[key].push_back(s);
            }
        }

        vector<vector<string>> res;
        for (const auto& [_, value] : m) {
            res.push_back(value);
        }

        return res;
    }
};