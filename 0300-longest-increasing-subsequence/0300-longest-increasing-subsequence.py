class Solution:
    def helper(self, ind, prev, nums, dp):
        if ind == len(nums):
            return 0
        
        if dp[ind][prev + 1] != -1:
            return dp[ind][prev + 1]

        # not take case 
        not_take = self.helper(ind + 1, prev, nums, dp)

        # take case 
        take = 0
        if prev == -1 or nums[prev] < nums[ind]:
            take = 1 + self.helper(ind + 1, ind, nums, dp)
        
        dp[ind][prev+1] = max(take, not_take)
        return dp[ind][prev+1]


    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        return self.helper(0, -1, nums, dp)