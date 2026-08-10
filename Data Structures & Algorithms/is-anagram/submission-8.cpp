class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charCount(26, 0);
        for (const char& c : s) {
            charCount[c - 'a']++;
        }
        for (const char& c : t) {
            if (charCount[c - 'a'] == 0) return false;
            charCount[c - 'a']--;
        }

        return accumulate(charCount.begin(), charCount.end(), 0) == 0;
    }
};
