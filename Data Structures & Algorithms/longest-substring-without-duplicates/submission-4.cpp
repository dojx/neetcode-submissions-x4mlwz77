class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.size();
        if (n < 2) return n;

        int l = 0, r = 1;
        unordered_set<char> seen;
        seen.insert(s[l]);
        int maxLen = 1;

        while (r < n) {
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            r++;
            if (maxLen < seen.size()) {
                maxLen = seen.size();
            }
        }

        return maxLen;
    }
};
