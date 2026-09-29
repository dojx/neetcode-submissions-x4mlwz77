/*
    decision tree:
        - add ( or add )
        - can add ( as long as countOpen < n
        - can add ) as long as countClose < countOpen
        - repeat until subset size is 2 * n, then add subset to res
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

    void backtrack(vector<string>& res, string subset, int openN, int closeN, const int& n) {
        if (subset.size() == n * 2) {
            res.push_back(subset);
            return;
        }
        if (openN < n) backtrack(res, subset + "(", openN + 1, closeN, n);
        if (closeN < openN) backtrack(res, subset + ")", openN, closeN + 1, n);
    }
};
