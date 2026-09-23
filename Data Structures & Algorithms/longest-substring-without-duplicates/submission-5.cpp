class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> lastSeen(256, -1); // ASCII range
        int l = 0, maxLen = 0;

        for (int r = 0; r < n; ++r) {
            unsigned char c = s[r];
            if (lastSeen[c] >= l) {
                l = lastSeen[c] + 1;
            }
            lastSeen[c] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};