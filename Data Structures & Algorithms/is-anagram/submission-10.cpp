class Solution {
public:
    bool isAnagram(string s, string t) {
        int charCount[26];

        for (const char& c : s) {
            charCount[c - 'a']++;
        }

        for (const char& c : t) {
            if (charCount[c - 'a'] <= 0) {
                return false;
            }
            charCount[c - 'a']--;
        }

        for (int n : charCount) {
            if (n > 0) {
                return false;
            }
        }

        return true;
    }
};
