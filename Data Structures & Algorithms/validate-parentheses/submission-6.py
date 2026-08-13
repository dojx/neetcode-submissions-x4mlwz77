class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        key = {
            '(': ')',
            '[': ']',
            '{': '}'
        }

        for c in s:
            if c in key:
                stack.append(c)
            else:
                if len(stack) <= 0 or c != key[stack.pop()]:
                    return False
        
        return len(stack) == 0