class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        unordered_map<char, char> brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (auto c : s) {
            if (brackets.contains(c)) {
                if (stk.empty() || stk.top() != brackets[c])
                    return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};
