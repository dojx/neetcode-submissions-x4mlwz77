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
        if (digits.empty()) return res;
        res = {""};

        for (char d : digits) {
            vector<string> tmp;
            for (string s : res) {
                for (char c : numToChar[d]) {
                    tmp.push_back(s + c);
                }
            }
            res = tmp;
        }

        return res;
    }
};
