class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor_actual = 0
        xor_curr = 0

        for i in range(len(nums) + 1):
            if i < len(nums):
                xor_curr ^= nums[i]
            xor_actual ^= i
        
        return xor_curr ^ xor_actual
