class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(s, part, 0);
        return res;
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void dfs(string& s, vector<string>& part, int i) {
        if (i >= s.size()) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(s, part, j + 1);
                part.pop_back();
            }
        }
    }

};
