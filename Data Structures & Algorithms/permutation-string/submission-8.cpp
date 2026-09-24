/*
    permutation: 2 substrings same length, same char frequency
    store char frequency for s1
    use sliding window on s2:
        keep track of char frequency each window
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freq1(26, 0), freq2(26, 0);

        for (const char& c : s1) {
            freq1[c - 'a']++;
        }

        int l = 0, r = 0;
        while (r < s1.size()) {
            freq2[s2[r] - 'a']++;
            r++;
        }

        if (freq1 == freq2) return true;

        while (r < s2.size()) {
            freq2[s2[r] - 'a']++;
            freq2[s2[l] - 'a']--;
            l++; r++;
            if (freq1 == freq2) return true;

        }

        return false;
    }
};
