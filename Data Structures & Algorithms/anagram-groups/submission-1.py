class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = dict()
        for s in strs:
            arr = [0] * 26
            for c in s:
                idx = ord(c) - ord('a')
                arr[idx] = arr[idx] + 1
            t = tuple(arr)
            if t in m:
                m[t].append(s)
            else:
                m[t] = [s]
        return list(m.values())
