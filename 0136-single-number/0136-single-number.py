class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xor1 = 0
        for i in range(len(nums)):
            xor1 ^= nums[i]
        
        return xor1