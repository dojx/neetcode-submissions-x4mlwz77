class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        charCount = [0] * 26
        for c in s:
            charCount[ord(c) - ord('a')] += 1

        for c in t:
            if charCount[ord(c) - ord('a')] == 0:
                return False
            charCount[ord(c) - ord('a')] -= 1

        return sum(charCount) == 0
