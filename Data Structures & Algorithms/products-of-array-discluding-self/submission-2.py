class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # a, b, c, d
        # 1, a, ab, abc
        # 1, c, bc, bcd

        prefix = [1]
        for i in range(len(nums) - 1):
            prefix.append(nums[i] * prefix[i])

        suffix = [1]
        for i in range(len(nums) - 1, 0, -1):
            suffix.append(nums[i] * suffix[len(nums) - i - 1])

        res = []
        for i in range(len(prefix)):
            res.append(prefix[i] * suffix[len(nums) - i - 1])

        return res


        
        