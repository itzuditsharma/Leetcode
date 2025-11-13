class Solution:
    def helper(self, ind, prev, nums, dp):
        if ind == len(nums):
            return 0
        
        if dp[ind][prev + 1] != -1:
            return dp[ind][prev + 1]

        # not take case 
        len_ = self.helper(ind + 1, prev, nums, dp)

        # take case 
        if prev == -1 or nums[prev] < nums[ind]:
            len_ = max(len_, 1 + self.helper(ind + 1, ind, nums, dp))
        
        dp[ind][prev+1] = len_
        return dp[ind][prev+1]


    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        return self.helper(0, -1, nums, dp)