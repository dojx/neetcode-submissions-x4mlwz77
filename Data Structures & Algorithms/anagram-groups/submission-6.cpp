class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            vector<int> key(26, 0);

            for (const char& c : s) {
                key[c - 'a']++;
            }

            string actualKey = "";
            for (const int& k : key) {
                actualKey += to_string(k) + ',';
            }

            if (groups.find(actualKey) == groups.end()) {
                groups[actualKey] = {s};
            } else {
                groups[actualKey].push_back(s);
            }
        }

        vector<vector<string>> res;
        for (const auto& [_, value] : groups) {
            res.push_back(value);
        }

        return res;
    }
};
