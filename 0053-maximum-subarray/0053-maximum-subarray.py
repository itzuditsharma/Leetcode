class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = -1e9
        sum = 0

        for num in nums:
            sum += num

            if sum > maxsum:
                maxsum = sum

            if sum < 0:
                sum = 0
        
        return maxsum