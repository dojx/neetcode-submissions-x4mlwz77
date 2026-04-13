class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1 map, char count
        // pass through s first increment, then t decrement
        // O(n), O(n)
        if (s.length() != t.length()) return false;
        unordered_map<int, int> m;
        for (char c : s) {
            if (m.find(c) != m.end())
                m[c]++;
            else
                m[c] = 1;
        }

        for (char c : t) {
            if (m.find(c) == m.end())
                return false;
            if (m[c] == 0)
                return false;
            m[c]--;
        }

        return true;
    }
};
