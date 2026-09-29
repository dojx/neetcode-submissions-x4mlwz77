class Solution {
    unordered_map<char, string> numToChar = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) helper(digits, "", 0);
        return res;
    }

    void helper(const string& digits, string curr, int i) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        for (int j = i; j < digits.size(); ++j) {
            for (char c : numToChar[digits[j]]) {
                helper(digits, curr + c, j + 1);
            }
        }
    }
};
