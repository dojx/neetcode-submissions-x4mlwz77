class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        unordered_map<char, char> key = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        for (const char& c : s) {
            if (key.contains(c)) {
                stk.push(c);
            } else if (stk.empty() || c != key[stk.top()]) {
                return false;
            } else {
                stk.pop();
            }
        }

        return stk.empty();
    }
};
