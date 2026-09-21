class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            vector<int> charCount(26, 0);
            for (const char& c : s) {
                charCount[c - 'a']++;
            }
            string key = "";
            for (int n : charCount) {
                key += to_string(n);
                key += ",";
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [_, group] : groups) {
            res.push_back(group);
        }

        return res;
    }
};
