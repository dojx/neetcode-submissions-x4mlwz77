class Solution {
    vector<vector<string>> res;
    vector<string> substrings;
public:
    vector<vector<string>> partition(string s) {
        helper(s, 0);
        return res;
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void helper(const string& s, int i) {
        if (i == s.size()) {
            res.push_back(substrings);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                substrings.push_back(s.substr(i, j - i + 1));
                helper(s, j + 1);
                substrings.pop_back();
            }
        }
        return;
    }
};
