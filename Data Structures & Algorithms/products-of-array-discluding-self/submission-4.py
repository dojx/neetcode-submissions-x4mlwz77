'''
    [1, a, ab, abc]
    [bcd, cd, d, 1]

    [bcd, acd, abd, abc]
'''

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        v1, v2 = [1] * len(nums), [1] * len(nums)

        for i in range(1, len(nums)):
            v1[i] = nums[i - 1] * v1[i - 1]
        for i in range(len(nums) - 2, -1, -1):
            v2[i] = nums[i + 1] * v2[i + 1]

        return [a * b for a, b in zip(v1, v2)]

