class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[32] = {0};
        int idx;

        if (s.length() != t.length()) return false;

        for (char c : s) {
            idx = int(c - 'a');
            arr[idx]++;
        }

        for (char c : t) {
            idx = int(c - 'a');
            if (arr[idx] == 0)
                return false;
            arr[idx]--;
        }

        return true;
    }
};
