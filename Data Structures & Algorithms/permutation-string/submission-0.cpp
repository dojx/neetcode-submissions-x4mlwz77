#include <array>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> arr1 = {0};
        array<int, 26> arr2 = {0};
        for (char c : s1) {
            arr1[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            arr2[s2[i] - 'a']++;
        }
        if (arr1 == arr2) return true;

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {
            arr2[s2[l] - 'a']--;
            l++;
            arr2[s2[r] - 'a']++;
            if (arr1 == arr2) return true;
        }
        return false;
    }
};
