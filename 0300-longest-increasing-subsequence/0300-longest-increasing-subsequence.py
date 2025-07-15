class Solution:
    def LIS(self, ind, prev_ind, nums, n, dp):
        if ind == n:
            return 0
        
        if dp[ind][prev_ind + 1] != -1:
            return dp[ind][prev_ind+1]

        # not_pick 
        len_ = 0 + self.LIS(ind+1, prev_ind, nums, n, dp)
        # pick 
        if prev_ind == -1 or nums[prev_ind] < nums[ind]:
            len_ = max(len_, 1 + self.LIS(ind+1, ind, nums, n, dp))
        
        dp[ind][prev_ind + 1] = len_
        return dp[ind][prev_ind + 1]

    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        return self.LIS(0, -1, nums, n, dp)
        