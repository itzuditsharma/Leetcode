class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = -1e9
        sum = 0

        for i in range(len(nums)):
            sum += nums[i]

            maxsum = max(maxsum, sum)

            if sum < 0:
                sum = 0
        
        return maxsum