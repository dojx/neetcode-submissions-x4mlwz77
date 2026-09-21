class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int charCount[26];

        for (int i = 0; i < s.size(); i++) {
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }

        for (int n : charCount) {
            if (n != 0) return false;
        }

        return true;   
    }
};
